#include <stdlib.h>
#include <utility>
#include <stdexcept>
#include <iostream>
#include "Quadrilateral.h"

using namespace std;

inline int area(int ax, int ay, int bx, int by, int cx, int cy)
{
	return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

inline bool intersect_1(int a, int b, int c, int d)
{
	if (a > b)
	{
		swap(a, b);
	}

	if (c > d)
	{
		swap(c, d);
	}

	return max(a, c) <= min(b, d);
}

bool intersect(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy) {
	return intersect_1(ax, bx, cx, dx)
		&& intersect_1(ay, by, cy, dy)
		&& area(ax, ay, bx, by, cx, by) * area(ax, ay, bx, by, dx, dy) <= 0
		&& area(cx, cy, dx, dy, ax, ay) * area(cx, cy, dx, dy, bx, by) <= 0;
}

Quadrilateral::Quadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) :
    Points(x1, y1, x2, y2, x3, y3, x4, y4)
{
}

Quadrilateral::~Quadrilateral()
{
	cout << "Desctruction of Quadrilateral " << this->getAllPointsStr() << endl;
}

double Quadrilateral::getSquare() const
{
	const int topsCount = 4;

	int xArray[topsCount] = {
		this->getAX(),
		this->getBX(),
		this->getCX(),
		this->getDX()};

	int yArray[topsCount] = {
		this->getAY(),
		this->getBY(),
		this->getCY(),
		this->getDY() };

	int sum = 0;

	for (int i = 0; i < topsCount; i++)
	{
		sum += xArray[i] * yArray[(i + 1) % topsCount];
		sum -= xArray[(i + 1) % topsCount] * yArray[i];
	}

	sum = abs(sum);

	double square = (double)sum / (double)2;

	return square;
}

double hypo(int x, int y)
{
	double sumOfCatets = pow(x, 2) + pow(y, 2);

	double ret = sqrt(sumOfCatets);

	return ret;
}

double Quadrilateral::getACLength() const
{
	return hypo(
		abs(this->getAX() - this->getCX()), 
		abs(this->getAY() - this->getCY()));
}

double Quadrilateral::getBDLength() const
{
	return hypo(
		abs(this->getBX() - this->getDX()),
		abs(this->getBY() - this->getDY()));
}

bool Quadrilateral::isReal() const
{
	return !intersect(
		this->getAX(), 
		this->getAY(), 
		this->getBX(), 
		this->getBY(), 
		this->getCX(), 
		this->getCY(), 
		this->getDX(), 
		this->getDY());
}