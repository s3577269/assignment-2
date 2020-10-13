#include "Player.h"

Player::Player(const std::string& name, bool isAI):ai(isAI){
    this->name = name;
    score = 0;
    mosaic = new Mosaic();
}

Player::~Player(){
    delete mosaic;
}

const std::string& Player::getName() const{
    return this->name;
}

int Player::getScore() const{
    return this->score;
}

void Player::updateScore() {    
    score+=mosaic->getScore();
}

Mosaic* Player::getMosaic() const{
    return mosaic;
}

bool Player::isAI() const
{
    return ai;
}