#include "tic_tac_toe_4.h"

TicTacToe4::TicTacToe4() : TicTacToe(4) {}

bool TicTacToe4::check_column_win() {
    for (int col = 0; col < 4; ++col) {
        if (pegs[col] != " " && pegs[col] == pegs[col + 4] && pegs[col] == pegs[col + 8] && pegs[col] == pegs[col + 12]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_row_win() {
    for (int row = 0; row < 16; row += 4) {
        if (pegs[row] != " " && pegs[row] == pegs[row + 1] && pegs[row] == pegs[row + 2] && pegs[row] == pegs[row + 3]) {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_diagonal_win() {
    return (pegs[0] != " " && pegs[0] == pegs[5] && pegs[0] == pegs[10] && pegs[0] == pegs[15]) ||
           (pegs[3] != " " && pegs[3] == pegs[6] && pegs[3] == pegs[9] && pegs[3] == pegs[12]);
}
