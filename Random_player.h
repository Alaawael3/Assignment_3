//
// Created by lolow on 12/6/2023.
//

#ifndef TASK_2_RANDOM_PLAYER_H
#define TASK_2_RANDOM_PLAYER_H

#pragma once
#include "Player.h"

class Random_player : public Player {
private:
    int dimension;
public:
    Random_player (char symbol, int dimension);
    void get_move (int& x, int& y);
};
#endif //TASK_2_RANDOM_PLAYER_H
