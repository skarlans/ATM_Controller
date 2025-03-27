#include "Account.h"

Account::Account(const string& AccountName, int InitBalance)
    : m_type(AccountName), m_balance(InitBalance) {}


string Account::getAccountName() const {
    return m_type;
}

int Account::getAccountBalance() const{
    return m_balance;
}

void Account::deposit(int amount){
    if (amount < 0)
        return;

    m_balance += amount;
}

bool Account::withdraw(int amount){
    if (amount < 0 || amount > m_balance)
        return false;

    m_balance -= amount;
    return true;
}