#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <set>

// Базовые классы Observer, Subject, Drawable остаются без изменений

class RotationObserver : public Observer
{
public:
    virtual void update(float value) override
    {
        for (auto shape : mShapes)
            shape->setRotation(3 * value);
    }

    void addShape(sf::Transformable* shape)
    {
        mShapes.push_back(shape);
    }

private:
    std::vector<sf::Transformable*> mShapes;
};

class ColorObserver : public Observer
{
public:
    virtual void update(float value) override
    {
        for (auto shape : mColorShapes)
            shape->setFillColor({static_cast<sf::Uint8>(value * 2), 0, 100});
    }

    void addShape(sf::Shape* shape)
    {
        mColorShapes.push_back(shape);
    }

private:
    std::vector<sf::Shape*> mColorShapes;
};

// Класс Slider остается без изменений

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Two Subjects", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    // Создаем два слайдера
    Slider rotationSlider(window, {200, 500}, {300, 20}, {25, 90});
    Slider colorSlider(window, {600, 500}, {300, 20}, {25, 90});

    // Создаем наблюдателей
    RotationObserver rotationObserver;
    ColorObserver colorObserver;

    // Создаем фигуры
    sf::CircleShape circle1(50);
    circle1.setOrigin({50, 50});
    circle1.setPosition({200, 300});
    circle1.setFillColor(sf::Color::Green);

    sf::RectangleShape square({100, 100});
    square.setOrigin({50, 50});
    square.setPosition({400, 300});
    square.setFillColor(sf::Color::Red);

    sf::CircleShape circle2(50);
    circle2.setOrigin({50, 50});
    circle2.setPosition({600, 300});
    circle2.setFillColor(sf::Color::Blue);

    // Регистрируем фигуры у наблюдателей
    rotationObserver.addShape(&circle1);
    rotationObserver.addShape(&square);
    rotationObserver.addShape(&circle2);

    colorObserver.addShape(&circle1);
    colorObserver.addShape(&square);
    colorObserver.addShape(&circle2);

    // Подписываем наблюдателей на слайдеры
    rotationSlider.addObserver(&rotationObserver);
    colorSlider.addObserver(&colorObserver);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            rotationSlider.handleEvent(event);
            colorSlider.handleEvent(event);
        }

        window.clear(sf::Color::Black);
        rotationSlider.draw();
        colorSlider.draw();
        window.draw(circle1);
        window.draw(square);
        window.draw(circle2);
        window.display();
    }
}