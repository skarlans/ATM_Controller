#include <cassert>
#include <iostream>
#include "Hardware.h"

using namespace std;

void TestHardware(){

    cout << "Hardware Test Start" << endl;
    CardReader reader;

    cout << "Test CardReader::getCardNumber->Initialization" << endl;
    assert(reader.getCardNumber() == -1);

    cout << "Test CardReader::InsertCard" << endl;
    assert(reader.InsertCard(1234));

    cout << "Test CardReader::InsertCard->duplicate case" << endl;
    assert(!reader.InsertCard(1111));

    cout << "Test CardReader::getCardNumber->wrong number case" << endl;
    assert(reader.getCardNumber() != 1111);

    cout << "Test CardReader::getCardNumber->proper number case" << endl;
    assert(reader.getCardNumber() == 1234);

    cout << "Test CardReader::ejectCard" << endl;
    reader.ejectCard();

    cout << "Test CardReader::getCardNumber->After Eject" << endl;
    assert(reader.getCardNumber()==-1);

    cout << "Hardware Test Ended" << endl;



}
