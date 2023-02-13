/*
Current state 
- create shapes, texts, backgrounds
- create window
- collect input from keyboard and moves an object on the screen
*/


#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>

int main()
{
    // file paths - concatinate current working directory with locations of other files
    std::string file_path = std::filesystem::current_path();
    std::string image_location = file_path + "/Images/background.jpeg";
    std::string font_location = file_path + "/Fonts/Menlo-Regular.ttf";
    
    // Window - set size and window name, set framerate cap 
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "SFML Project Testing Application");
    window.setVerticalSyncEnabled(true);

    //Background - 
    sf::Texture texture;
    texture.loadFromFile(image_location);
    sf::Sprite sprite(texture);

    // shape - create shape, set size, set position, set color
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(750.f, 500.f);
    shape.setFillColor(sf::Color::Red);

    // Text - load font, set text (string), set size, set color
    sf::Text text;
    sf::Font font;
    font.loadFromFile(font_location);
    text.setFont(font);
    text.setString("Hello world\nuse arrow keys to move circle!\nSpace to return");
    text.setCharacterSize(70);
    text.setFillColor(sf::Color::White);


    // while window is open, draw and display objects to window
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event)){
            // once window is closed, exit all while loops
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // draw items on window
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.draw(shape);
        window.display();

        // use keyboard input to move shape around screen
        // if press Right arrow
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            // left key is pressed: move our character
            window.setTitle("Moving Right");
            shape.move(2.f, 0.f);
        }
        // if press Up arrow
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            window.setTitle("Moving Up");
            shape.move(0.f, -2.f);
        }
        // if press Left arrow
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            window.setTitle("Moving Left");
            shape.move(-2.f, 0.f);
        }
        // if press Down arrow
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            window.setTitle("Moving Down");
            shape.move(0.f, 2.f);
        }
        // if press Space
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            shape.setPosition(window.getSize().x/2, window.getSize().y/2);
        }

    }
}