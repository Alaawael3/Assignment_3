//
// Created by lolow on 12/6/2023.
//

#include "Board.h"

GameManager::GameManager() {
    cout<<"start the game\n";
}

GameManager::GameManager(Board* board, Player* player[])//default constructor
        : board(board) {
    this->player[0]=player[0];
    this->player[1]=player[1];
    currentPlayer=player[0];
}


void GameManager::runGame_1() {
    while (true) {
        board->display_1();
        currentPlayer = player[0];
        cout << "your turn choose a cell...";
        int x,y;
        st1:
        currentPlayer->get_move(x,y,1);
        if (!board->checkvalid(x,y)) goto st1;

        board->update_board(x,y,currentPlayer->get_symbol());

        if (board->checkWin(currentPlayer)) {
            cout << currentPlayer->to_string() << " wins!\n" << std::endl;
            break;
        }
        if (!board->validcells_1()) break;

        currentPlayer = player[1];
        start:
        currentPlayer->get_move(x,y,1);
        if (!board->checkvalid(x,y)) goto start;
        board->display_1();
        board->update_board(x,y,currentPlayer->get_symbol());

        if (board->checkWin(currentPlayer)) {
            board->display_1();
            cout << "computer wins you are loser :)\n" << endl;
            break;
        }
        if (!board->validcells_1()) break;
    }
    cout << "Game over!! \n";
}


void GameManager::runGame_2() {
    while (true) {
        board->display_2();
        currentPlayer = player[0];
        cout << "your turn choose a cell...";
        int x, y;
        st1:
        currentPlayer->get_move(x, y,2);
        if (!board->checkvalid_2(x, y)) goto st1;

        board->update_board_2(x, y, currentPlayer->get_symbol());
        board->display_2();
        if (board->checkWin_2(currentPlayer)) {
            cout << currentPlayer->to_string() << " wins!\n" << std::endl;
            break;
        }
        if (!board->validcells_2()) break;

        currentPlayer = player[1];
        start:
        currentPlayer->get_move(x, y,2);
        if (!board->checkvalid_2(x, y)) goto start;
        board->display_2();
        board->update_board_2(x, y, currentPlayer->get_symbol());

        if (board->checkWin_2(currentPlayer)) {
            cout << "computer wins you are loser :)\n" << endl;
            break;
        }
        if (!board->validcells_2()) break;
    }
    cout << "Game over!! \n";
}


void GameManager::runGame_3(){
    int x, y;

    board->display_3();

    while (!board->game_is_over()) {
        for (int i = 0; i < 2; ++i) {
            player[i]->get_move(x, y,3);
            while (!board->update_board_3(x, y, player[i]->get_symbol())) {
                player[i]->get_move(x, y,3);
            }
            board->display_3();
            if (board->checkWin_3()) {
                cout << player[i]->to_string() << " wins\n";
                return;
            }

        }
    }
}