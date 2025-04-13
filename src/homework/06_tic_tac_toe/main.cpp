#include <iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

int main()
{
    TicTacToeManager manager;
    std::string first_player;
    char choice;

    do
    {
        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;

        TicTacToe game;
        game.start_game(first_player);

        int position;
        while (!game.game_over())
        {
            std::cout << game;  // << overloaded output operator (you will implement this later)
            std::cout << "Enter position (1-9): ";
            std::cin >> position;

            game.mark_board(position);
        }

        std::cout << game;
        std::cout << "Game over! Winner: " << game.get_winner() << "\n";
        manager.save_game(game);

        int x, o, t;
        manager.get_winner_total(o, x, t);
        std::cout << "Score - X wins: " << x << ", O wins: " << o << ", Ties: " << t << "\n";

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
