#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello World");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return 1;
    }

    sf::Text text("Привет Мир!", font, 50);
    text.setFillColor(sf::Color::White);
    text.setPosition(250, 250);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }

    return 0;
}