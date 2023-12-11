//
// Created by lolow on 12/10/2023.
//

#ifndef TEST_TASK2_BOARD_H
#define TEST_TASK2_BOARD_H
#include <bits/stdc++.h>
class Player;
using namespace std;

class Board {
protected:
    static const int ROWS = 3;
    static const int COLUMNS = 5;
    static string boardArray[ROWS][COLUMNS];

public:
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual void update_board (int x, int y, string mark) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool validcells()=0 ;
    virtual bool checkWin(Player* player) = 0;
    // Return true if all moves are done and no winner
    virtual void display() = 0;
    // Return true if game is over
    virtual bool checkvalid(int x,int y) = 0;
};

///////////////////////////////////////////
// This class represents a player who has
// a name and a symbol to put on board
class Player {
protected:
    string name;
    string symbol;
public:
    // Two constructors to initiate player
    // Give player a symbol to use in playing
    // It can be X or O or others
    // Optionally, you can give him ID or order
    // Like Player 1 and Player 2
    Player (string symbol); // Needed for computer players
    Player (int order, string symbol);
    // Get desired move: x y (each between 0 and 2)
    // Virtual (can change for other player types)
    virtual void get_move(int& x, int& y);
    // Give player info as a string
    string to_string();
    // Get symbol used by player
    string get_symbol();
};

///////////////////////////////////////////
// This class represents a 3 x 3 board
// used in X_O game
class X_O_Board:public Board {
public:
    X_O_Board();
    bool validcells() ;

    bool checkvalid(int x,int y);

    void display()  ;
    void update_board (int x, int y, string mark);

    bool checkWin(Player *player)  ;



};

///////////////////////////////////////////
// This class represents a random computer player
// that generates random positions x y (0 to 2)
// If invalid, game manager asks to regenerate
class Random_Player: public Player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    Random_Player (string symbol, int dimension);
    // Generate a random move
    void get_move(int& x, int& y);
};

///////////////////////////////////////////
class GameManager {
private:
    Board* board;
    Player* player[2];
    Player* currentPlayer;
public:

    GameManager(Board* board,Player* player[]);
    GameManager();
    void runGame();

};




#endif //TEST_TASK2_BOARD_H