#include "Menu.h"
#include <iostream>

using namespace std;
Menu::Menu() {
    LoadRecordsFromFile("expense_records.txt");
}

Menu::~Menu() {
    SaveRecordsToFile("expense_records.txt");
}

void Menu::Run() {
    while (true) {
        DisplayMenu();
        int choice;
        cin >> choice;
        HandleChoice(choice);
    }
}
void Menu::DisplayMenu() const {
    cout << "\nPersonal Finance Manager Menu:" << endl;
    cout << "1. Add Wallet" << endl;
    cout << "2. Add Card" << endl;
    cout << "3. Make a Withdrawal" << endl;
    cout << "4. Make a Deposit" << endl;
    cout << "5. Check Balance" << endl;
    cout << "6. Check all Balances" << endl;
    cout << "7. Print Records" << endl; 
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

void Menu::HandleChoice(int choice) {
    switch (choice) {
    case 1:
        AddWallet();
        break;
    case 2:
        AddCard();
        break;
    case 3:
        MakeWithdrawal();
        break;
    case 4:
        MakeDeposit();
        break;
    case 5:
        CheckBalance();
        break;
    case 6:
        ShowAll();
        break;
    case 7:
        PrintRecords(); 
        break;
    case 8:
        SaveRecordsToFile("expense_records.txt");
        exit(0);
    default:
        cout << "\nInvalid choice. Please try again." << endl;
        break;
    }
}

void Menu::AddWallet() {

    string walletName;
    cout << "\nEnter wallet name: ";
    cin >> walletName;

    manager.AddWallet(walletName);
}

void Menu::AddCard() {

    string cardName;
    double creditLimit;

    cout << "\nEnter card name: ";
    cin >> cardName;
    cout << "Enter credit limit: ";
    cin >> creditLimit;

    manager.AddCard(cardName, creditLimit);
}

void Menu::MakeWithdrawal() {
    string name;
    double amount;
    int category;
    int day;
    int month;

    cout << "\nEnter wallet/card name: ";
    cin >> name;

    Wallet* wallet = manager.GetWallet(name);
    Card* card = manager.GetCard(name);

    if (wallet || card) {

        cout << "Enter withdrawal amount: ";
        cin >> amount;

        do {
            cout << "Choose category:\n1. Food\n2. Rent" << endl;
            cout << "3. Online\n4. Other" << endl;
            cin >> category;

        } while (category != 1 && category != 2 && category != 3 && category != 4);

        cout << "Enter day: ";
        cin >> day;
        cout << "Enter month: ";
        cin >> month;

        if (wallet) {
            wallet->Withdraw(amount);
        }
        else {
            card->MakePurchase(amount);
        }

        ExpenseRecord record = { name, amount, category, day, month };
        expenseRecords.push_back(record); 
    }
    else {
        cout << "\nWallet/Card not found." << endl;
    }
}
void Menu::MakeDeposit() {
    string name;
    double amount;

    cout << "\nEnter wallet/card name: ";
    cin >> name;

    Wallet* wallet = manager.GetWallet(name);
    Card* card = manager.GetCard(name);

    if (wallet || card) {

        cout << "Enter deposit amount: ";
        cin >> amount;
        if (wallet)
            wallet->Deposit(amount);
        else
            card->Deposit(amount);
    }
    else {
        cout << "\nWallet/Card not found." << endl;
    }
}

void Menu::CheckBalance() {
    string name;
    cout << "\nEnter wallet/card name: ";
    cin >> name;
    Wallet* wallet = manager.GetWallet(name);
    Card* card = manager.GetCard(name);
    if (wallet || card) {
        double balance = wallet ? wallet->GetBalance() : card->CheckBalance();
        cout << "\nBalance for " << name << ": " << balance << endl;
    }
    else {
        cout << "\nWallet/Card not found." << endl;
    }
}
void Menu::ShowAll() {
    manager.ShowAllBalances();
}
void Menu::PrintRecords() {
    cout << "\nExpense Records:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Name\tAmount\tCategory\tDay\tMonth" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (const ExpenseRecord& record : expenseRecords) {
        cout << record.name << "\t" << record.amount << "\t";

        switch (record.category) {
        case 1:
            cout << "Food\t";
            break;
        case 2:
            cout << "Rent\t";
            break;
        case 3:
            cout << "Online\t";
            break;
        case 4:
            cout << "Other\t";
            break;
        default:
            cout << "Unknown\t";
            break;
        }

        cout <<"\t" << record.day << "\t" << record.month << endl;
    }

    cout << "--------------------------------------------------------------" << endl;
}
void Menu::SaveRecordsToFile(const string& filename) {
    ofstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (const ExpenseRecord& record : expenseRecords) {
        file << record.name << "\t" << record.amount << "\t" << record.category << "\t" << record.day << "\t" << record.month << endl;
    }

    if (file.fail()) {
        cerr << "Error: Failed to write data to the file." << endl;
    }
    else {
        cout << "Expense records saved to " << filename << endl;
    }

    file.close();
}

void Menu::LoadRecordsFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "File does not exist. No expense records loaded." << endl;
        return;
    }

    expenseRecords.clear(); 

    ExpenseRecord record;
    while (file >> record.name >> record.amount >> record.category >> record.day >> record.month) {
        expenseRecords.push_back(record);
    }

    file.close();
    cout << "Expense records loaded from " << filename << endl;
}