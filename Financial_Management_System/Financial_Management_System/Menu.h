    #pragma once

    #include <fstream>
    #include "PersonalFinanceManager.h"
    #include <vector>

    class Menu {
    private:
        PersonalFinanceManager manager;
        struct ExpenseRecord {
            string name;
            double amount;
            int category;
            int day;
            int month;
        };
        vector<ExpenseRecord> expenseRecords; 

    public:
        Menu(); 
        ~Menu();
        void Run();

    private:
        void DisplayMenu() const;
        void HandleChoice(int choice);
        void AddWallet();
        void AddCard();
        void MakeWithdrawal();
        void MakeDeposit();
        void CheckBalance();
        void ShowAll();
        void PrintRecords();
        void SaveRecordsToFile(const string& filename);
        void LoadRecordsFromFile(const string& filename);
    };
