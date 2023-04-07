#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "classes.cpp"


bool collision_detect (float, float, float, float, float, float, float, float);

int main (){

    // will use time to seed random generator for random wall heights
    srand(time(0));


    // create window with size of 1000 by 600, set framerate limit to 60fps, 
    sf::RenderWindow window (sf::VideoMode(2000, 1600), "Test");
    window.setFramerateLimit(60);


    // load exploding sound into buffer
    sf::SoundBuffer explode_buffer;
    sf::Sound explode;
    explode_buffer.loadFromFile("./Audio/explosion_x.wav");
    explode.setBuffer(explode_buffer);


    // struct to hold textures for rendering, can just do sprite.settexture(texture.)
    struct Textures {
        sf::Texture ship[2]; // make ship have 2 textures, one for alive and one for dead
        sf::Texture wall;
        sf::Texture background;
    } textures;
    

    // load all images into members of Textures struct
    textures.ship[0].loadFromFile("./Images/ship.png");
    textures.ship[1].loadFromFile("./Images/explosion.png");
    textures.wall.loadFromFile("./Images/walls.png");
    textures.background.loadFromFile("./Images/deathstar_surface.jpeg");


    // create ship instance, set intial position (1/4 hori, 1/2 vert)
    Ship ship = Ship();
    ship.sprite.setPosition(250, 300);


    // create a vector for the walls, so we can add and delete easily
    std::vector <sf::Sprite> walls;


    // create Game class instance and update
    Game game = Game();
    game.background.setTexture(textures.background);
    game.font.loadFromFile("./Fonts/Menlo-Regular.ttf");

    game.score_text.setFont(game.font);
    game.score_text.setFillColor(sf::Color::White);
    game.score_text.setCharacterSize(50);
    game.score_text.setPosition(30, 30);

    game.high_score_text.setFont(game.font);
    game.high_score_text.setFillColor(sf::Color::White);
    game.high_score_text.setCharacterSize(50);
    game.high_score_text.setPosition(30, 90);


    // will loop so long as window is open. Handle rendering and movement here
    while(window.isOpen()) {


        // load ship sprite with initial texture
        ship.sprite.setTexture(textures.ship[0]);


        // load texts with current score and high score, but need to to_string them to load
        game.score_text.setString(std::to_string(game.score));
        game.high_score_text.setString(std::to_string(game.high_score));



        // track ship current position
        ship.x = ship.sprite.getPosition().x;
        ship.y = ship.sprite.getPosition().y;
        ship.width = ship.sprite.getScale().x;
        ship.height = ship.sprite.getScale().y;
        


        // generate a new set of walls every 150 frames
        if (game.frames % 150 == 0){
            // use random generator for heights but restrict them to be 2x ship height apart. 
            int random_height = rand();
            int gap = ship.sprite.getScale().y * 2;

            sf::Sprite wall_lower;
            wall_lower.setTexture(textures.wall);
            wall_lower.setPosition(1000, random_height + gap);
            wall_lower.setScale(0.5, 0.5);

            sf::Sprite wall_upper;
            wall_upper.setTexture(textures.wall);
            wall_upper.setPosition(1000, random_height);
            wall_upper.setScale(0.5, 0.5);


            std::cout << "wall gen\n";
            walls.push_back(wall_lower);
            walls.push_back(wall_upper);
            
        }

        // check for keypresses to update ship position or restart
        sf::Event event;
        while (window.pollEvent(event)){
            

            if (event.type == sf::Event::Closed){
                window.close();
            }


            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                
            }

            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                
            }

            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                
            }
        }
    
    }


}


// function to check for collision between 2 objects, given their x, y, width, height
bool collision_detect (float x_coord_1, float y_coord_1, float width_1, float height_1, float x_coord_2, float y_coord_2, float width_2, float height_2) {
	if (x_coord_1 + width_1 >= x_coord_2 && x_coord_1 <= x_coord_2 + width_2 && y_coord_1 + height_1 >= y_coord_2 && y_coord_1 <= y_coord_2 + height_2) {
		return true;
	}
	return false;
}