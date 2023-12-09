//
// Created by lolow on 12/6/2023.
//

#ifndef TASK_2_GAMEMANAGER_H
#define TASK_2_GAMEMANAGER_H
#pragma once

#include "Player.h"
#include "Random_player.h"
#include "Xo_board.h"

class GameManager {
public:
    GameManager(X_O_Board* board,Player* player[]);
    GameManager();
    void runGame();

protected:
    X_O_Board* board;
    Player* currentPlayer;
    Player* player[2];
};

#endif //TASK_2_GAMEMANAGER_H
