#include <iostream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <SFML/Graphics/RectangleShape.hpp>

#include "classes.cpp"

int main(){


    std::string file_path = std::filesystem::current_path();
    std::string background = file_path + "/Images/deathstar_surface.jpeg";
    

    sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML Project Testing Application");
    window.setVerticalSyncEnabled(true);

    // background
    sf::Texture background_texture;
    background_texture.loadFromFile(background);
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);

    SHIP ship;
    WALLS wall;

    sf::CircleShape shape;
    shape.setRadius(20.f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(window.getSize().x / 2, window.getSize().y / 3);


    sf::Texture ship_texture;
    ship_texture.loadFromFile(ship.sprite);
    sf::Texture ship_explode;
    ship_explode.loadFromFile(ship.dead_sprite);
    std::cout << ship.dead_sprite;
    sf::Sprite ship_sprite;
    ship_sprite.setTexture(ship_texture);

    ship_sprite.setPosition(window.getSize().x / 8, window.getSize().y / 2);

    // set ship width and height for collision
    ship.alive = true;
    ship.width = ship_sprite.getLocalBounds().width;
    ship.height = ship_sprite.getLocalBounds().height;

    sf::RectangleShape border;
    sf::Vector2f border_size (ship_texture.getSize().x + 10, ship_texture.getSize().y + 10);
    border.setSize(border_size);
    border.setFillColor(sf::Color::Red);
    


    sf::Texture wall_texture;
    wall_texture.loadFromFile(wall.sprite);
    sf::Sprite wall_sprite;
    wall_sprite.setTexture(wall_texture);
    wall_sprite.setPosition(window.getSize().x / 2, window.getSize().y / 3);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)){
            // once window is closed, exit all while loops
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // attemp to change sprite texture to make ship explode. Needs work to make functional.
        if(ship.alive){
            ship_sprite.setTexture(ship_texture);
        }
        else{
            ship_sprite.setTexture(ship_explode);
        }

        // draw all items to the screen
        window.clear();
        window.draw(background_sprite);
        window.draw(wall_sprite);
        window.draw(shape);
        window.draw(border);
        window.draw(ship_sprite);
        window.display();


        // draw items on window

        // All code here will be turned into a function!!!
        // use keyboard input to move shape around screen
        
        // if press Up arrow
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            window.setTitle("Moving Up");
            ship_sprite.move(0.f, -5.f);
            border.setPosition(ship_sprite.getPosition().x -5, ship_sprite.getPosition().y -5);
        }
        
        // if press Down arrow
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            window.setTitle("Moving Down");
            ship_sprite.move(0.f, 5.f);
            border.setPosition(ship_sprite.getPosition().x-5, ship_sprite.getPosition().y-5);
        }
        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            window.setTitle("Moving Down");
            ship_sprite.move(-5.f, 0.f);
            border.setPosition(ship_sprite.getPosition().x-5, ship_sprite.getPosition().y-5);
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            window.setTitle("Moving Down");
            ship_sprite.move(5.f, 0.f);
            border.setPosition(ship_sprite.getPosition().x-5, ship_sprite.getPosition().y-5);
        }


        // if press Space
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            ship_sprite.setPosition(window.getSize().x/2, window.getSize().y/2);
            border.setPosition(ship_sprite.getPosition().x-5, ship_sprite.getPosition().y-5);
        }

        // current ship coordinate system. Uses size of sprite to determine, will be made into some kind of array
        ship.x_location = ship_sprite.getPosition().x;
        ship.y_location = ship_sprite.getPosition().y;

        wall.wall_x = wall_sprite.getPosition().x;
        wall.wall_y = wall_sprite.getPosition().y;

        // if the ship coordinates align with the wall coordinates, change sprite to explode and end game
        if (ship.x_location == wall.wall_x || ship.x_location + ship.width == wall.wall_x || ship.y_location == wall.wall_y || ship.y_location - ship.height == wall.wall_y){
            
            std::cout << "HIT\n";
            // if the ship.alive is false, it SHOULD update the texture of the sprite to the explosion image, but current just vanishes. Interesting. 
            ship.alive = false;
        }


    }

}