//
// Created by lolow on 12/6/2023.
//

#ifndef TASK_2_PLAYER_H
#define TASK_2_PLAYER_H

#pragma once
#include <string>
#include <bits/stdc++.h>

using namespace std;
class Player {
public:
    Player(char symbol);
    Player (int order, char symbol);
    string get_symbol();
    string to_string();
    void get_move (int& x, int& y);

protected:
    string name;
    string symbol;
};
#endif //TASK_2_PLAYER_H
