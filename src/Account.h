#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

using namespace std;

class Account{

private:
    string m_type;
    int m_balance;

public:
    
    // Constructor
    Account(const string& AccountName, int InitBalance);

    // getter for AccountName
    string getAccountName() const;

    // getter for AccountBalance
    int getAccountBalance() const;

    // Deposit, if amount is below 0, return false. Else, add amount to the balance && return true.
    bool deposit(int amount);

    // Withdraw, if amount is below 0, do nothing. Else, add amount to the balance.
    bool withdraw(int amount);
};
#endif