//
// Created by lolow on 12/6/2023.
//
// RandomPlayer.cpp
#include "Random_player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Set player symbol and name as Random Computer Player
Random_player::Random_player (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void Random_player::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}
