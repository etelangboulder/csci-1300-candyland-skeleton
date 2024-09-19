#include "Candystore.h"

CandyStore::CandyStore()
{
    vector<Candy> c;
    _store_supply = c;
    _store_name = "";
    _store_gold = 0;
}

CandyStore::CandyStore(vector<Candy> store_supply, string store_name, double store_gold, int position)
{
    _store_supply = store_supply;
    _store_name = store_name;
    _store_gold = store_gold;
    _position = position;
}

int CandyStore::getStorePosition() const
{
    return _position;
}

void CandyStore::displayCandy()
{
    cout << "Here is a list of candies in the store:" << endl;
    for (int i = 0; i < _store_supply.size(); i++)
    {
        cout << "------------------------------------" << endl;
        cout << "Name: " << _store_supply[i].name << endl;
        cout << "Description: " << _store_supply[i].description << endl;
        cout << "Effect: " << _store_supply[i].effect << endl;
        cout << "Effect Value: " << _store_supply[i].effect_value << endl;
        cout << "Candy Type: " << _store_supply[i].candy_type << endl;
        cout << "Price: " << _store_supply[i].price << endl;
    }
    cout << "------------------------------------" << endl;
}

void CandyStore::addStoreCandy(Candy c)
{
    _store_supply.push_back(c);
}

void CandyStore::buyCandy(Candy c)
{
    for (int i = 0; i < _store_supply.size(); i++)
    {
        // take in user input search for candy
        // if its not there return and end function
        //if it is there check if player has enough gold, if not end function
        //if there is enough gold, 1.remove candy from shop and add candy to inventory 2.subtract price of candy from player gold 3. add price of candy to store gold

        _store_gold += c.price;
    }
}