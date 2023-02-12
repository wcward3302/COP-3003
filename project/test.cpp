#include <SFML/Graphics.hpp>

//g++ test.cpp -lsfml-graphics -lsfml-window -lsfml-system -o testing.out

int main()
{

    std::string image_location = "/Users/willward/Library/CloudStorage/OneDrive-Personal/Documents/Current Courses/COP-3003/project/Images/photo-1555505019-8c3f1c4aba5f.jpeg";
    std::string font_location = "/Users/willward/Library/CloudStorage/OneDrive-Personal/Documents/Current Courses/COP-3003/project/Fonts/ChrustyRock-ORLA.ttf";

    sf::RenderWindow window(sf::VideoMode(1640, 1480), "SFML Application");
    sf::CircleShape shape;

    sf::Texture texture;
    texture.loadFromFile(image_location);
    sf::Sprite sprite(texture);

    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);


    sf::Text text;

    sf::Font font;
    font.loadFromFile(font_location);
    // select the font
    text.setFont(font); // font is a sf::Font
    text.setString("Hello world");
    text.setCharacterSize(124); // in pixels, not points!
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);


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