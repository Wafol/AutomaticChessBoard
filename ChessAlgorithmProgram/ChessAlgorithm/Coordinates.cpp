//
// Created by pavel on 8/15/2023.
//

#include "Coordinates.h"

Coordinates Coordinates::addCoordinates(Coordinates xy_plus) {
    x += xy_plus.x;
    y += xy_plus.y;

    return *this;
}

Coordinates Coordinates::minusCoordinates(Coordinates xy_minus) {
    x -= xy_minus.x;
    y -= xy_minus.y;

    return *this;
}

bool Coordinates::operator<(const Coordinates &other) const {
    if (x != other.x)
        return x < other.x;

    return y < other.y;
}
