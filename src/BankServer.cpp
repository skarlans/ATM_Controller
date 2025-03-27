#include "BankServer.h"

BankServer::BankServer() {}

bool BankServer::addCustomer(int CardNumber, int pin, const string& AccountName, int initBalance){

    if (database.find(CardNumber) != database.end())
        return false;

    CustomerData newData;
    newData.pin = pin;
    Account Account(AccountName, initBalance);
    newData.accounts.push_back(Account);
    database[CardNumber] = newData;

    return true;

}

bool BankServer::addAccount(int CardNumber, const string& AccountName, int initBalance){
    if(database.find(CardNumber) == database.end())
        return false;
    
    Account Account(AccountName, initBalance);
    
    auto it = database.find(CardNumber);
    it->second.accounts.push_back(Account);

    return true;

}

bool BankServer::validatePIN(int CardNumber, int pin){
    if(database.find(CardNumber) == database.end())
        return false;

    auto it = database.find(CardNumber);
    int pin_database = it->second.pin;
    if(pin_database == pin)
        return true;
    else
        return false;
}

bool BankServer::validateAccountName(int CardNumber, const string& AccountName){
    if(database.find(CardNumber) == database.end())
        return false;

    auto it = database.find(CardNumber);
    vector<Account> AccountList = it->second.accounts;
    for(const auto &Acc: AccountList){
        if(Acc.getAccountName()== AccountName)
            return true;

    }

    return false;
}

int BankServer::getBalance(int CardNumber, const string& AccountName) const {

    if(database.find(CardNumber) == database.end())
        return -1;
    
    for(const auto &acc: database.find(CardNumber)->second.accounts){
        if(acc.getAccountName() == AccountName)    
            return acc.getAccountBalance();
    }

    return -1;
    
}


bool BankServer::deposit(int CardNumber, const string& AccountName, int amount){

    if(database.find(CardNumber) == database.end())
        return false;
    
    for(auto& account: database.find(CardNumber)->second.accounts){
        if(account.getAccountName() == AccountName){
            account.deposit(amount);
            return true;
        }
    }

    return false;
    
}

bool BankServer::withdraw(int CardNumber, const string& AccountName, int amount){

    if(database.find(CardNumber) == database.end())
        return false;
    
    for(auto& account: database.find(CardNumber)->second.accounts){
        if(account.getAccountName() == AccountName)    
            return account.withdraw(amount);
    }

    return false;
    
}
