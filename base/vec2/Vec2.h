//
// Created by lucas on 26/11/22.
//

#ifndef GAME_VEC2_H
#define GAME_VEC2_H

#include <tgmath.h>


/**
 * Represents a vector on R²
 */
class Vec2 {
private:
    float x;
    float y;

public:
    /**
     * Simple constructor that initializes all members as 0 (zero)
     */
    Vec2();

    /**
     * Creates a Vec2
     * @param x position on the horizontal axis
     * @param y position on the vertical axis. This axis grows down
     */
    Vec2(float x, float y);

    /**
     * Sums another vector to this
     * @param vec vector to be summed
     */
    void Sum(Vec2 vec);

    /**
     * Multiplies this by a scalar
     * @param scalar number to be multiplied
     */
    void MultiplyByEscalar(int scalar);

    /**
     * Gets the unit vector, which means this with same direction but with magnitude 1
     * @return this normalized
     */
    Vec2 GetUnit();

    /**
     * Calculates the distance between this and another vector
     * @param anotherVector the destiny vector
     * @return the difference's magnitude between the vectors
     */
    double DistanceTo(Vec2 anotherVector);

    /**
     * Calculates this inclination related to x axis
     * @return inclination in radians
     */
    int InclinationToX();

    /**
     * Rotates this
     * @param angle angle in radians to be rotated
     */
    void Rotate(double angle);

    float getX() const;

    float getY() const;

    Vec2 operator+(const Vec2 other) const;
};


#endif //GAME_VEC2_H
