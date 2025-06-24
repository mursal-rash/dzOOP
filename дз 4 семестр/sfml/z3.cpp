#include <SFML/Graphics.hpp>
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Circular Motion");
    sf::CircleShape circle(30);
    circle.setFillColor(sf::Color::Blue);

    float angle = 0.0f;
    float radius = 200.0f;
    float centerX = 400.0f;
    float centerY = 300.0f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        angle += 0.01f;
        float x = centerX + radius * cos(angle);
        float y = centerY + radius * sin(angle);
        circle.setPosition(x, y);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}