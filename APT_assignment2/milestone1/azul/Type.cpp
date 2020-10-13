#include "Type.h"
#include <exception>
#include <stdexcept>

char convertToChar(Tile tile){
    char charTile = N;
    if(tile == RED){
        charTile = R;
    } else if(tile == YELLOW){
        charTile = Y;
    } else if(tile == DARK_BLUE){
        charTile = B;
    } else if(tile == LIGHT_BLUE){
        charTile = L;
    } else if(tile == BLACK){
        charTile = U;
    } else if(tile == FIRST_PLAYER){
        charTile = F;
    }
    return charTile;    
}


Tile convertToEnum(char tile){
    Tile enumTile = NO_TILE;
    if(tile == R){
        enumTile = RED;
    } else if(tile == Y){
        enumTile = YELLOW;
    } else if(tile == B){
        enumTile = DARK_BLUE;
    } else if(tile == L){
        enumTile = LIGHT_BLUE;
    } else if(tile == U){
        enumTile = BLACK;
    } else if(tile == F){
        enumTile = FIRST_PLAYER;
    } else if(tile == N){
        enumTile = NO_TILE;
    } else {
        throw std::invalid_argument("Invalid tile - tile type not found");
    }
    return enumTile;
}