#pragma once
#include "Points.h"
class Quadrilateral :
    public Points
{
public:

    Quadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
    ~Quadrilateral();

    double getSquare() const;

    double getACLength() const;

    double getBDLength() const;

    bool isReal() const;
};

