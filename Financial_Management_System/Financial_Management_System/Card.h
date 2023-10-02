#pragma once
#include <string>
using namespace std;

class Card {
private:
    string cardName;
    double cardBalance;
    double creditLimit;

public:
    Card();
    Card(const string& cardName, double cardBalance, double creditLimit);
    void Deposit(double amount);
    void MakePurchase(double amount);
    double CheckBalance() const;
    string GetName() const;

};
