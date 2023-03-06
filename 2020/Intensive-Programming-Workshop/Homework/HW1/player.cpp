#include "Player.h"

Player::Player(const std::string name, const bool is_human){//constructor
    name_ = name;
    is_human_ = is_human;
    pos_.row = 0;
    pos_.col = 0;
}

void Player:: SetPosition(int row, int col){
    pos_.row = row;
    pos_.col = col;
}
