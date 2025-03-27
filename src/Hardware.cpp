#include "Hardware.h"

CardReader::CardReader() : m_icurrentCard(-1), m_bCardInserted(false) {}

bool CardReader::InsertCard(int CardNumber){

    if(m_bCardInserted)
        return false;
    
    m_icurrentCard = CardNumber;
    m_bCardInserted = true;
    return true;
}

int CardReader::getCardNumber() const{
    if(!m_bCardInserted)
        return -1;
    
    return m_icurrentCard;
}

void CardReader::ejectCard() {

    m_icurrentCard = -1;
    m_bCardInserted = false;
}