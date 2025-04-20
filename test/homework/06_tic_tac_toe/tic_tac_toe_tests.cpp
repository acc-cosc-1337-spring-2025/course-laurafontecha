#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test first player set to X") {
    TicTacToe3 game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
    TicTacToe3 game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected - tie") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(4); REQUIRE(game.game_over() == false);
    game.mark_board(6); REQUIRE(game.game_over() == false);
    game.mark_board(8); REQUIRE(game.game_over() == false);
    game.mark_board(7); REQUIRE(game.game_over() == false);
    game.mark_board(9); REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(4); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(7); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second column") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == false);
    game.mark_board(8); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third column") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(3); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(6); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(9); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first row") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(4); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second row") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(4); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(6); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third row") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(7); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(8); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(9); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from top left") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == false);
    game.mark_board(9); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(7); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test get_winner() returns X after win") {
    TicTacToe3 game;
    game.start_game("X");
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(4); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == true);
    REQUIRE(game.get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager get_winner_total function") {
    TicTacToeManager manager;

    std::unique_ptr<TicTacToe> game1 = std::make_unique<TicTacToe3>();
    game1->start_game("X");
    game1->mark_board(1);
    game1->mark_board(4);
    game1->mark_board(2);
    game1->mark_board(5);
    game1->mark_board(3);
    REQUIRE(game1->game_over() == true);
    REQUIRE(game1->get_winner() == "X");
    manager.save_game(game1);

    std::unique_ptr<TicTacToe> game2 = std::make_unique<TicTacToe3>();
    game2->start_game("O");
    game2->mark_board(1);
    game2->mark_board(2);
    game2->mark_board(4);
    game2->mark_board(5);
    game2->mark_board(7);
    REQUIRE(game2->game_over() == true);
    REQUIRE(game2->get_winner() == "O");
    manager.save_game(game2);

    std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe3>();
    game3->start_game("X");
    game3->mark_board(1);
    game3->mark_board(2);
    game3->mark_board(3);
    game3->mark_board(5);
    game3->mark_board(4);
    game3->mark_board(6);
    game3->mark_board(8);
    game3->mark_board(7);
    game3->mark_board(9);
    REQUIRE(game3->game_over() == true);
    REQUIRE(game3->get_winner() == "C");
    manager.save_game(game3);

    int x_win, o_win, ties;
    manager.get_winner_total(o_win, x_win, ties);
    REQUIRE(x_win == 1);
    REQUIRE(o_win == 1);
    REQUIRE(ties == 1);
}
