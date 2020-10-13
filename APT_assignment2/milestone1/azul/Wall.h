#ifndef WALL
#define WALL

#include "Type.h"
#include <vector>
#include <set>

class Wall{
public:
    Wall();
    ~Wall();

    // Put tiles to the wall and count score
    int tile(Tile tile, int row);
    // Get the tile type in the wall line
    bool checkColor(Tile tile, int row) const;
    // Display the ith row in console
    void display(int i) const;
    // Accessor to the existing tile set of a Pattern line
    std::set<Tile> existingTiles(int row) const;
    // Compute the score if a specific tile is add to the row
    int computeScore(Tile tile, size_t row) const;

private:
    Tile** wall;
};

#endif // WALL