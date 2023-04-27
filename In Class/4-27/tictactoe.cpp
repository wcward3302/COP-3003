#include "tictactoe.hpp"

void TicTacToe::display_board(){
    for (const auto & rows : board){

        for (const auto & column : rows){

            std::cout << column << ' ';
        }
        std::cout << '\n';
    }
}

bool TicTacToe::did_win(){
    
}
