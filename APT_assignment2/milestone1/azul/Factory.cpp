#include "Factory.h"
#include <iostream>
#include <algorithm>

Factory::Factory(bool e): enhanced(e)
{
}


void Factory::addTile(Tile tile) {
    tiles.push_back(tile);
    if (numbers.find(tile) != numbers.end())
    {
        numbers[tile]++;
    }
    else{
        numbers[tile] = 1;
    }        
}

bool Factory::find(Tile tile) {
   return (std::find(tiles.begin(), tiles.end(), tile) != tiles.end());
}

unsigned int Factory::size() {
    return tiles.size();
}

bool Factory::isEmpty() {
    return tiles.empty();
}

void Factory::clearFactory() {
    tiles.clear();
    numbers.clear();
}

void Factory::display() const{
    for(Tile tile: tiles){
        std::cout<<convertToChar(tile)<<" ";
    }
    if (enhanced)
    {
        std::cout << "[";
        for (const auto& e: numbers)
        {
            std::cout << convertToChar(e.first) << ": " << e.second << "|";
        }        
        std::cout << "]";
    }    
}

std::vector<Tile> Factory::takeTiles(unsigned int factoryIndex, Tile tile, Factory* centre)
{
    std::vector<Tile> returnTiles;
    std::vector<Tile> remainTiles;

    while(!tiles.empty())
    {        
        auto t = tiles.front();
        if (t==tile || t==FIRST_PLAYER)
        {
           returnTiles.push_back(t);
        } else
        {
           remainTiles.push_back(t);
        }        
        
        tiles.pop_front();

        // update counter        
        if (numbers.find(t) != numbers.end())
        {
            numbers[t]--;
            if (numbers[t] == 0)
            {
                numbers.erase (t);
            }                
        }
        else{
            numbers[t] = 1;
        }    
    }
    
    for (Tile t: remainTiles)
    {
        centre->addTile(t);
    }
    
    return returnTiles;
}

 const std::map<Tile, size_t>& Factory::tileNumbers() const
 {
     return numbers;
 }