#include <SFML/Graphics.hpp>

class DraggableWithColorChange : public Draggable {
private:
    sf::Color baseColor;
    sf::Color dragColor;

public:
    DraggableWithColorChange(sf::RenderWindow& window, sf::Vector2f position, sf::Vector2f size, sf::Color baseColor, sf::Color dragColor)
        : Draggable(window, position, size, baseColor), baseColor(baseColor), dragColor(dragColor) {}

    void update() override {
        bool wasDragging = isDragging;
        Draggable::update();

        if (isDragging && !wasDragging) {
            shape.setFillColor(dragColor);
        } else if (!isDragging && wasDragging) {
            shape.setFillColor(baseColor);
        }
    }
};
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Draggable with Color Change");
    DraggableWithColorChange rect(
        window,
        sf::Vector2f(100, 100),
        sf::Vector2f(200, 100),
        sf::Color::Green,
        sf::Color::Red
    );

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        rect.update();
        window.clear();
        rect.draw();
        window.display();
    }

    return 0;
}