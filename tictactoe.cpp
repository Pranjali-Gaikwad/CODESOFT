/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

void displayBoard(const std::vector<char>& board) {
    std::cout << " " << board[0] << " | " << board[1] << " | " << board[2] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[3] << " | " << board[4] << " | " << board[5] << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << " " << board[6] << " | " << board[7] << " | " << board[8] << std::endl;
}

bool checkWin(const std::vector<char>& board, char player) {
    const int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };
    
    for (const auto& pattern : winPatterns) {
        if (board[pattern[0]] == player && board[pattern[1]] == player && board[pattern[2]] == player) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const std::vector<char>& board) {
    for (const char& cell : board) {
        if (cell != 'X' && cell != 'O') {
            return false;
        }
    }
    return true;
}

int main() {
    char playAgain = 'y';
    
    while (playAgain == 'y' || playAgain == 'Y') {
        std::vector<char> board(9, ' ');
        char currentPlayer = 'X';
        bool gameWon = false;
        bool gameDraw = false;

        std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

        while (!gameWon && !gameDraw) {
            displayBoard(board);

            int move;
            std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            std::cin >> move;
            move--;

            if (move < 0 || move >= 9 || board[move] != ' ') {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }

            board[move] = currentPlayer;
            gameWon = checkWin(board, currentPlayer);
            gameDraw = checkDraw(board);

            if (!gameWon) {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        displayBoard(board);

        if (gameWon) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
        } else if (gameDraw) {
            std::cout << "The game is a draw!" << std::endl;
        }

        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
    }

    std::cout << "Thank you for playing Tic-Tac-Toe! Goodbye!" << std::endl;
    return 0;
}
