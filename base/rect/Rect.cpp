//
// Created by lucas on 26/11/22.
//

#include "Rect.h"

Rect::Rect() {

}

Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) {}

void Rect::SumWithVec(Vec2 vec) {

}

double * Rect::getCenter() {
    return nullptr;
}

double Rect::DistanceToAnotherCenter(Rect otherRect) {
    return 0;
}

bool Rect::Contains(double x, double y) {
    return (x>=Rect::x and (x <= Rect::x + w)) and (y >= Rect::y and (y <= (Rect::y + h)));
}

float Rect::getX() const {
    return x;
}

float Rect::getY() const {
    return y;
}
