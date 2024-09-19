#ifndef PLAYER_H
#define PLAYER_H

#include "Struct.h"

class Player
{
    // data member
    private:  
        string _name;
        const static int _MAX_CANDY_AMOUNT = 9;
        int	_stamina;
        double _gold;
        string _effect;
        Candy _inventory[_MAX_CANDY_AMOUNT];
        int	_candy_amount;
        int _player_position;
        int _turns_lost;

    public:
        Player();
        Player(string, int, double, Candy[], const int, int);

        int getCandyAmount() const; 
        int getStamina() const;
        double getGold() const;
        string getName() const;
        int getTurnsLost() const;
        int getPosition() const;
        
        void printInventory();

        void setStamina(int);
        void setGold(double);
        void setName(string);
        void setTurnsLost(int);
        void setPosition(int);
        void movePlayer(int);
        
        Candy findCandy(string);
        bool addCandy(Candy);
        bool removeCandy(string);
};
#endif