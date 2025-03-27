#include <cassert>
#include <iostream>
#include "BankServer.h"

using namespace std;

void TestBankServer(){

    cout << "BankServer Test Start" << endl;
    BankServer bank;

    cout << "Test BankServer::addCustomer" << endl;
    assert(bank.addCustomer(1234, 2222, "Testing", 2000));
    assert(!bank.addCustomer(1234, 55423, "Testing2", 4000));

    cout << "Test BankServer::addAccount" << endl;
    assert(bank.addAccount(1234, "Testing_Another", 3000));
    assert(!bank.addAccount(4521, "Testing_New", 1000));

    cout << "Test BankServer::validatePIN" << endl;
    assert(bank.validatePIN(1234, 2222));
    assert(!bank.validatePIN(1234, 55423));
    assert(!bank.validatePIN(1234, 1234));
    assert(!bank.validatePIN(123, 2222));

    cout << "Test BankServer::validateAccountName" << endl;
    assert(bank.validateAccountName(1234, "Testing"));
    assert(!bank.validateAccountName(1234, "Testing3"));
    assert(!bank.validateAccountName(1234, "Testing2"));
    assert(!bank.validateAccountName(123, "Testing"));
    
    cout << "Test BankServer::getBalance" << endl;
    assert(bank.getBalance(1234, "Testing") == 2000);
    assert(bank.getBalance(1234, "Testing_Another") == 3000);
    assert(bank.getBalance(2222, "Testing") == -1);
    assert(bank.getBalance(1234, "Testing_New") == -1);

    cout << "Test BankServer::deposit" << endl;
    assert(bank.deposit(1234, "Testing", 1000));
    assert(!bank.deposit(1234, "Testing", -1000));
    assert(!bank.deposit(1234, "Testing_Deposit", 1000));
    assert(!bank.deposit(5555, "Testing_Another", 3000));

    cout << "Test BankServer::withdraw " << endl;
    assert(bank.withdraw(1234, "Testing", 1000));
    assert(!bank.withdraw(1234, "Testing", -1000));
    assert(!bank.withdraw(1234, "Testing", -100000));
    assert(!bank.withdraw(1234, "Testing_Withdraw", 1000));
    assert(!bank.withdraw(5555, "Testing_Another", 3000));
    


    cout << "BankServer Test Ended" << endl;



}
