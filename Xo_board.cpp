//
// Created by lolow on 12/6/2023.
//
#include "Xo_board.h"
#include <iostream>

X_O_Board::X_O_Board() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            stringstream ss;
            string s2,s1="(";
            ss>>i;
            ss<<s2;
            s1+=s2;
            s1+=',';
            ss>>j;
            ss<<s2;
            s1+=s2;
            s1+=')';
            boardArray[i][j] = s1;
        }
    }
}//default constructor

bool X_O_Board:: validcells(){
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLUMNS; ++c) {
            if (boardArray[r][c]!="x"||boardArray[r][c]!="o") return 1;
        }
    }
    return 0;
}

bool X_O_Board::checkvalid(int& x,int& y) {
    if (x >= 0 && x < ROWS &&
        y >= 0 && y < COLUMNS &&
            (boardArray[x][y]!="x"||boardArray[x][y]!="o"))
        return 1;
    else return 0;
}

void X_O_Board::update_board (int x, int y, string mark){
    if (checkvalid(x,y))
boardArray[x][y]=mark;
    else cout<<"invalid cell!";
}

void X_O_Board::display() const {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            cout << boardArray[i][j] << ' ';
        }
        cout << endl;
    }
}

bool X_O_Board::checkWin(Player* player) const {
    string symbol = player->get_symbol();

    //checking rows
    for (int r = ROWS - 1; r >= 0; --r) {
        int count = 0;
        for (int c = 0; c < COLUMNS; ++c) {
            if (boardArray[r][c] == symbol) count++;
            else count = 0;
            if (count >= 4) return 1;
        }
    }

    //checking columns
    for (int c = 0; c < COLUMNS; ++c) {
        int count = 0;
        for (int r = ROWS - 1; r >= 0; --r) {
            if (boardArray[r][c] == symbol) count++;
            else count = 0;
            if (count >= 4) return 1;
        }
    }

    //check diagonaly_right
    for (int r = ROWS - 1; r >= 0; --r) {
        int count = 0;
        for (int c = 0; c < COLUMNS; ++c) {
            if (boardArray[r][c] == symbol) {
                for (int i = 1; i < 4; ++i) {
                    if (c + i < COLUMNS && r - i >= 0 && boardArray[r - i][c + i] == symbol) {
                        count++;
                    } else {
                        count = 0;
                        break;
                    }
                    if (count >= 4) return 1;
                }
            } else count = 0;
            if (count >= 4) return 1;
        }
    }

    //check diagonaly_left
    for (int r = ROWS - 1; r >= 0; --r) {
        int count = 0;
        for (int c = 0; c < COLUMNS; ++c) {
            if (boardArray[r][c] == symbol) {
                for (int i = 1; i < 4; ++i) {
                    if (c - i < COLUMNS && r - i >= 0 && boardArray[r - i][c - i] == symbol) {
                        count++;
                    } else {
                        count = 0;
                        break;
                    }
                    if (count >= 4) return 1;
                }
            } else count = 0;
            if (count >= 4) return 1;
        }
    }

    return false;
}
