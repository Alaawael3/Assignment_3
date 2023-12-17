//
// Created by lolow on 12/17/2023.
//
#include "Board.h"
#include <cstdlib>

using namespace std;

// Set player symbol and name as Random Computer Player
Random_Player::Random_Player (string symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My name is " << name << endl;
    srand(unsigned(time(0)));

}

// Generate a random move
void Random_Player::get_move (int& x, int& y,int gamenomber) {
    if(gamenomber==1){
        x = rand()%5;
        y = rand()%3;
    }
    else if (gamenomber==2) {
        x = rand() % 6;
        y = rand() % 7;
    }
    else{
        x = (int) (rand() / (RAND_MAX + 1.0) * 5);
        y = (int) (rand() / (RAND_MAX + 1.0) * 5);
    }
}

string Random_Player::get_symbol() {
    return symbol;
}
