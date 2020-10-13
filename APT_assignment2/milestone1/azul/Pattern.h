#ifndef PATTERN
#define PATTERN

#include "Type.h"

#include <vector>

class Pattern{
public:
    Pattern();

    // Get a pattern line
    const std::vector<Tile>& getPatternLine(int index) const;
    // Put a type of tiles on the pattern line of the specified number of rows
    bool placeTile(Tile tiles, unsigned int row);
    // Return the tile at the head of a pattern line
    Tile getFirstTile(int row) const;
    // Return the tile at the back of a pattern line
    Tile getLastTile(int row) const;
    // Clear a pattern line
    void clear(int index);

private:
    std::vector<std::vector<Tile>> pattern;
};

#endif // PATTERN