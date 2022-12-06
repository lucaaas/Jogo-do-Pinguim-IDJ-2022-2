//
// Created by lucas on 26/11/22.
//

#ifndef GAME_RECT_H
#define GAME_RECT_H

#include "../vec2/Vec2.h"

/**
 * Represents a rectangle and its dimensions. Where x and y are the top left angle
 */
class Rect {
private:
    float x;
    float y;
    float w;
    float h;

public:
    /**
     * Simple constructor that initializes all members as 0 (zero)
     */
    Rect();

    /**
     * Creates a Rect
     * @param x position on the horizontal axis
     * @param y position on the vertical axis. This axis grows down
     * @param w width
     * @param h height
     */
    Rect(float x, float y, float w, float h);

    /**
     * Sums this with a vector
     * @param vec vector to be summed
     */
    void SumWithVec(Vec2 vec);

    /**
     * Gets the center of this
     * @return an array with the coords x and y
     */
    double* getCenter();

    /**
     * Calculates the distance between this center and another
     * @param otherRect
     * @return the distance between the centers
     */
    double DistanceToAnotherCenter(Rect otherRect);

    /**
     * Checks if this contains the coordinates
     * @param x
     * @param y
     * @return true if contains
     */
    bool Contains(double x, double y);

    /**
     *
     * @return the coordinate in the horizontal axis
     */
    float getX() const;

    /**
     *
     * @return the coordinate in the vertical axis
     */
    float getY() const;
};


#endif //GAME_RECT_H
