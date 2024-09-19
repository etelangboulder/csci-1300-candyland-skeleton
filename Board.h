#ifndef BOARD_H
#define BOARD_H

#include "Player.h"

#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

class Board
{
private:
    const static int _BOARD_SIZE = 83;
    Tile _tiles[_BOARD_SIZE];
    const static int _MAX_CANDY_STORE = 3;
    int _candy_store_position[_MAX_CANDY_STORE];
    vector<CandyTile> candyTiles;
    int _candy_store_count;

public:
    Board(Player, Player);

    void resetBoard(Player, Player);
    void displayTile(int, Player, Player);
    void displayBoard(Player, Player);

    int getBoardSize() const;
    int getCandyStoreCount() const;

    bool addCandyStore(int);
    bool isPositionCandyStore(int);
    bool addCandyTile(Candy);
    bool isPositionCandyTile(Player &p);
};
#endif