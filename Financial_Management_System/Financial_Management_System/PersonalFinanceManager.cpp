#include "PersonalFinanceManager.h"
#include <iostream>

void PersonalFinanceManager::AddWallet(const string& name) {

    for (const Wallet& wallet : wallets) {
        if (wallet.GetName() == name) {
            cout << "A wallet with the name " << name << " already exists." << endl;
            return;
        }
    }

    Wallet newWallet(name);
    wallets.push_back(newWallet);
    cout << "Added a new " << name << " wallet." << endl;
}

void PersonalFinanceManager::AddCard(const string& name, double limit) {

    for (const Card& card : cards) {
        if (card.GetName() == name) {
            cout << "A card with the name " << name << " already exists." << endl;
            return;
        }
    }

    Card newCard(name, 0, limit); 
    cards.push_back(newCard);
    cout << "Added a new " << name << " card with a credit limit of " << limit << "." << endl;
}

Wallet* PersonalFinanceManager::GetWallet(const string& name) {
    for (Wallet& wallet : wallets) {
        if (wallet.GetName() == name) {
            return &wallet;
        }
    }
    return nullptr; 
}

Card* PersonalFinanceManager::GetCard(const string& name) {
    for (Card& card : cards) {
        if (card.GetName() == name) {
            return &card;
        }
    }
    return nullptr; 
}

void PersonalFinanceManager::ShowWalletBalances() const {
    cout << "Wallet Balances:" << endl;
    for (const Wallet& wallet : wallets) {
        cout << wallet.GetName() << ": " << wallet.GetBalance() << endl;
    }
}
void PersonalFinanceManager::ShowAllBalances() const {

    cout << "Wallet Balances:" << endl;
    for (const Wallet& wallet : wallets) {
        cout << wallet.GetName() << ": " << wallet.GetBalance() << endl;
    }

    cout << "Card Balances:" << endl;
    for (const Card& card : cards) {
        cout << card.GetName() << ": " << card.CheckBalance() << endl;
    }
}
