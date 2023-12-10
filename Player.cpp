//
// Created by lolow on 12/6/2023.
//
#include "Board.h"

Player::Player(string symbol) {
    this->symbol = symbol;
}

Player::Player (int order, string symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 5)for x and form (0,6) for y separated by spaces: ";
    cin >> x >> y;
}

string Player::to_string(){
    return "Player: " + name ;
}

// Get symbol used by player
string Player::get_symbol() {
    return symbol;
}
