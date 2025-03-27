#include <iostream>
#include "Account.h"
#include "Hardware.h"
#include "BankServer.h"
#include "ATMController.h"

int main() {

    CardReader Hardware;
    BankServer Bank;
    ATMController ATM(Bank, Hardware);

    // Add TestData
    Bank.addCustomer(1001, 1234, "Checking", 500);
    Bank.addCustomer(1002, 4321, "Checking", 600);
    Bank.addAccount(1001, "Saving", 1000);

    
    // Simple Test Code
    while(true){

        // PUT CARD NUMBER
        cout << "INSERT CARD : " << endl;
        int card;
        cin >> card;
        if (card == 0) break;

        if(!ATM.InsertCard(card)){
            cout << "Failed" << endl;
            continue;
        }
        
        // PUT PIN NUMBER
        int pin;
        bool isLogin = false;
        cout << "INSERT PIN NUMBER : " << endl;
        cin >> pin;
        if(!ATM.EnterPIN(pin)){
            cout << "PIN REGISTERED FAILED! CARD EJECT!" << endl;
            ATM.EjectCard();
            continue;
        }

        // PUT ACCOUNTNAME
        string AccountName;
        cout << "INSERT ACCOUNTNAME : " << endl;
        cin >> AccountName;

        if(!ATM.EnterAccountName(AccountName)){
            cout << "ACCOUNT NAME NOT FOUND! CARD EJECT!" << endl;
            ATM.EjectCard();
            continue;
        }else {isLogin = true;} // Login!

        // Main Interface
        while(isLogin){
            int button;
            cout <<"1 : Check Balance / 2 : Deposit / 3 : WithDraw / 4 : Eject Card / 0 : Exit" << endl;
            cin >> button;

            // Check Balance
            if(button == 1){
                int balance = ATM.CheckBalance(AccountName);
                if(balance == -1)
                    cout << "No Account Type in this Card!" << endl;
                cout << AccountName << " BALANCE : " << balance << endl;
            }
            // DEPOSIT
            else if(button == 2){
                int money;
                cout << "DEPOSIT : How Much? : ";
                cin >> money;
                bool res = ATM.deposit(AccountName, money);
                if(res)
                    cout << "DEPOSIT SUCCESS!" << endl;
                else
                    cout << "DEPOSIT FAILED" << endl;
            }
            // WITHDRAW
            else if(button == 3){
                int money;
                cout << "WITHDRAW How Much? : ";
                cin >> money;
                bool res = ATM.withdraw(AccountName, money);
                if(res)
                    cout << "WITHDRAW SUCCESS!" << endl;
                else
                    cout << "WITHDRAW FAILED" << endl;
            }
            // EJECT CARD
            else if(button == 4){
                ATM.EjectCard();
                cout << "EJECT CARD!" << endl;
                isLogin = false;
            }
            else{
                cout << "WRONG BUTTON!" << endl;
            }
        }


    }

    return 0;
}