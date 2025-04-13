#define CATCH_CONFIG_MAIN 
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("Test first player set to X") {
    TicTacToe game;
    game.start_game("X");
    REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
    TicTacToe game;
    game.start_game("O");
    REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected - tie") {
    TicTacToe game;
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
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(4); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(7); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == false);
    game.mark_board(8); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third column") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(3); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(6); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(9); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(4); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == true);
}


TEST_CASE("Test win by second row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(4); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(6); REQUIRE(game.game_over() == true);
}


TEST_CASE("Test win by third row") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(8); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(9); REQUIRE(game.game_over() == true);
}


TEST_CASE("Test win diagonally from top left") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == false);
    game.mark_board(9); REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win diagonally from bottom left") {
    TicTacToe game;
    game.start_game("X");
    game.mark_board(7); REQUIRE(game.game_over() == false);
    game.mark_board(1); REQUIRE(game.game_over() == false);
    game.mark_board(5); REQUIRE(game.game_over() == false);
    game.mark_board(2); REQUIRE(game.game_over() == false);
    game.mark_board(3); REQUIRE(game.game_over() == true);
}


TEST_CASE("Test get_winner() returns X after win") {
    TicTacToe game;
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

    
    TicTacToe game1;
    game1.start_game("X");
    game1.mark_board(1); REQUIRE(game1.game_over() == false);
    game1.mark_board(4); REQUIRE(game1.game_over() == false);
    game1.mark_board(2); REQUIRE(game1.game_over() == false);
    game1.mark_board(5); REQUIRE(game1.game_over() == false);
    game1.mark_board(3); REQUIRE(game1.game_over() == true);
    REQUIRE(game1.get_winner() == "X");
    manager.save_game(game1);

    TicTacToe game2;
    game2.start_game("O");
    game2.mark_board(1); REQUIRE(game2.game_over() == false); // O
    game2.mark_board(2); REQUIRE(game2.game_over() == false); // X
    game2.mark_board(4); REQUIRE(game2.game_over() == false); // O
    game2.mark_board(5); REQUIRE(game2.game_over() == false); // X
    game2.mark_board(7); REQUIRE(game2.game_over() == true);  // O gana
    REQUIRE(game2.get_winner() == "O");
    manager.save_game(game2);
    
    TicTacToe game3;
    game3.start_game("X");
    game3.mark_board(1); REQUIRE(game3.game_over() == false);
    game3.mark_board(2); REQUIRE(game3.game_over() == false);
    game3.mark_board(3); REQUIRE(game3.game_over() == false);
    game3.mark_board(5); REQUIRE(game3.game_over() == false);
    game3.mark_board(4); REQUIRE(game3.game_over() == false);
    game3.mark_board(6); REQUIRE(game3.game_over() == false);
    game3.mark_board(8); REQUIRE(game3.game_over() == false);
    game3.mark_board(7); REQUIRE(game3.game_over() == false);
    game3.mark_board(9); REQUIRE(game3.game_over() == true);
    REQUIRE(game3.get_winner() == "C");
    manager.save_game(game3);

    int x_win, o_win, ties;
    manager.get_winner_total(o_win, x_win, ties);
    REQUIRE(x_win == 1);
    REQUIRE(o_win == 1);
    REQUIRE(ties == 1);

}
