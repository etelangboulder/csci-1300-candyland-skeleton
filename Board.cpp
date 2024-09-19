#include "Board.h"

Board::Board(Player p1, Player p2)
{
    resetBoard(p1, p2);
}

void Board::resetBoard(Player p1, Player p2)
{
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
    Tile new_tile;
    string current_color;
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        new_tile = {current_color, "regular tile"};
        _tiles[i] = new_tile;
    }
    new_tile = {ORANGE, "regular tile"};
    _tiles[_BOARD_SIZE - 1] = new_tile;

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1;
    }

    p1.setPosition(0);
    p2.setPosition(0);
}

void Board::displayTile(int position, Player p1, Player p2)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";
    if (position == p1.getPosition())
    {
        cout << "1";
    }
    else if (position == p2.getPosition())
    {
        cout << "2";
    }
    else
    {
        cout << " ";
    }
    cout << " " << RESET;
}

void Board::displayBoard(Player p1, Player p2)
{
    cout << endl;

    // First horizontal segment
    for (int i = 0; i <= 23; i++)
    {
        displayTile(i, p1, p2);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        displayTile(i, p1, p2);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        displayTile(i, p1, p2);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i, p1, p2);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i, p1, p2);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

bool Board::addCandyStore(int position)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _candy_store_position[_candy_store_count] = position;
    _candy_store_count++;
    return true;
}

bool Board::isPositionCandyStore(int board_position)
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if (_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

bool Board::addCandyTile(Candy c)
{
    int set_position = 0;

    cout << "What tile would you like your candy to be put on. (Tile #1 is 0)" << endl;
    cin >> set_position;

    if (set_position < 0 || set_position >= _BOARD_SIZE)
    {
        cout << "That position isn't valid!" << endl;
        return false;
    }
    else
    {
        for(int i = 0; i < candyTiles.size(); i++){
            if(set_position == candyTiles[i].position){
                cout << "That position already has a Candy Tile!" << endl;
                return false;
            }
        }
    }

    CandyTile ct;
    ct.name = c.name;
    ct.position = set_position;
    ct.turnLoss = c.effect_value;



    cout << c.name << " has been placed on Tile: " << set_position << " and any player who steps on that tile will lose " << (c.effect_value * -1) << " turns.";
    return true;
}

bool Board::isPositionCandyTile(Player &p)
{
    for (int i = 0; i < candyTiles.size(); i++)
    {
        if (candyTiles[i].position == p.getPosition())
        {
            cout << "You have stepped on a Candy Tile." << endl;
            cout << candyTiles[i].name << " has been placed on that tile and you lose " << (candyTiles[i].turnLoss * -1) << " turns.";
            p.setTurnsLost(p.getTurnsLost() + candyTiles[i].turnLoss);
            candyTiles.erase(candyTiles.begin() + i);
            return true;
        }
    }
    return false;
}