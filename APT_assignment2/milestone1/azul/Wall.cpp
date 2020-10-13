#include "Wall.h"
#include <iostream>

Wall::Wall(){
    wall = new Tile*[ROW];
    for(int i = 0; i != ROW; i++) {
        wall[i] = new Tile[COLUMN];
        for(int j = 0; j != COLUMN; j++) {
            wall[i][j] = NO_TILE;
        }
    }
}

Wall::~Wall(){
    for(int i = 0; i != ROW; i++) {
        delete wall[i];
    }
    delete wall;
}

int Wall::tile(Tile tile, int row){
    int col = (tile + row) % COLUMN;
    wall[row][col] = tile;

    return computeScore(tile, row);
}

bool Wall::checkColor(Tile tile, int row) const{
    bool hasSameColor = false;
    for(int i=0;i!=COLUMN;++i){
        if(wall[row-1][i]==tile){
            hasSameColor = true;
        }
    }
    return hasSameColor;
}


void Wall::display(int i) const
{
    // Print wall part
    for(int j = 0; j != COLUMN; ++j){
        std::cout<<convertToChar(wall[i][j])<<" ";
    }
}


std::set<Tile> Wall::existingTiles(int row) const
{
    std::set<Tile> tileSet;
    for (size_t i = 0; i < COLUMN; i++)
    {
        auto t = wall[row][i];
        if (t!=NO_TILE)
        {
            tileSet.insert(t);
        }
        
    }
    return tileSet;
}

int Wall::computeScore(Tile tile, size_t row) const
{
    int col = (tile + row) % COLUMN;
    int score = 0;
    int n_x_adjacent = 0;  
    bool x_adjacent = true;    
    // Down-check
    for (int i = row+1; i < ROW && x_adjacent; i++)
    {
        if (wall[i][col] == NO_TILE)
        {
            x_adjacent = false;
        }else{
            n_x_adjacent++;
        }        
    }

    x_adjacent = true;
    for(int i = row-1; i >= 0 && x_adjacent; i--) 
    {
         if(wall[i][col] == NO_TILE) {
             x_adjacent = false;
         }
         else {
             n_x_adjacent++;
         }
     }
    

    bool y_adjacent = true;
    int n_y_adjacent = 0;
    // Up-check
     // Right-check
    for(int i = col+1; i < COLUMN && y_adjacent; i++) {
        if(wall[row][i] == NO_TILE) {
            y_adjacent = false;
        }
        else {
            n_y_adjacent++;
        }
    }

     y_adjacent = true;
    // Left-check
    for(int i = col-1; i >= 0 && y_adjacent; i--) {
        if(wall[row][i] == NO_TILE) {
            y_adjacent = false;
        }
        else {
            n_y_adjacent++;
        }
    }
    score+=n_x_adjacent;
    score+=n_y_adjacent;
    score++;
    
    return score;
}