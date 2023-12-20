//
// Created by pavel on 8/15/2023.
//

#ifndef CHESSALGORITHM_COORDINATES_H
#define CHESSALGORITHM_COORDINATES_H


class Coordinates {
public:
    int x;
    int y;

    Coordinates() = default;
    Coordinates(int x, int y): x(x), y(y) {}

    //adds new coordinates to the old ones
    Coordinates addCoordinates(Coordinates xy_plus);
    Coordinates minusCoordinates(Coordinates xy_minus);

    //this operation is there bcs of map
    bool operator<(const Coordinates& other) const;
};


#endif //CHESSALGORITHM_COORDINATES_H
