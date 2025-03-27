#include "ATMController.h"

ATMController::ATMController(BankServer& bank, CardReader& cardreader) : m_Bank(bank), m_Hardware(cardreader), m_bAuth(false), m_iCurrentCard(-1) {}

bool ATMController::InsertCard(int CardNumber) {

    bool res = m_Hardware.InsertCard(CardNumber);
    if(res){
        m_iCurrentCard = m_Hardware.getCardNumber();
        m_bAuth = true;
    }

    return res;
}

bool ATMController::EnterPIN(int pin){
    if(m_iCurrentCard == -1)
        return false;

    bool val = m_Bank.validatePIN(m_iCurrentCard, pin);
    m_bAuth = val;
    return m_bAuth;
}

bool ATMController::EnterAccountName(const string& AccountName){
    if(m_iCurrentCard == -1)
        return false;

    bool val = m_Bank.validateAccountName(m_iCurrentCard, AccountName);
    m_bAuth = val;
    return m_bAuth;
}

int ATMController::CheckBalance(const string& AccountName){
    if(m_bAuth == false || m_iCurrentCard == -1)
        return false;
    
    return m_Bank.getBalance(m_iCurrentCard, AccountName);
}

bool ATMController::deposit(const string& AccountName, int amount){
    if(m_bAuth == false || m_iCurrentCard == -1)
        return false;

    return m_Bank.deposit(m_iCurrentCard, AccountName, amount);
}

bool ATMController::withdraw(const string& AccountName, int amount){
    if(m_bAuth == false || m_iCurrentCard == -1)
        return false;
    
    return m_Bank.withdraw(m_iCurrentCard, AccountName, amount);
}

void ATMController::EjectCard(){

    m_Hardware.ejectCard();
    m_iCurrentCard = -1;
    m_bAuth = false;
}