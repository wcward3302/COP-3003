#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

// class for ship, holds basic information about ship position and size
class Ship {

public:
    double velocity;
    double x;
    double y;
    double height;
    double width;

    sf::Sprite sprite;
    sf::Sprite dead_sprite;

    Ship()=default;

    void update(){
        if (velocity == 1){
            sprite.move(0,-15);
        }
        else if (velocity == 2){
            sprite.move(0,15);
        }
        else{
            sprite.move(0,0);
        }
    }

    bool collision_detect (float x_coord_1, float y_coord_1, float width_1, float height_1, float x_coord_2, float y_coord_2, float width_2, float height_2) {
        if (x_coord_1 + width_1 >= x_coord_2 && x_coord_1 <= x_coord_2 + width_2 && y_coord_1 + height_1 >= y_coord_2 && y_coord_1 <= y_coord_2 + height_2) {
            return true;
        }
        return false;
    }
};


// game class holds information about game instance, like the score and high score, as well as a frame counter variable
class Game {

public:
    int score_text;
    int high_score_text;
    int frames;
    std::string enter_message_text = "Welcome!\nMay the mass x acceleration be with you...";
    std::string instruct_text = "Use arrow keys to move up and down, esc to restart";
    
    int game_state; // 0 is running, 1 is stopped

    sf::Sprite background;
    sf::Text score;
    sf::Text high_score;
    sf::Text enter_message;
    sf::Text instruct;
    sf::Font font;

    Game()=default;

    // function to set current high score from file
    void get_high_score(){

        std::fstream score_file;
        score_file.open("high_scores.txt");

        if (score_file.is_open()){

            std::string line;

            // copy content of text file to lines class member
            while (std::getline(score_file, line)){
                high_score_text = std::stoi(line);
            }

            // if we made it here then the file was opened, so now close
            score_file.close();
        }   
        else{
            std::cout << "did not open\n";
        }
    }

    // Write high score to file. Will not make any real change unless high score changes
    void set_high_score(){

        std::fstream score_file;
        score_file.open("./high_scores.txt");

        if (score_file.is_open()){

            score_file << high_score_text;

            score_file.close();
        }
        else{
            std::cout << "did not open\n";
        }
    }
};