#ifndef MOSAIC
#define MOSAIC

#include "Type.h"
#include "Pattern.h"
#include "Wall.h"

#include <vector>

class Mosaic{
public:
    Mosaic();
    ~Mosaic();

    // Place a list of tiles on one pattern line, if the pattern line is full, put the rest of tiles to floor
    void setPattern(std::vector<Tile> tiles, unsigned int patternRow);
    // Wall-Tiling phase, update abandonList and score
    void wallTiling();
    // Clear the floor, update abandonList and score
    void resetFloor();
    // Return abandonList
    std::vector<Tile> getAbandonList();
    // Return score
    int getScore();
    // Reset abandonList and score
    void newRound();
    // Return pattern
    Pattern* getPattern();
    // Return wall
    Wall* getWall();
    // Return floor
    std::vector<Tile> getFloor();

private:
    std::vector<Tile> floor;
    int score;
    std::vector<Tile> abandonList;
    Pattern* pattern;
    Wall* wall;
};

#endif // MOSAIC