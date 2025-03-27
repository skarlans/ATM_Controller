#include <iostream>

using namespace std;

extern void TestAccount();
extern void TestATMController();
extern void TestBankServer();
extern void TestHardware();

int main(){

    TestAccount();
    TestATMController();
    TestBankServer();
    TestHardware();

    cout << "All Test Finished!" << endl;

    return 0;
}