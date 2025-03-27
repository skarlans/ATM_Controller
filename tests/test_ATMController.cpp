#include <cassert>
#include <iostream>
#include "ATMController.h"
#include "BankServer.h"
#include "Hardware.h"

using namespace std;

void TestATMController(){

    cout << "ATMController Test Start" << endl;
    BankServer bank;
    bank.addCustomer(1234, 2001, "TESTING", 5000);
    CardReader reader;
    ATMController ATM(bank, reader);

    cout << "Test ATMController::InsertCard" << endl;
    assert(ATM.InsertCard(1234));
    assert(!ATM.InsertCard(12434));

    cout << "Test ATMController::EnterPIN" << endl;
    assert(ATM.EnterPIN(2001));
    assert(!ATM.EnterPIN(1002));

    cout << "Test ATMController::EnterAccountName" << endl;
    assert(ATM.EnterAccountName("TESTING"));
    assert(!ATM.EnterAccountName("TestATM"));

    ATM.EnterPIN(2001);
    ATM.EnterAccountName("TESTING");
    cout << "Test ATMController::CheckBalance" << endl;
    assert(ATM.CheckBalance("TESTING") == 5000);
    assert(ATM.CheckBalance("TestATM") == -1);

    cout << "Test ATMController::deposit" << endl;
    assert(ATM.deposit("TESTING", 1000));
    assert(!ATM.deposit("TESTING", -1000));
    assert(!ATM.deposit("TestATM", 1000));

    cout << "Test ATMController::withdraw" << endl;
    assert(ATM.withdraw("TESTING", 1000));
    assert(!ATM.withdraw("TESTING", -1000));
    assert(!ATM.withdraw("TestATM", 1000));
    assert(!ATM.withdraw("TESTING", 50000));

    cout << "ATMController Test Ended" << endl;



}