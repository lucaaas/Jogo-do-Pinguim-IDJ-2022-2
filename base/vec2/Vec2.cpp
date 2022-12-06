//
// Created by lucas on 26/11/22.
//

#include "Vec2.h"

Vec2::Vec2() {}

Vec2::Vec2(float x, float y) : x(x), y(y) {}

void Vec2::Sum(Vec2 vec) {

}

void Vec2::MultiplyByEscalar(int scalar) {

}

Vec2 Vec2::GetUnit() {
    return Vec2();
}

double Vec2::DistanceTo(Vec2 anotherVector) {
    return 0;
}

int Vec2::InclinationToX() {
    return 0;
}

void Vec2::Rotate(double angle) {
    x = x * cos(angle) + y * sin(angle);
    y = x * sin(angle) - y * cos(angle);
}

float Vec2::getX() const {
    return x;
}

float Vec2::getY() const {
    return y;
}

Vec2 Vec2::operator+(const Vec2 other) const {
    Vec2 sum = Vec2(this->x + other.x, this->y + other.y);
    return sum;
}
