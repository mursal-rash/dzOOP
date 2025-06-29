#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <set>

class Observer
{
public:
    virtual void update(float value) = 0;
    virtual ~Observer() = default;
};

class Subject
{
public:
    virtual void addObserver(Observer* p) = 0;
    virtual void removeObserver(Observer* p) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() = default;
};

class Drawable
{
public:
    virtual void draw() const = 0;
    virtual ~Drawable() = default;
};

class Slider : public Subject, public Drawable
{
protected:
    sf::RectangleShape mTrackShape;
    sf::RectangleShape mThumbShape;
    sf::Color mTrackColor{200, 200, 220};
    sf::Color mThumbColor{150, 150, 240};
    sf::RenderWindow& mRenderWindow;
    bool mIsPressed{false};
    std::set<Observer*> mObservers;

public:
    Slider(sf::RenderWindow& window, sf::Vector2f centerPosition, sf::Vector2f trackSize, sf::Vector2f thumbSize) 
        : mRenderWindow(window)
    {
        mTrackShape.setSize(trackSize);
        mTrackShape.setOrigin(trackSize / 2.0f);
        mTrackShape.setPosition(centerPosition);
        mTrackShape.setFillColor(mTrackColor);

        mThumbShape.setSize(thumbSize);
        mThumbShape.setOrigin(thumbSize / 2.0f);
        mThumbShape.setPosition(centerPosition);
        mThumbShape.setFillColor(mThumbColor);
    }

    void draw() const override
    {
        mRenderWindow.draw(mTrackShape);
        mRenderWindow.draw(mThumbShape);
    }

    void onMouseMove(const sf::Event& event)
    {
        if (!mIsPressed) return;

        sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseMove.x, event.mouseMove.y});
        float min = mTrackShape.getPosition().x - mTrackShape.getSize().x / 2.0f;
        float max = mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;

        mThumbShape.setPosition({std::clamp(mousePosition.x, min, max), mThumbShape.getPosition().y});
        notifyObservers();
    }

    void onMousePressed(const sf::Event& event)
    {
        if (event.mouseButton.button == sf::Mouse::Left) 
        {
            sf::Vector2f mousePosition = mRenderWindow.mapPixelToCoords({event.mouseButton.x, event.mouseButton.y});
            if (mThumbShape.getGlobalBounds().contains(mousePosition) || mTrackShape.getGlobalBounds().contains(mousePosition)) 
            {
                mIsPressed = true;
                mThumbShape.setPosition({mousePosition.x, mThumbShape.getPosition().y});
                notifyObservers();
            }
        }
    }

    void onMouseReleased(const sf::Event& event)
    { 
        mIsPressed = false;
    }

    void handleEvent(const sf::Event& event) 
    {
        if (event.type == sf::Event::MouseMoved)
            onMouseMove(event);
        else if (event.type == sf::Event::MouseButtonPressed)
            onMousePressed(event);
        else if (event.type == sf::Event::MouseButtonReleased)
            onMouseReleased(event);
    }

    float getValue() const
    {
        float part = mThumbShape.getPosition().x - mTrackShape.getPosition().x + mTrackShape.getSize().x / 2.0f;
        return part / mTrackShape.getSize().x * 100.0f;
    }

    void addObserver(Observer* p) override
    {
        mObservers.insert(p);
    }

    void removeObserver(Observer* p) override
    {
        mObservers.erase(p);
    }

    void notifyObservers() override
    {
        for (auto p : mObservers)
            p->update(getValue());
    }
};

class Circle : public Observer, public Drawable
{
protected:
    sf::CircleShape mShape;
    sf::RenderWindow& mRenderWindow;

public:
    Circle(sf::RenderWindow& window, sf::Vector2f position, float radius) 
        : mRenderWindow(window), mShape(radius)
    {
        mShape.setOrigin({radius, radius});
        mShape.setPosition(position);
        mShape.setFillColor(sf::Color::Green);
    }

    void draw() const override
    {
        mRenderWindow.draw(mShape);
    }

    void update(float value) override
    {
        mShape.setScale({value / 50, value / 50});
    }
};

class CircleColorChange : public Circle
{
public:
    CircleColorChange(sf::RenderWindow& window, sf::Vector2f position, float radius) 
        : Circle(window, position, radius)
    {
        mShape.setFillColor({0, 0, 100});
    }

    void update(float value) override
    {
        mShape.setFillColor({0, 0, static_cast<sf::Uint8>(value * 2)});
    }
};

class Square : public Observer, public Drawable
{
protected:
    sf::RectangleShape mShape;
    sf::RenderWindow& mRenderWindow;

public:
    Square(sf::RenderWindow& window, sf::Vector2f position, float size) 
        : mRenderWindow(window), mShape({size, size})
    {
        mShape.setOrigin({size / 2, size / 2});
        mShape.setPosition(position);
        mShape.setFillColor(sf::Color::Red);
    }

    void draw() const override
    {
        mRenderWindow.draw(mShape);
    }

    void update(float value) override
    {
        mShape.setRotation(3 * value);
    }
};

class VerticalMover : public Observer, public Drawable
{
protected:
    sf::CircleShape mShape;
    sf::RenderWindow& mRenderWindow;
    float mInitialY;

public:
    VerticalMover(sf::RenderWindow& window, sf::Vector2f position, float radius)
        : mRenderWindow(window), mShape(radius), mInitialY(position.y)
    {
        mShape.setOrigin({radius, radius});
        mShape.setPosition(position);
        mShape.setFillColor(sf::Color::Yellow);
    }

    void draw() const override
    {
        mRenderWindow.draw(mShape);
    }

    void update(float value) override
    {
        mShape.setPosition(mShape.getPosition().x, mInitialY + value);
    }
};

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(800, 800), "Observer Pattern", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    Slider slider(window, {400, 500}, {500, 20}, {25, 90});

    std::vector<Observer*> observers{
        new Circle{window, {100, 300}, 50},
        new Square{window, {400, 300}, 100},
        new CircleColorChange{window, {700, 300}, 50}
    };

    VerticalMover verticalMover(window, {400, 200}, 30);
    slider.addObserver(&verticalMover);

    for (auto p : observers)
        slider.addObserver(p);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed)
                window.close();

            slider.handleEvent(event);
        }

        window.clear(sf::Color::Black);
        slider.draw();
        for (auto p : observers)
            dynamic_cast<Drawable*>(p)->draw();
        verticalMover.draw();
        window.display();
    }

    for (auto p : observers)
        delete p;

    return 0;
}