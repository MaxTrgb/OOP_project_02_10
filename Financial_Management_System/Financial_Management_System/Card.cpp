#include "Card.h"
#include <iostream>

Card::Card()
{
    cardName = "";
    cardBalance= 0.0;
    creditLimit = 0.0;
}

Card::Card(const string& cardName, double cardBalance, double creditLimit)  {
    this->cardName = cardName;
    this->cardBalance = cardBalance;
    this->creditLimit = creditLimit;
}

void Card::Deposit(double amount) {
    if (amount > 0) {
        cardBalance += amount;
        cout << "Deposited " << amount << " into " << cardName << " card." << endl;
    }
}

void Card::MakePurchase(double amount) {
    if (amount > 0 && amount <= cardBalance + creditLimit) {
        cardBalance -= amount;
        cout << "Made a purchase of " << amount << " using " << cardName << " card." << endl;
    }
    else {
        cout << "Purchase declined for " << cardName << " card due to insufficient balance/limit." << endl;
    }
}

double Card::CheckBalance() const {
    return cardBalance;
}

string Card::GetName() const {
    return cardName;
}
