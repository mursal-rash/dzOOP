#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

struct Ball 
{
    sf::CircleShape shape;
    float mass;
    float charge;
    sf::Vector2f velocity;
};

float distance(const sf::Vector2f& a, const sf::Vector2f& b) 
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

sf::Vector2f forceBetween(const Ball& a, const Ball& b) 
{
    sf::Vector2f direction = b.shape.getPosition() - a.shape.getPosition();
    float dist = distance(a.shape.getPosition(), b.shape.getPosition());
    if (dist < 10.f) return sf::Vector2f(0.f, 0.f);
    float forceMagnitude = (a.charge * b.charge) / dist;
    direction /= dist;
    return forceMagnitude * direction;
}

int main() 
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    const int numBalls = 10;
    const float dt = 1.0f / 60.0f;
    const sf::Vector2u windowSize(800, 600);

    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Simulation");
    window.setFramerateLimit(60);

    std::vector<Ball> balls(numBalls);
    for (auto& ball : balls) {
        float radius = 15.f;
        ball.mass = std::rand() % 10 + 1;
        ball.charge = std::rand() % 20 - 10;
        ball.shape = sf::CircleShape(radius);
        ball.shape.setPosition(std::rand() % (windowSize.x - static_cast<int>(2 * radius)),
                               std::rand() % (windowSize.y - static_cast<int>(2 * radius)));
        ball.velocity = sf::Vector2f(0.f, 0.f);

        if (ball.charge > 0) 
        {
            ball.shape.setFillColor(sf::Color::Red);
        } else 
        {
            ball.shape.setFillColor(sf::Color::Blue);
        }
    }

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (auto& ball : balls) 
        {
            sf::Vector2f netForce(0.f, 0.f);

            for (const auto& other : balls) 
            {
                if (&ball != &other) 
                {
                    netForce += forceBetween(ball, other);
                }
            }

            sf::Vector2f acceleration = netForce / ball.mass;
            ball.velocity += acceleration * dt;
            ball.shape.move(ball.velocity * dt);

            if (ball.shape.getPosition().x < 0 || ball.shape.getPosition().x + 2 * ball.shape.getRadius() > windowSize.x) 
            {
                ball.velocity.x = -ball.velocity.x;
            }
            if (ball.shape.getPosition().y < 0 || ball.shape.getPosition().y + 2 * ball.shape.getRadius() > windowSize.y) 
            {
                ball.velocity.y = -ball.velocity.y;
            }
        }

        window.clear();
        for (const auto& ball : balls) 
        {
            window.draw(ball.shape);
        }
        window.display();
    }

    return 0;
}