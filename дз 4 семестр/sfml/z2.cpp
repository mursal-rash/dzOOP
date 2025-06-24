#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Rotating Square");
    sf::RectangleShape square(sf::Vector2f(100, 100));
    square.setFillColor(sf::Color::Red);
    square.setOrigin(50, 50);
    square.setPosition(400, 300);

    float angle = 0.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        angle += 1.0f;
        square.setRotation(angle);

        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}