#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <vector>

using namespace std;

struct Candy
{
    string name;
    string description;
    string effect;
    double effect_value;
    string candy_type;
    double price;
};

struct Tile
{
    string color;
    string tile_type;
};

struct CandyTile
{
    string name;
    int position;
    int turnLoss;
};

#endif