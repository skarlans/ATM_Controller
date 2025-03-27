#ifndef CARDREADER_H
#define CARDREADER_H

class CardReader{
private:
    int m_icurrentCard;
    bool m_bCardInserted;
public:
    
    // Constructor for CardReader
    CardReader();

    // InsertCard, if card is existed already, return false. If not, return true;
    bool InsertCard(int cardNumber);

    // Getter for Cardnumber, if card is not existed, return -1. Else, return Cardnumber
    int getCardNumber() const;

    // Eject Card, Erase Card Information.
    void ejectCard();
};
#endif