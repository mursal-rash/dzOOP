#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Moving Circle");
    sf::CircleShape circle(50);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(0, 300);

    float speed = 5.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        circle.move(speed, 0);
        if (circle.getPosition().x > 800)
            circle.setPosition(-100, 300);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}