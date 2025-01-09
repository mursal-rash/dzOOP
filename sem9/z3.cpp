#include <SFML/Graphics.hpp>
#include <cmath>

int main() 
{
    const int windowWidth = 800;
    const int windowHeight = 600;
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Circle Movement");

    const float radius = 50.0f;
    const float circleRadius = 10.0f;
    float angle = 0.0f;
    const float speed = 0.05f;

    sf::CircleShape circle(circleRadius);
    circle.setFillColor(sf::Color::Red);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float x = windowWidth / 2 + radius * cos(angle);
        float y = windowHeight / 2 + radius * sin(angle);

        circle.setPosition(x - circleRadius, y - circleRadius);

        angle += speed;

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
