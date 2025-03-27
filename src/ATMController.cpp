#include "ATMController.h"

ATMController::ATMController(BankServer& bank, CardReader& cardreader) : m_Bank(bank), m_Hardware(cardreader),
                            m_bAuth(false), m_iCurrentCard(-1), m_bValidAccountName(false), m_bValidPIN(false){}

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

    m_bValidPIN = m_Bank.validatePIN(m_iCurrentCard, pin);
    processAuth();

    return m_bValidPIN;
}

bool ATMController::EnterAccountName(const string& AccountName){
    if(m_iCurrentCard == -1)
        return false;

    m_bValidAccountName = m_Bank.validateAccountName(m_iCurrentCard, AccountName);
    processAuth();

    return m_bValidAccountName;
}

int ATMController::CheckBalance(const string& AccountName){
    if(!isAuth())
        return false;
    
    return m_Bank.getBalance(m_iCurrentCard, AccountName);
}

bool ATMController::deposit(const string& AccountName, int amount){
    if(!isAuth())
        return false;

    return m_Bank.deposit(m_iCurrentCard, AccountName, amount);
}

bool ATMController::withdraw(const string& AccountName, int amount){
    if(!isAuth())
        return false;
    
    return m_Bank.withdraw(m_iCurrentCard, AccountName, amount);
}

void ATMController::EjectCard(){

    m_Hardware.ejectCard();
    m_iCurrentCard = -1;
    m_bAuth = false;
    m_bValidAccountName = false;
    m_bValidPIN = false;
}

bool ATMController::isAuth(){
    return (m_bAuth == false || m_iCurrentCard == -1) ? false : true;
}

void ATMController::processAuth(){
    if(m_bValidPIN && m_bValidAccountName)
        m_bAuth = true;
    else
        m_bAuth = false;
}