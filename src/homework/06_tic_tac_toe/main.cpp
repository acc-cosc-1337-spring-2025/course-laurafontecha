#include "tic_tac_toe.h"
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    TicTacToe game;
    string first_player;
    char choice;

    do
    {
        cout << "Enter First player (X or O): ";
        cin >> first_player;

        game.start_game(first_player);
        int position;

        while (!game.game_over())
        {
            cout << "Enter a position (1-9): ";
            cin >> position;
            game.mark_board(position);
            game.display_board();
        }

        cout << "Game Over! ";
        if (game.get_winner() == "C") {
            cout << "It's a tie.\n";
        } else {
            cout << "Winner is: " << game.get_winner() << "\n";
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return 0;
}