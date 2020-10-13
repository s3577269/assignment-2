#ifndef PLAYER
#define PLAYER

#include "Type.h"
#include "Mosaic.h"

#include <string>

class Player{
public:
    Player(const std::string& name, bool isAI);
    ~Player();

    // Return name
    const std::string& getName() const;
    // Return score
    int getScore() const;
    // Update  score
    void updateScore();
    // Return this player's mosaic board
    Mosaic* getMosaic() const;

    bool isAI() const;
private:
    std::string name;
    int score;
    Mosaic* mosaic;
    bool ai;
};

#endif // PLAYER