//
// Created by lolow on 12/6/2023.
//

#include "X_O Board.h"

GameManager::GameManager() {
    cout<<"start the game\n";
}
GameManager::GameManager(Board* board, Player* player[])//default constructor
        : board(board) {
    this->player[0]=player[0];
    this->player[1]=player[1];
    currentPlayer=player[0];
}



void GameManager::runGame() {
    while (true) {
        board->display();
        currentPlayer = player[0];
        cout << "your turn choose a cell...";
        int x,y;
        st1:
        currentPlayer->get_move(x,y);
        if (!board->checkvalid(x,y)) goto st1;

        board->update_board(x,y,currentPlayer->get_symbol());

        if (board->checkWin(currentPlayer)) {
            cout << currentPlayer->to_string() << " wins!\n" << std::endl;
            break;
        }
        if (!board->validcells()) break;

        currentPlayer = player[1];
        start:
        currentPlayer->get_move(x,y);
        if (!board->checkvalid(x,y)) goto start;
        board->display();
        board->update_board(x,y,currentPlayer->get_symbol());

        if (board->checkWin(currentPlayer)) {
            board->display();
            cout << "computer wins you are loser :)\n" << endl;
            break;
        }
        if (!board->validcells()) break;
    }
    cout << "Game over!! \n";
}
