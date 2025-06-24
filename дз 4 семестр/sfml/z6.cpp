#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Arrow Keys Movement");
    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Yellow);
    circle.setPosition(400, 300);

    float speed = 5.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            circle.move(-speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            circle.move(speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            circle.move(0, -speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            circle.move(0, speed);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}