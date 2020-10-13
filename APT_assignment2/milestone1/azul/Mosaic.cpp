#include "Mosaic.h"

Mosaic::Mosaic(){
    score = 0;
    pattern = new Pattern();
    wall = new Wall();
}

Mosaic::~Mosaic(){
    delete pattern;
    delete wall;
}

void Mosaic::setPattern(std::vector<Tile> tiles, unsigned int patternRow){
    for(Tile tile:tiles){
        if(tile==FIRST_PLAYER || patternRow == ROW+1 ||!pattern->placeTile(tile,patternRow)){
            if(floor.size()>=FLOOR_SIZE){
                abandonList.push_back(tile);
            } else {
                floor.push_back(tile);
            }
        }
    }
}

void Mosaic::wallTiling(){
    for(int i=0;i!=ROW;++i){
        Tile abandonTile;
        bool full = true;

        for(Tile tile:pattern->getPatternLine(i)){
            if(tile==NO_TILE){
                full = false;
            }
        }
        if(full){
            abandonTile = pattern->getPatternLine(i).at(0);
            score+=wall->tile(abandonTile, i);
            pattern->clear(i);
            for(int j=0;j!=i;++j){
                abandonList.push_back(abandonTile);
            }
        }
    }
}

void Mosaic::resetFloor(){
    for(unsigned int i=0;i!=floor.size();++i){
        if(i>=MINUS_ONE&&i<MINUS_TWO){
            score-=1;
        } else if(i>=MINUS_TWO&&i<MINUS_THREE){
            score-=2;
        } else {
            score-=3;
        }
    }
    floor.clear();
}

std::vector<Tile> Mosaic::getAbandonList(){
    return abandonList;
}

int Mosaic::getScore(){
    return score;
}

void Mosaic::newRound(){
    abandonList.clear();
    score = 0;
}

Pattern* Mosaic::getPattern(){
    return pattern;
}

Wall* Mosaic::getWall(){
    return wall;
}

std::vector<Tile> Mosaic::getFloor(){
    return floor;
}
