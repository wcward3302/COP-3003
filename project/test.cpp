#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>

int main()
{
    // dynamic file paths
    std::string file_path = std::filesystem::current_path();
    std::string image_location = file_path + "/Images/background.jpeg";
    std::string font_location = file_path + "/Fonts/Menlo-Regular.ttf";
    
    //instance for window
    sf::RenderWindow window(sf::VideoMode(1500, 1000), "SFML Project Testing Application");
    window.setVerticalSyncEnabled(true);

    //Background 
    sf::Texture texture;
    texture.loadFromFile(image_location);
    sf::Sprite sprite(texture);

    // shape
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(200.f, 300.f);
    shape.setFillColor(sf::Color::Cyan);

    // Text
    sf::Text text;
    sf::Font font;
    font.loadFromFile(font_location);
    text.setFont(font);
    text.setString("Hello world");
    text.setCharacterSize(110);
    text.setFillColor(sf::Color::Black);


    // while window is open, draw and display objects to window
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.draw(shape);
        window.display();
    }
}