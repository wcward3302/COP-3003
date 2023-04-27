#include <vector>
#include <iostream>



class Tik_Tak_Toe {
public:

    std::array < std::array <char, 3>, 3> board;


    Tik_Tak_Toe() = default;

    void display_board();
    bool did_win();

};


int main(){

    Tik_Tak_Toe game = Tik_Tak_Toe();
    std::string input;

    while(!game.did_win()){
        std::cout << "Which space do you want (Please enter format 11 = 1,1): ";
        std::getline(std::cin, input);

        game.board[int(input[0]), int(input[1])];

        game.display_board();


    }
}



void Tik_Tak_Toe::display_board(){
    for (const auto & rows : board){

        for (const auto & column : rows){

            std::cout << column << ' ';
        }
        std::cout << '\n';
    }
}
bool Tik_Tak_Toe::did_win(){

}