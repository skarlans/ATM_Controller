#ifndef BANKSERVER_H
#define BANKSERVER_H

#include <string>
#include <vector>
#include <unordered_map>
#include "Account.h"

using namespace std;

struct CustomerData
{
    int pin;
    vector<Account> accounts;
};

class BankServer
{
private:
    unordered_map<int, CustomerData> database;

public:
    // Constructor
    BankServer();

    // addCustomer, if new, save (CardNumber, PIN, AccountName, Initial Balance) and return true
    // if not, return false
    bool addCustomer(int CardNumber, int pin, const string &AccountName, int initBalance);

    // addAccount, if exist, save (AccountName, Initial Balance) to the account(cardnumber) and return true
    // if not, return false
    bool addAccount(int CardNumber, const string &AccountName, int initBalance);

    // validatePIN, if exist, return true. if not, return false
    bool validatePIN(int CardNumber, int pin);

    // validateAccountName, if exist, return true. if not, return false
    bool validateAccountName(int CardNumber, const string& AccountName);

    // getBalance, if AccountName exist, return (int) balance. if not, return -1
    int getBalance(int CardNumber, const string &AccountName) const;

    // deposit, if AccountName exist, return true. if not, return false
    bool deposit(int CardNumber, const string &AccountName, int amount);

    // deposit, if AccountName exist and possible, return true. if not, return false
    bool withdraw(int CardNumber, const string &AccountName, int amount);
};

#endif