// ConsoleTicTacToe.cpp : First attempt at Tic Tac Toe game through use of console

#include <iostream>
#include <stdlib.h>

using namespace std;

// Board Array
char tttBoard[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char playerTurn = 'X';

int choice;
int row;
int col;

bool isDraw = false;

// Game Board Layout
void DisplayBoard() {
    
    cout << "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << tttBoard[0][0] << "  |  " << tttBoard[0][1] << "  |  " << tttBoard[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << tttBoard[1][0] << "  |  " << tttBoard[1][1] << "  |  " << tttBoard[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << tttBoard[2][0] << "  |  " << tttBoard[2][1] << "  |  " << tttBoard[2][2] << " \n";
    cout << "\t\t     |     |     \n";
}

// player input
void PlayerTurn() {
    if (playerTurn == 'X') {
        cout << "\n\tPlayer - 1 [X] turn: ";

    }
    else if (playerTurn == 'O') {
        cout << "\n\tPlayer - 2 [O] turn: ";
    }

    cin >> choice;

    // Update Rows and Columns
    switch (choice) {
        case 1:
            row = 0;
            col = 0;
            break;
        case 2:
            row = 0;
            col = 1;
            break;
        case 3:
            row = 0;
            col = 2;
            break;
        case 4:
            row = 1;
            col = 0;
            break;
        case 5:
            row = 1;
            col = 1;
            break;
        case 6:
            row = 1;
            col = 2;
            break;
        case 7:
            row = 2;
            col = 0;
            break;
        case 8:
            row = 2;
            col = 1;
            break;
        case 9:
            row = 2;
            col = 2;
            break;
        default:
            cout << "Invalid Move";
    }

    // Update position for 'X'
    if (playerTurn == 'X' && tttBoard[row][col] != 'X' && tttBoard[row][col] != 'O') {
        tttBoard[row][col] = 'X';
        playerTurn = 'O';
    }
    // Update position for 'O'
    else if (playerTurn == 'O' && tttBoard[row][col] != 'X' && tttBoard[row][col] != 'O') {
        tttBoard[row][col] = 'O';
        playerTurn = 'X';
    }
    // Error if square already taken
    else {
        cout << "That square has already been taken!n Please choose a different square!\n\n";
        PlayerTurn();
    }

    DisplayBoard();
}

// 
bool GameOver() {
    // Check up/down/left/right win
    for (int i = 0; i < 3; i++) {
        if (tttBoard[i][0] == tttBoard[i][1] && tttBoard[i][0] == tttBoard[i][2] || tttBoard[0][i] == tttBoard[1][i] && tttBoard[0][i] == tttBoard[2][i]) {
            return false;
        }
    }

    // Check Diagonal Win
    if (tttBoard[0][0] == tttBoard[1][1] && tttBoard[0][0] == tttBoard[2][2] || tttBoard[0][2] == tttBoard[1][1] && tttBoard[0][2] == tttBoard[2][0]) {
        return false;
    }

    // check if game is ongoing
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tttBoard[i][j] != 'X' && tttBoard[i][j] != 'O') {
                return true;
            }
        }
    }

    isDraw = true;

    return false;

}

int main() {
    cout << "\t\t\t===Tic Tac Toe===\t\t\t";
    cout << "\n\t\t\t===PvP===\n\t\t\t";

    while (GameOver()) {
        DisplayBoard();
        PlayerTurn();
        GameOver();
    }

    if (playerTurn == 'X' && isDraw == false) {
        cout << "\n\nCongrats Player O! You have won the game!";
    }
    else if (playerTurn == 'O' && isDraw == false) {
        cout << "\n\nCongrats Player X! You have won the game!";
    }
    else {
        cout << "\n\nDraw!\n\n";
    }
}