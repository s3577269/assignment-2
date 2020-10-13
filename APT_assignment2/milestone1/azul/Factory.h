#ifndef FACTORY
#define FACTORY

#include "Type.h"
#include <deque>
#include <vector>
#include <map>

class Factory {
public:
    Factory(bool enhanced);
    
    //Add tile into factory
    void addTile(Tile tile);

    //Check if the facory is empty
    bool isEmpty();

    //Size of the factory
    unsigned int size();

    //Get tile within factory
    Tile getTile(unsigned int i);

    //Remove tiles in factory
    void clearFactory();

    //Find
    bool find(Tile tile);

    //Display the content of a factory
    void display() const;
    
    //Take tiles from a factory and move the remaining tiles into the centre factory
    std::vector<Tile> takeTiles(unsigned int factoryIndex, Tile tile, Factory* centre);

    //Accessor to the tiles counter map of a factory
    const std::map<Tile, size_t>& tileNumbers() const;

private:
    std::deque<Tile> tiles;
    std::map<Tile, size_t> numbers;
    bool enhanced;
};

#endif //FACTORY