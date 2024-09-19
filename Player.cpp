#include "Player.h"

Player::Player()
{
    _name = "";
    _stamina = 0;
    _gold = 0;
    _candy_amount = 0;
    _player_position = 0;

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        Candy candy{"", "", "", 0, "", 0};
        _inventory[i] = candy;
    }
}

Player::Player(string name, int stamina, double gold, Candy candy_array[], const int CANDY_ARR_SIZE, int player_position)
{
    _name = name;
    _stamina = stamina;
    _gold = gold;
    _candy_amount = 0;
    _player_position = player_position;

    // empty inventory
    for (int i = 0; i < CANDY_ARR_SIZE; i++)
    {
        if (candy_array[i].name.empty())
        {
        }
        else if (_candy_amount < _MAX_CANDY_AMOUNT)
        {
            _inventory[i] = candy_array[i];
            _candy_amount++;
        }
    }
}

int Player::getCandyAmount() const
{
    return _candy_amount;
}

int Player::getStamina() const
{
    return _stamina;
}

double Player::getGold() const
{
    return _gold;
}

string Player::getName() const
{
    return _name;
}

int Player::getTurnsLost() const
{
    return _turns_lost;
}

int Player::getPosition() const
{
    return _player_position;
}

void Player::printInventory()
{
    for (int i = 1; i <= _MAX_CANDY_AMOUNT; i++)
    {
        cout << "|[";
        if (_inventory[i - 1].name.empty())
        {
            cout << "Empty";
        }
        else
        {
            cout << _inventory[i - 1].name;
        }
        cout << "]|";

        if (i % 3 == 0)
        {
            cout << endl;
        }
    }
}

void Player::setStamina(int stamina)
{
    if (stamina > 100)
    {
        stamina = 100;
    }
    else if (stamina < 0)
    {
        stamina = 0;
    }
    _stamina = stamina;
}

void Player::setGold(double gold)
{
    if (gold > 100)
    {
        gold = 100;
    }
    else if (gold < 0)
    {
        gold = 0;
    }
    _gold = gold;
}

void Player::setName(string name)
{
    _name = name;
}

void Player::setTurnsLost(int turns_lost)
{
    _turns_lost = turns_lost;
}

void Player::setPosition(int position)
{
    if(position < 0){
        position = 0;
    }
    _player_position = position;
}

void Player::movePlayer(int position)
{
    _player_position += position;
}

Candy Player::findCandy(string candy_name)
{
    string candy_lowercase;

    for (int i = 0; i < candy_name.length(); i++)
    {
        candy_lowercase += tolower(candy_name[i]);
    }

    candy_name = candy_lowercase;

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        string inventory_name = _inventory[i].name;
        string inventory_lowercase;
        for (int j = 0; j < inventory_name.length(); j++)
        {
            inventory_lowercase += tolower(inventory_name[j]);
        }

        if (inventory_lowercase == candy_name)
        {
            return _inventory[i];
        }
    }

    Candy candy{"", "", "", 0, "", 0};
    return candy;
}

bool Player::addCandy(Candy candy)
{
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        if (_inventory[i].name.empty())
        {
            _inventory[i] = candy;
            _candy_amount++;
            return true;
        }
    }

    return false;
}

bool Player::removeCandy(string candy_name)
{
    string candy_lowercase;

    for (int i = 0; i < candy_name.length(); i++)
    {
        candy_lowercase += tolower(candy_name[i]);
    }

    candy_name = candy_lowercase;

    for (int i = _MAX_CANDY_AMOUNT - 1; i >= 0; i--)
    {
        string inventory_name = _inventory[i].name;
        string inventory_lowercase;
        for (int j = 0; j < inventory_name.length(); j++)
        {
            inventory_lowercase += tolower(inventory_name[j]);
        }
        if (inventory_lowercase == candy_lowercase)
        {
            Candy candy{"", "", "", 0, "", 0};
            _inventory[i] = candy;
            _candy_amount--;

            for (int j = i; j < _MAX_CANDY_AMOUNT - 1; j++)
            {
                _inventory[j] = _inventory[j + 1];
                _inventory[j + 1] = candy;
            }

            return true;
        }
    }

    return false;
}