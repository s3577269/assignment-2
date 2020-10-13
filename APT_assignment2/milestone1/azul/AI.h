#include "Factory.h"
#include "Player.h"

// free function to compute the best move of a player giving the current game state
std::string computeNextMove(const std::vector<Factory*>& factories, const Player* const player);