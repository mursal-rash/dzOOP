#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

sf::RenderWindow initializeWindow() {
    return sf::RenderWindow(sf::VideoMode(800, 600), "Rotating Square");
}

sf::RectangleShape createSquare() {
    sf::RectangleShape square(sf::Vector2f(100.f, 100.f));
    square.setFillColor(sf::Color::Green);
    square.setOrigin(50.f, 50.f);
    square.setPosition(400.f, 300.f);
    return square;
}

int main() 
{
    sf::RenderWindow window = initializeWindow();
    sf::RectangleShape square = createSquare();
    sf::Clock clock;

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        float deltaTime = clock.restart().asSeconds();
        square.rotate(30.f * deltaTime);

       
        window.clear();
        window.draw(square);
        window.display();
    }

    return 0;
}
