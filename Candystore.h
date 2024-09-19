#ifndef CANDYSTORE_H
#define CANDYSTORE_H

#include "Struct.h"

class CandyStore
{
private:
    vector<Candy> _store_supply;
    string _store_name;
    double _store_gold;
    int _position;

public:
    CandyStore();
    CandyStore(vector<Candy>, string, double, int);

    int getStorePosition() const;

    void displayCandy();       // display 3 candies
    void addStoreCandy(Candy); // add candy to menu
    void buyCandy(Candy);      // remove candy and add store gold
};

#endif