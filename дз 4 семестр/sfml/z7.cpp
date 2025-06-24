#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Mouse Attraction (a)");
    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Magenta);
    circle.setPosition(400, 300);

    float speed = 3.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            sf::Vector2f circlePos = circle.getPosition() + sf::Vector2f(30, 30);
            sf::Vector2f direction = mousePos - circlePos;
            float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
            if (length > 0) {
                direction = direction / length;
                circle.move(direction * speed);
            }
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}