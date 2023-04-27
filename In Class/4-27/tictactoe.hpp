#ifndef TIC_TAC_TOE_HPP
#define TIC_TAC_TOE_HPP

#include <iostream>

class TicTacToe {

public:

    char turn;
    std::array < std::array <char, 3>, 3> board;

    TicTacToe() = default;

    void display_board();
    void turn();
    bool did_win();
};



#endif