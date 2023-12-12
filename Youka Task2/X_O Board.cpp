//
// Created by lolow on 12/6/2023.
//
#include "X_O Board.h"
#include <iostream>

string Board::boardArray[ROWS][COLUMNS];

X_O_Board::X_O_Board() {
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
            boardArray[i][j] =s1;
        }
    }
}//default constructor

bool X_O_Board:: validcells(){
    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLUMNS; ++c) {
            if (boardArray[r][c]!="  x "||boardArray[r][c]!="  o ") return 1;
        }
    }
    return 0;
}

bool X_O_Board::checkvalid(int x,int y) {
    if(boardArray[x][y]=="  x "||boardArray[x][y]=="  o "){
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

void X_O_Board::update_board (int x, int y, string mark){
    boardArray[x][y]=mark;
    n_moves++;
}
bool Board::is_draw(Player *player) {
    if(n_moves==9&& !checkWin(player)){
        cout<<"DRAW"<<endl;
        return true;
    }
    else{
        return false;
    }

}

void X_O_Board::display()  {
   cout<<"            "<<boardArray[0][2]<<endl;
   cout<<"      "<<boardArray[1][1]<<" "<<boardArray[1][2]<<" "<<boardArray[1][3]<<" "<<endl;
   cout<<boardArray[2][0]<<" "<<boardArray[2][1]<<" "<<boardArray[2][2]<<" "<<boardArray[2][3]<<" "<<boardArray[2][4]<<endl;
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
