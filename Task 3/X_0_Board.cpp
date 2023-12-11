//
// Created by lolow on 12/6/2023.
//
#include "Board.h"
#include <iostream>

string Board::boardArray[ROWS][COLUMNS];
string Board::boardArray_2[ROWS_2][COLUMNS_2];
string Board::boardArray_3[ROWS_3][COLUMNS_3];

X_O_Board::X_O_Board() {
    for (int i = 0; i < ROWS_3; ++i) {
        for (int j = 0; j < COLUMNS_3; ++j) {
            stringstream ss;
            string s2,s1="(";
            ss<<i;
            ss>>s2;
            s1+=s2;
            s2.clear();
            ss.clear();
            s1+=',';
            ss<<j;
            ss>>s2;
            s1+=s2;
            s1+=')';
            boardArray_3[i][j] = s1;
        }
    }

    for (int i = 0; i < ROWS_2; ++i) {
        for (int j = 0; j < COLUMNS_2; ++j) {
            stringstream ss;
            string s2,s1="(";
            ss<<i;
            ss>>s2;
            s1+=s2;
            s2.clear();
            ss.clear();
            s1+=',';
            ss<<j;
            ss>>s2;
            s1+=s2;
            s1+=')';
            boardArray_2[i][j] = s1;
        }
    }
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            stringstream ss;
            string s2,s1="(";
            ss<<i;
            ss>>s2;
            s1+=s2;
            s2.clear();
            ss.clear();
            s1+=',';
            ss<<j;
            ss>>s2;
            s1+=s2;
            s1+=')';
            boardArray[i][j] = s1;
        }
    }
}//default constructor



bool X_O_Board:: validcells_1(){
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLUMNS; ++c) {
            if (boardArray[r][c]!="X"||boardArray[r][c]!="O") return 1;
        }
    }
    return 0;
}

bool X_O_Board:: validcells_2(){
    for (int r = 0; r < ROWS_2; ++r) {
        for (int c = 0; c < COLUMNS_2; ++c) {
            if (boardArray_2[r][c]!="X"||boardArray_2[r][c]!="O") return 1;
        }
    }
    return 0;
}

bool X_O_Board::game_is_over() const {
    return n_moves >= 24;
}

bool X_O_Board::checkvalid(int x,int y) {
    if(boardArray[x][y]=="x"||boardArray[x][y]=="o"){
        return 0;
    }
    if(x==0&&y==2) {
        return 1;
    }
    else if(x==1&&y==1){
        return 1;
    }
    else if(x==1&&y==2){
        return 1;
    }
    else if(x==1&&y==3){
        return 1;
    }
    else if(x==2&&y==0){
        return 1;
    }
    else if(x==2&&y==1){
        return 1;
    }
    else if(x==2&&y==2){
        return 1;
    }
    else if(x==2&&y==3){
        return 1;
    }
    else if(x==2&&y==4){
        return 1;
    }

    else return 0;
}

bool X_O_Board::checkvalid_2(int x,int y) {
    if ((x >= 0 && x < ROWS_2 &&
         y >= 0 && y < COLUMNS_2 &&
         (boardArray_2[x][y] != "x" && boardArray_2[x][y] != "o") &&
         (boardArray_2[x + 1][y] == "x" || boardArray_2[x + 1][y] == "o"))
        || (x == ROWS_2-1 && (boardArray_2[x][y] != "x" && boardArray_2[x][y] != "o")))
        return 1;
    else return 0;
}



void X_O_Board::update_board (int x, int y, string mark){
    boardArray[x][y]=mark;
}

void X_O_Board::update_board_2 (int x, int y, string mark){
        boardArray_2[x][y]=mark;
}

bool X_O_Board::update_board_3(int x, int y, string mark) {
    if (!(x < 0 || x >= 5 || y < 0 || y >= 5) &&
        (boardArray_3[x][y] != "X" && boardArray_3[x][y] != "O")) {
        boardArray_3[x][y] = mark;
        n_moves++;
        return true;
    } else {
        return false;
    }
}



void X_O_Board::display_1(){
    cout<<"           "<<boardArray[0][2]<<endl;
    cout<<"     "<<boardArray[1][1]<<" "<<boardArray[1][2]<<" "<<boardArray[1][3]<<" "<<endl;
    cout<<boardArray[2][0]<<" "<<boardArray[2][1]<<" "<<boardArray[2][2]<<" "<<boardArray[2][3]<<" "<<boardArray[2][4]<<endl;
}

void X_O_Board::display_2()  {
    for (int i = 0; i < ROWS_2; ++i) {
        for (int j = 0; j < COLUMNS_2; ++j) {
            cout << boardArray_2[i][j] << ' ';
        }
        cout << endl;
    }
}

void X_O_Board::display_3() const {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {

            cout << boardArray_3[i][j] << " ";
        }
        cout << endl;
    }
}



bool X_O_Board::checkWin(Player* player)  {
    string symbol = player->get_symbol();

    //checking rows
    if(boardArray[1][1]==symbol&&boardArray[1][2]==symbol&&boardArray[1][3]==symbol){
        return true;
    }
    else if(boardArray[2][0]==symbol&&boardArray[2][1]==symbol&&boardArray[2][2]==symbol){
        return true;
    } else if(boardArray[2][1]==symbol&&boardArray[2][2]==symbol&&boardArray[2][3]==symbol){
        return true;
    }
    else if(boardArray[2][2]==symbol&&boardArray[2][3]==symbol&&boardArray[2][4]==symbol){
        return true;
    }

    //checking columns
    if(boardArray[0][2]==symbol&&boardArray[1][2]==symbol&&boardArray[2][2]==symbol){
        return true;
    }

    //check diagonaly_right
    if(boardArray[0][2]==symbol&&boardArray[1][1]==symbol&&boardArray[2][0]==symbol){
        return true;
    }

    //check diagonaly_left
    if(boardArray[0][2]==symbol&&boardArray[1][3]==symbol&&boardArray[2][4]==symbol){
        return true;
    }

    return false;
}

bool X_O_Board::checkWin_2(Player* player)  {
    string symbol = player->get_symbol();

    //checking rows
    for (int r = ROWS_2- 1; r >= 0; --r) {
        int count = 0;
        for (int c = 0; c < COLUMNS_2; ++c) {
            if (boardArray_2[r][c] == symbol) count++;
            else count = 0;
            if (count >= 4) return 1;
        }
    }

    //checking columns
    for (int c = 0; c < COLUMNS_2; ++c) {
        int count = 0;
        for (int r = ROWS_2 - 1; r >= 0; --r) {
            if (boardArray_2[r][c] == symbol) count++;
            else count = 0;
            if (count >= 4) return 1;
        }
    }

    //check diagonaly_right
    for (int r = ROWS_2 - 1; r >= 0; --r) {
        int count = 0;
        for (int c = 0; c < COLUMNS_2; ++c) {
            if (boardArray_2[r][c] == symbol) {
                for (int i = 1; i < 4; ++i) {
                    if (c + i < COLUMNS_2 && r - i >= 0 && boardArray_2[r - i][c + i] == symbol) {
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
    for (int r = ROWS_2 - 1; r >= 0; --r) {
        int count = 0;
        for (int c = 0; c < COLUMNS_2; ++c) {
            if (boardArray_2[r][c] == symbol) {
                for (int i = 1; i < 4; ++i) {
                    if (c - i < COLUMNS_2 && r - i >= 0 && boardArray_2[r - i][c - i] == symbol) {
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

bool X_O_Board::checkWin_3() {
    int player1Count = 0;
    int player2Count = 0;

// Check rows and columns for a winner
    for (int i = 0; i < 5; ++i) {
// Check rows
        for (int j = 0; j < 3; ++j) {
            if (boardArray_3[i][j] == boardArray_3[i][j + 1] && boardArray_3[i][j + 1] == boardArray_3[i][j + 2]
                && (boardArray_3[i][j] != "X" && boardArray_3[i][j] != "O")) {
                (boardArray_3[i][j] == "X") ? ++player1Count : ++player2Count;
            }
        }

// Check columns
        for (int j = 0; j < 3; ++j) {
            if (boardArray_3[j][i] == boardArray_3[j + 1][i] && boardArray_3[j + 1][i] == boardArray_3[j + 2][i]
                && (boardArray_3[i][j] == "X" || boardArray_3[i][j] == "O")) {
                (boardArray_3[j][i] == "X") ? ++player1Count : ++player2Count;
            }
        }
    }

// Check diagonals for a winner
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
// Check main diagonal
            if (boardArray_3[i][j] == boardArray_3[i + 1][j + 1] && boardArray_3[i + 1][j + 1] == boardArray_3[i + 2][j + 2]
                && (boardArray_3[i][j] == "X" || boardArray_3[i][j] == "O")) {
                (boardArray_3[i][j] == "X") ? ++player1Count : ++player2Count;
            }

// Check reverse diagonal
            if (boardArray_3[i][j + 2] == boardArray_3[i + 1][j + 1] && boardArray_3[i + 1][j + 1] == boardArray_3[i + 2][j] &&
                (boardArray_3[i][j + 2] == "X" || boardArray_3[i][j + 2] == "O")) {
                (boardArray_3[i][j + 2] == "X") ? ++player1Count : ++player2Count;
            }
        }
    }

// Check if all cells are filled except one
    bool allCellsFilledExceptOne = true;
    int emptyCellCount = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (boardArray_3[i][j] != "X" && boardArray_3[i][j] != "O") {
                ++emptyCellCount;
                if (emptyCellCount > 1) {
                    allCellsFilledExceptOne = false;
                    break;
                }
            }
        }
        if (!allCellsFilledExceptOne) {
            break;
        }
    }

// Return true if all cells are filled except one and either player has a three-in-a-row
    return (allCellsFilledExceptOne && (player1Count > 0 || player2Count > 0));
}
