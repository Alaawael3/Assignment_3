#include <bits/stdc++.h>
#include "Xo_board.h"
#include "Player.h"
#include "Random_player.h"
#include "GameManager.h"

using namespace std;

int main() {
    int choice;
    Player *player[2];
    player[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;

    if (choice != 1)
        player[1] = new Player(2, 'o');
    else
        // Player pointer points to child
        player[1] = new Random_player('o', 3);  // Pass an integer parameter for Random_player

    X_O_Board *board = new X_O_Board;
    GameManager x_o_game(board, player);
    x_o_game.runGame();

    // Deallocate memory
    delete player[0];
    delete player[1];
    delete board;

    // Optional: Pause the console
    system("pause");
}
