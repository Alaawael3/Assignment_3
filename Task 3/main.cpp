#include <bits/stdc++.h>
#include"Board.h"
using namespace std;

int main() {
    int choice;
    Player *player[2];

    cout<<"choose the game:\n"
          "1- Pyramic Tic-Tac-Toe\n"
          "2- Four-in-a-row\n"
          "3- 5 x 5 Tic Tac Toe \n";
    cin >> choice;
    if (choice==1){
        player[0] = new Player(1,"  X ");
        cout << "Welcome to FCAI X-O Game. :)\n";
        cout<<"enter 1 if you wanna play against pc 2 if you want another player\n";
        cin>>choice;
        if (choice != 1)
            player[1] = new Player(2,"  O ");
        else
            player[1] = new Random_Player("  O ", 3);  // Pass an integer parameter for Random_player

        X_O_Board *board = new X_O_Board;
        GameManager x_o_game(board, player);
        x_o_game.runGame_1();
        delete player[0];
        delete player[1];
        delete board;
    }
    else if (choice==2) {
        player[0] = new Player(1, "X");
        cout << "Welcome to FCAI X-O Game. :)\n";
        cout<<"enter 1 if you wanna play against pc 2 if you want another player\n";
        cin>>choice;
        if (choice != 1)
            player[1] = new Player(2, "O");
        else
            player[1] = new Random_Player("O", 3);  // Pass an integer parameter for Random_player

        X_O_Board *board = new X_O_Board;
        GameManager x_o_game(board, player);
        x_o_game.runGame_2();
        delete player[0];
        delete player[1];
        delete board;
    }
    else {
        player[0] = new Player(1, "X");
        cout << "Welcome to FCAI X-O Game. :)\n";
        cout<<"enter 1 if you wanna play against pc 2 if you want another player\n";
        cin>>choice;
        if (choice != 1)
            player[1] = new Player(2, "O");
        else
            player[1] = new Random_Player("O", 3);  // Pass an integer parameter for Random_player

        X_O_Board *board = new X_O_Board;
        GameManager x_o_game(board, player);
        x_o_game.runGame_3();
        delete player[0];
        delete player[1];
        delete board;
    }
}
