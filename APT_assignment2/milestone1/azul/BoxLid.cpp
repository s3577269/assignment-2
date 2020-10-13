#include <random>

#include "BoxLid.h"


BoxLid::BoxLid(int s):seed(s){}

void BoxLid::addTile(Tile tile)
{
    tiles.push_back(tile);
}
    
    
void BoxLid::shuffle()
{
    std::default_random_engine gen{seed};

    int size = tiles.size();
    for (int i = size-1; i >0; i--)
    {
        std::uniform_int_distribution<int> uniform(0, i);
        int index = uniform(gen);

        // swap the ith tile with the randomly selected tile
        auto temp  = tiles[index];
        tiles[index] = tiles[i];
        tiles[i] = temp;
    }    
}
    
void BoxLid::clear()
{
    tiles.clear();
}