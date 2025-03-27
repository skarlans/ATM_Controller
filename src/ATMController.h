#ifndef ATMCONTROLLER_H
#define ATMCONTROLLER_H
#include <vector>
#include <string>
#include "Hardware.h"
#include "BankServer.h"

using namespace std;


class ATMController
{
private:
    BankServer& m_Bank;
    CardReader& m_Hardware;
    bool m_bAuth;    
    int m_iCurrentCard;
public:
    // Constructor
    ATMController(BankServer& bank, CardReader& reader);

    // InsertCard(ATMController -> CardReader), return true if success, false if not
    bool InsertCard(int CardNumber);

    // EnterPIN(ATMController -> BankServer), return true if success, false if not
    bool EnterPIN(int pin);

    // EnterAccountName(ATMController -> BankServer), return true if success, false if not
    bool EnterAccountName(const string& AccountName);

    // CheckBalance(ATMController -> BankServer), return (int)Balance if success, -1 if not
    int CheckBalance(const string& AccountName);

    // Deposit(ATMController -> BankServer), return true if success, false if not
    bool deposit(const string& AccountName, int amount);

    // Witdraw(ATMController -> BankServer), return true if success, false if not
    bool withdraw(const string& AccountName, int amount);

    // EjectCard(ATMController -> CardReader), eliminate the information of current card
    void EjectCard();
        
};

#endif