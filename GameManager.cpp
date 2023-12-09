//
// Created by lolow on 12/6/2023.
//

#include "GameManager.h"

GameManager::GameManager() {
    cout<<"start the game\n";
}
GameManager::GameManager(X_O_Board* board, Player* player[])//default constructor
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
         currentPlayer->get_move(x,y);
         board->update_board(x,y,currentPlayer->get_symbol());

        if (board->checkWin(currentPlayer)) {
            cout << currentPlayer->to_string() << " wins!\n" << std::endl;
            break;
        }

        currentPlayer = player[1];
        currentPlayer->get_move(x,y);
        board->update_board(x,y,currentPlayer->get_symbol());

        if (board->checkWin(currentPlayer)) {
            cout << "computer wins you are loser :)\n" << endl;
            break;
        }
        if (board->validcells()) break;
    }
    cout << "Game over!! \n";
}

