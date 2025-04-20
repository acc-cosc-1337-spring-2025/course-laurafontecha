#include <iostream>
#include <memory>
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

int main()
{
    TicTacToeManager manager;
    std::string first_player;
    char choice;

    do
    {
        int game_type;
        std::cout << "Play TicTacToe 3 (3x3) or 4 (4x4)? Enter 3 or 4: ";
        std::cin >> game_type;

        std::unique_ptr<TicTacToe> game;

        if (game_type == 3)
        {
            game = std::make_unique<TicTacToe3>();
        }
        else if (game_type == 4)
        {
            game = std::make_unique<TicTacToe4>();
        }
        else
        {
            std::cout << "Invalid choice. Exiting.\n";
            return 1;
        }

        std::cout << "Enter first player (X or O): ";
        std::cin >> first_player;
        game->start_game(first_player);

        int position;
        while (!game->game_over())
        {
            std::cout << *game; 
            std::cout << "Enter position: ";
            std::cin >> position;
            game->mark_board(position);
        }

        std::cout << *game;
        std::cout << "Game over! Winner: " << game->get_winner() << "\n";

        manager.save_game(game);

        int x, o, t;
        manager.get_winner_total(o, x, t);
        std::cout << "Score - X wins: " << x << ", O wins: " << o << ", Ties: " << t << "\n";

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    return 0;
}
