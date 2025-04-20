//h
#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <string>
#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe(int size) : pegs(size * size, " ") {}  // Nuevo constructor

    bool game_over();
    void start_game(std::string first_player);
    void mark_board(int position);
    std::string get_player() const { return player; }
    void display_board() const;
    std::string get_winner() const { return winner; }

    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

protected:  // 👈 Para que las clases hijas tengan acceso
    std::vector<std::string> pegs;
    
    virtual bool check_diagonal_win();
    virtual bool check_column_win();
    virtual bool check_row_win();


private:
    void set_next_player();
    bool check_board_full();
    void clear_board();
    void set_winner();

    std::string winner;
    std::string player;
};

#endif
