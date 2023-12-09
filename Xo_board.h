//
// Created by lolow on 12/6/2023.
//

#ifndef TASK_2_XO_BOARD_H
#define TASK_2_XO_BOARD_H
#pragma once
#include <string> // Add this line
#include "GameManager.h"

class X_O_Board: public GameManager  {
public:
    X_O_Board();
     bool validcells() ;

    bool checkvalid(int& x,int& y);

    void display() const ;
    void update_board (int x, int y, string mark);

    bool checkWin(Player *player) const ;

private:
    static const int ROWS = 6;
    static const int COLUMNS = 7;
    static string boardArray[ROWS][COLUMNS];
};
#endif //TASK_2_XO_BOARD_H
