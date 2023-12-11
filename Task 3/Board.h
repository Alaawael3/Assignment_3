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
    static const int ROWS_2 = 6;
    static const int COLUMNS_2 = 7;
    static const int ROWS_3 = 5;
    static const int COLUMNS_3 = 5;

    static string boardArray[ROWS][COLUMNS];
    static string boardArray_2[ROWS_2][COLUMNS_2];
    static string boardArray_3[ROWS_3][COLUMNS_3];
    int n_moves;
public:
    virtual void update_board (int x, int y, string mark) = 0;
    virtual void update_board_2 (int x, int y, string mark) = 0;
    virtual bool update_board_3(int x, int y, string mark)=0;

    virtual bool validcells_1()=0;
    virtual bool validcells_2()=0 ;
    virtual bool game_is_over() const = 0;

    virtual bool checkWin(Player* player)=0;
    virtual bool checkWin_2(Player* player) = 0;
    virtual bool checkWin_3()=0;

    virtual void display_1() = 0;
    virtual void display_2() = 0;
    virtual void display_3() const=0;

    virtual bool checkvalid(int x,int y) = 0;
    virtual bool checkvalid_2(int x,int y) = 0;
};

///////////////////////////////////////////
class Player {
protected:
    string name;
    string symbol;
public:

    Player (string symbol); // Needed for computer players
    Player (int order, string symbol);

    virtual void get_move(int& x, int& y,int gamenomber);
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
    bool validcells_1();
    bool validcells_2() ;
    bool game_is_over() const;

    bool checkvalid(int x,int y);
    bool checkvalid_2(int x,int y);

    void display_1();
    void display_2()  ;
    void display_3() const;

    void update_board (int x, int y, string mark);
    void update_board_2 (int x, int y, string mark);
    bool update_board_3(int x, int y, string mark);

    bool checkWin(Player* player);
    bool checkWin_2(Player *player)  ;
    bool checkWin_3();


};

///////////////////////////////////////////

class Random_Player: public Player {
protected:
    int dimension;
public:
    // Take a symbol and pass it to parent
    Random_Player (string symbol, int dimension);
    // Generate a random move
    void get_move(int& x, int& y,int gamenomber);
    string get_symbol();

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
    void runGame_1();
    void runGame_2();
    void runGame_3();

};




#endif //TEST_TASK2_BOARD_H
