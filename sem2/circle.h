#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"

class Circle {
private:
Point center;
float radius;

public:
Circle(const Point& acenter, float aradius);
Circle();
Circle(const Circle& circle);

void setCenter(const Point& acenter);
Point getCenter() const;

void setRadius(float aradius);
float getRadius() const;

float getArea() const;
float getDistance(const Point& p) const;
bool isColliding(const Circle& c) const;
void move(const Point& p);
};

#endif // CIRCLE_H