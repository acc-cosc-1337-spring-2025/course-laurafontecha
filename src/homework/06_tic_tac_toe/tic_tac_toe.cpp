#include "tic_tac_toe.h"
#include <iostream>

using std::cout;

bool TicTacToe::game_over() {
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        set_winner();
        return true;
    } else if (check_board_full()) {
        winner = "C"; // C = Tie
        return true;
    }
    return false;
}

void TicTacToe::start_game(std::string first_player) {
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position) {
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board() const {
    for (std::size_t i = 0; i < pegs.size(); i += 3) {
        cout << pegs[i] << "|" << pegs[i + 1] << "|" << pegs[i + 2] << "\n";
    }
}

// -------------------- PRIVATE METHODS --------------------

void TicTacToe::clear_board() {
    for (auto& peg : pegs) {
        peg = " ";
    }
}

void TicTacToe::set_next_player() {
    player = (player == "X") ? "O" : "X";
}

bool TicTacToe::check_board_full() {
    for (const auto& peg : pegs) {
        if (peg == " ") {
            return false;
        }
    }
    return true;
}

// Virtual functions to be overridden in derived classes
bool TicTacToe::check_column_win() { return false; }
bool TicTacToe::check_row_win() { return false; }
bool TicTacToe::check_diagonal_win() { return false; }

void TicTacToe::set_winner() {
    winner = (player == "X") ? "O" : "X";
}

// -------------------- FRIEND OPERATORS --------------------

std::ostream& operator<<(std::ostream& out, const TicTacToe& game) {
    for (std::size_t i = 0; i < game.pegs.size(); ++i) {
        out << game.pegs[i];
        if ((i + 1) % 3 == 0)
            out << "\n";
        else
            out << " | ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, TicTacToe& game) {
    int position;
    std::cout << "Enter position (1-9): ";
    in >> position;
    game.mark_board(position);
    return in;
}
