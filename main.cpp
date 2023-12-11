#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

class Board {
public:
    virtual bool update_board(int x, int y, char symbol) = 0;
    virtual bool is_winner() const = 0;
    virtual bool is_draw() const = 0;
    virtual void display_board() const = 0;
    virtual bool game_is_over() const = 0;
    virtual ~Board() {}
};

class X_O_Board : public Board {
private:
    int n_rows, n_cols;
    char** board;
    int n_moves;

public:
    X_O_Board();
    ~X_O_Board();
    bool update_board(int x, int y, char mark);
    void display_board() const;
    bool is_winner() const;
    bool is_draw() const;
    bool game_is_over() const;
};

class Player {
protected:
    string name;
    char symbol;

public:
    Player(int order,char symbol);
    Player(char symbol);
    virtual ~Player() {}
    virtual void get_move(int& x, int& y) const;
    string to_string() const;
    char get_symbol() const;
};

class RandomPlayer : public Player {
protected:
    int dimension;
public:
    RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y) const override;
};

class GameManager {
private:
    Board* boardPtr;
    Player* players[2];

public:
    GameManager(Board* bPtr, Player* playerPtr[2]);
    void run();
};

// Implementations

X_O_Board::X_O_Board() : n_rows(5), n_cols(5), n_moves(0) {
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j)
            board[i][j] = ' ';
    }
}

X_O_Board::~X_O_Board() {
    for (int i = 0; i < n_rows; ++i) {
        delete[] board[i];
    }
    delete[] board;
}

bool X_O_Board::update_board(int x, int y, char mark) {
    if (!(x < 0 || x >= n_rows || y < 0 || y >= n_cols) && (board[x][y] == ' ')) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else {
        return false;
    }
}

void X_O_Board::display_board() const {
    for (int i = 0; i < n_rows; ++i) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; ++j) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool X_O_Board::is_winner() const {
    int player1Count = 0;
    int player2Count = 0;

    // Check rows and columns for a winner
    for (int i = 0; i < 5; ++i) {
        // Check rows
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ') {
                (board[i][j] == 'X') ? ++player1Count : ++player2Count;
            }
        }

        // Check columns
        for (int j = 0; j < 3; ++j) {
            if (board[j][i] == board[j + 1][i] && board[j + 1][i] == board[j + 2][i] && board[j][i] != ' ') {
                (board[j][i] == 'X') ? ++player1Count : ++player2Count;
            }
        }
    }

    // Check diagonals for a winner
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // Check main diagonal
            if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != ' ') {
                (board[i][j] == 'X') ? ++player1Count : ++player2Count;
            }

            // Check reverse diagonal
            if (board[i][j + 2] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j] && board[i][j + 2] != ' ') {
                (board[i][j + 2] == 'X') ? ++player1Count : ++player2Count;
            }
        }
    }

    // Check if all cells are filled except one
    bool allCellsFilledExceptOne = true;
    int emptyCellCount = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (board[i][j] == ' ') {
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




bool X_O_Board::is_draw() const {
    return (n_moves == 24 && !is_winner());
}

bool X_O_Board::game_is_over() const {
    return n_moves >= 24;
}
Player::Player(char symbol) {
    this->symbol = symbol;
}
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move(int& x, int& y) const {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces: ";
    cin >> x >> y;
}

string Player::to_string() const {
    return "Player: " + name;
}

char Player::get_symbol() const {
    return symbol;
}

RandomPlayer::RandomPlayer(char symbol,int dimension) : Player(symbol) {
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;}

void RandomPlayer::get_move(int& x, int& y) const {
    x = (int) (rand() / (RAND_MAX + 1.0) * 5);
    y = (int) (rand() / (RAND_MAX + 1.0) * 5);
}

GameManager::GameManager(Board* bPtr, Player* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i = 0; i < 2; ++i) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()) {
                cout << players[i]->to_string() << " wins\n";
                return;
            }


            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();

    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

    return 0;
}




