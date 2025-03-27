#include "BankServer.h"

BankServer::BankServer() {}

bool BankServer::addCustomer(int CardNumber, int pin, const string& AccountName, int initBalance){

    if (isRegistered(CardNumber))
        return false;

    CustomerData newData;
    newData.pin = pin;
    Account Account(AccountName, initBalance);
    newData.accounts.push_back(Account);
    database[CardNumber] = newData;

    return true;

}

bool BankServer::addAccount(int CardNumber, const string& AccountName, int initBalance){
    if(!isRegistered(CardNumber))
        return false;
    
    Account Account(AccountName, initBalance);
    
    auto it = database.find(CardNumber);
    it->second.accounts.push_back(Account);

    return true;

}

bool BankServer::validatePIN(int CardNumber, int pin){
    if(!isRegistered(CardNumber))
        return false;

    auto it = database.find(CardNumber);
    int pin_database = it->second.pin;
    if(pin_database == pin)
        return true;
    else
        return false;
}

bool BankServer::validateAccountName(int CardNumber, const string& AccountName){
    if(!isRegistered(CardNumber))
        return false;

    auto it = database.find(CardNumber);
    vector<Account> AccountList = it->second.accounts;
    for(const auto &Acc: AccountList){
        if(Acc.getAccountName()== AccountName)
            return true;

    }

    return false;
}

int BankServer::getBalance(int CardNumber, const string& AccountName) {

    if(!isRegistered(CardNumber))
        return -1;
    
    for(const auto &acc: database.find(CardNumber)->second.accounts){
        if(acc.getAccountName() == AccountName)    
            return acc.getAccountBalance();
    }

    return -1;
    
}


bool BankServer::deposit(int CardNumber, const string& AccountName, int amount){

    if(!isRegistered(CardNumber))
        return false;
    
    for(auto& account: database.find(CardNumber)->second.accounts){
        if(account.getAccountName() == AccountName)
            return account.deposit(amount);;
    }

    return false;
    
}

bool BankServer::withdraw(int CardNumber, const string& AccountName, int amount){

    if(!isRegistered(CardNumber))
        return false;
    
    for(auto& account: database.find(CardNumber)->second.accounts){
        if(account.getAccountName() == AccountName)    
            return account.withdraw(amount);
    }

    return false;
    
}

bool BankServer::isRegistered(int CardNumber){
    return (database.find(CardNumber) == database.end()) ? false : true;
}
