#include <SFML/Graphics.hpp>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mouse Coordinates");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return 1;
    }

    sf::Text text("", font, 20);
    text.setFillColor(sf::Color::White);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mouseCoords = window.mapPixelToCoords(mousePixel);

        std::string str = "Pixel: " + std::to_string(mousePixel.x) + ", " + std::to_string(mousePixel.y) + 
                          "\nCoords: " + std::to_string(mouseCoords.x) + ", " + std::to_string(mouseCoords.y);
        text.setString(str);

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}