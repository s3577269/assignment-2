#ifndef BOX_LID_H
#define BOX_LID_H 

#include <vector>

#include "Type.h"

// Class represents a box lid.
class BoxLid
{    
private:
    friend class TileBag;

    BoxLid(int s);

    // add a tile into the box lid
    void addTile(Tile tile);

    // shuffle tiles in the box lid
    void shuffle();

    // clear the tiles in the box lid
    void clear();

    // seed for random generator
    int seed;
    
    std::vector<Tile> tiles;
};

#endif // BOX_LID_H