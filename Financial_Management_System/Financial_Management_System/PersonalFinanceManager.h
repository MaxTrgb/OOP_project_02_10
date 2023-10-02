#pragma once
#include "Wallet.h"
#include "Card.h"
#include <vector>
using namespace std;

class PersonalFinanceManager {
private:
    vector<Wallet> wallets;
    vector<Card> cards;

public:
    void AddWallet(const string& name);
    void AddCard(const string& name, double limit);
    Wallet* GetWallet(const string& name);
    Card* GetCard(const string& name);
    void ShowWalletBalances() const;
    void ShowAllBalances() const;

};
