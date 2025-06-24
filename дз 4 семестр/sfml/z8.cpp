#include <SFML/Graphics.hpp>
#include <random>
#include <vector>

float getRandomFloat(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<float> d(min, max);
    return d(gen);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Броуновское движение");
    std::vector<sf::CircleShape> particles;
    std::vector<sf::Vector2f> velocities;

    for (int i = 0; i < 50; ++i) {
        sf::CircleShape particle(10);
        particle.setFillColor(sf::Color(
            getRandomFloat(0, 255),
            getRandomFloat(0, 255),
            getRandomFloat(0, 255)
        ));
        particle.setPosition(
            getRandomFloat(0, 700),
            getRandomFloat(0, 500)
        );
        particles.push_back(particle);
        velocities.push_back(sf::Vector2f(
            getRandomFloat(-2, 2),
            getRandomFloat(-2, 2)
        ));
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        for (size_t i = 0; i < particles.size(); ++i) {
            particles[i].move(velocities[i]);

            if (particles[i].getPosition().x < 0 || particles[i].getPosition().x > 780)
                velocities[i].x *= -1;
            if (particles[i].getPosition().y < 0 || particles[i].getPosition().y > 580)
                velocities[i].y *= -1;

            if (rand() % 100 < 5) {
                velocities[i].x += getRandomFloat(-0.5f, 0.5f);
                velocities[i].y += getRandomFloat(-0.5f, 0.5f);
            }
        }

        window.clear();
        for (const auto& particle : particles) {
            window.draw(particle);
        }
        window.display();
    }

    return 0;
}