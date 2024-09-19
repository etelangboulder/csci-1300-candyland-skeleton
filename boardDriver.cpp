#include "Board.h"
#include "Player.h"
#include "Candystore.h"
#include "Game.cpp"

int main()
{
    Player p1;
    Player p2;

    vector<Candy> candies;
    candies = readCandies(candies);
    vector<Player> players;
    players = readPlayers(players, candies);

    characterSelect(p1, players);
    characterSelect(p2, players);

    Board board{p1, p2};
    board.displayBoard(p1, p2);
    

    return 0;
}