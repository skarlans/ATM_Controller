#include <cassert>
#include <iostream>
#include "Account.h"

using namespace std;

void TestAccount(){

    cout << "Account Test Start" << endl;
    Account account("Test", 1000);

    assert(account.getAccountName() == "Test");
    assert(account.getAccountBalance() == 1000);

    assert(account.deposit(1000));
    assert(account.getAccountBalance() == 2000);
    
    assert(!account.deposit(-1000));
    assert(account.withdraw(500));

    assert(!account.withdraw(5000));
    assert(!account.withdraw(-1000));

    cout << "Account Test Ended" << endl;



}
