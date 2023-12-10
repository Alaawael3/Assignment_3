// Created by lolow on 12/6/2023.
//
#include "Board.h"
#include <cstdlib>

using namespace std;

// Set player symbol and name as Random Computer Player
Random_Player::Random_Player (string symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void Random_Player::get_move (int& x, int& y) {
    x = rand()%6;
    y = rand()%7;
}
