#include <fstream>
#include <sstream>
#include "Board.h"
#include "Candystore.h"

vector<Candy> readCandies(vector<Candy> candies)
{

    // reads the candies.txt file and adds the candies listed in the text file to the vector

    ifstream file("candies.txt");
    string text;

    string name;
    string description;
    string effect;
    string effect_value; // double
    string candy_type;
    string price; // double

    if (file.is_open())
    {
        while (getline(file, text))
        {
            stringstream ss(text);
            getline(ss, name, '|');
            getline(ss, description, '|');
            getline(ss, effect, '|');
            getline(ss, effect_value, '|');
            getline(ss, candy_type, '|');
            getline(ss, price);

            Candy candy = {name, description, effect, stod(effect_value), candy_type, stod(price)};
            candies.push_back(candy);
        }
    }
    else
    {
        cout << "File is not Open." << endl;
        file.close();
        return candies;
    }

    file.close();
    return candies;
}

vector<Player> readPlayers(vector<Player> players, vector<Candy> candies)
{
    // reads the candies.txt file and adds the candies listed in the text file to the vector

    ifstream file("players.txt");
    string text;

    string name;
    string stamina; // int
    string gold;    // double
    int candy_amount = 0;
    Candy candy_array[9];
    int position = 0;
    string candy_name;

    if (file.is_open())
    {
        while (getline(file, text))
        {
            stringstream ss(text);
            getline(ss, name, '|');
            getline(ss, stamina, '|');
            getline(ss, gold, '|');
            while (getline(ss, candy_name, ','))
            {
                for (int i = 0; i < candies.size(); i++)
                {
                    if (candies[i].name == candy_name)
                    {
                        candy_array[candy_amount] = candies[i];
                        candy_amount++;
                    }
                }
            }
            getline(ss, candy_name);

            Player player = {name, stoi(stamina), stod(gold), candy_array, 9, position};
            players.push_back(player);
        }
    }
    else
    {
        cout << "File is not Open." << endl;
        file.close();
        return players;
    }

    file.close();
    return players;
}

void characterSelect(Player &p, vector<Player> &players)
{
    // using the player objects from our players array
    // print each character object in the players array
    // take input and remove selected character while also setting current player to selected character values
}

void checkTile(Board &board, Player &p1, Player &p2, int &previous_position)
{
    // p1 is the player whose tile is being checked
    // using the player position it will check what tile its on for six things, a calamity, a special tile, a hidden treasure, a candy store, a candy tile, and a robbery
    // first it will check if you have the same position as the other player, if you do it will call robbery function

    // then it will check if there is a candy tile, and if there is the appropriamte amount of turns will be lost (these effect future turns)

    // then it will check if its a candy store tile using board functions, if it is it will use the candy class functions to display candies and offer to sell them
    // after all the candy class functions are used appropriately it will immediately end function

    // if its not a candy store, checkTile function will create a random number 1 through 10, if its 1-8, its a regular tile and 9-10 is a special tile

    // if its a regular tile it will assign a random number 1 through 10, if its 1-4 (signifying 40%), it will then go to the calamity function
    // if its 5-10, it will end function

    // if its a special tile, it will call special tile function
}

bool riddle()
{
    // it will read the riddles.txt file to get a vector of possible riddles
    // it will then randomly select a riddle and ask for user input
    // if its solved, return true, if not, return false

    return true;
}

bool rps()
{
    // plays rock paper scissors against computer
    // computer will choose number 1 - 3 and use random number to choose rock paper or scissors
    // from there it will take user input and match the results
    // if its a tie it will loop
    // if its a win, it will return true, if its a loss it will return false

    return true;
}

void calamity(Player &p)
{
    // using the different percentages listed in the instructions it will call one of the calamities
    // calamaties that use rock paper siccsors will call the rock paper scissors function
}

void robbery(Player &p1, Player &p2)
{
    // p2 will be the one stealing p1 will the one being stolen from
    // check if other player has a robbery repel, if so remove candy and end function
    // if theres no robbery repel, a random number of coins between 5 - 30 will be stolen
}

void hiddenTreasure(Board &board, Player &p1)
{
    //using the board functions it will check if there is a hidden treasure
    //then using a random number it will randomly select wich hidden treasure it is
    //it will then apply change in values to player
}

void specialTile(Player &p, int &previous_position)
{
    ////create a random number 1 through 4
    // splitting each different special tile between the numbers 1 through 4 it will randomly select a special tile
    // the different special tiles are listed in the instructions but one uses the previous position as in the parameters
}

void useCandy(Candy &c, Board &board, Player &p1, Player &p2)
{
    // based off checking the candies values it will determine the effect of the candy
    // if the candy effects a tile on the board, the board object will be updated using the addCandyTile function
}

void menu()
{
    // the menu function is not only printing the menu but also will check if the player gets a turn
    // it will check if the player has lost any turns and if there is any lost turns it will increase lost turns by 1 and end function
    // if there is no lost turns it will then print the options:
    // 1. draw a card 2. use candy 3. show player stats
    // drawing a card prints a random color and a single double or triple and will move player based on result
    // after drawing a card and moving the character it will call the check tile function
    // using a candy does not take up the turn and will use its effect
    // showing a players stats also does not take up a turn and will show current players name, gold, stamina, and inventory
}