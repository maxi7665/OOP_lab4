#include "Points.h"
#include <stdlib.h>
#include <utility>
#include <sstream>

using namespace std;

Points::Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	this->ax = x1;
	this->ay = y1;

	this->bx = x2;
	this->by = y2;

	this->cx = x3;
	this->cy = y3;

	this->dx = x4;
	this->dy = y4;
}

int Points::getAX() const { return this->ax; }
void Points::setAX(int ax) { this->ax = ax; }
int Points::getAY() const { return this->ay; }
void Points::setAY(int ay) { this->ay = ay; }

int Points::getBX() const { return this->bx; }
void Points::setBX(int bx) { this->bx = bx; }
int Points::getBY() const { return this->by; }
void Points::setBY(int by) { this->by = by; }

int Points::getCX() const { return this->cx; }
void Points::setCX(int cx) { this->cx = cx; }
int Points::getCY() const { return this->cy; }
void Points::setCY(int cy) { this->cy = cy; }

int Points::getDX() const { return this->dx; }
void Points::setDX(int dx) { this->dx = dx; }
int Points::getDY() const { return this->dy; }
void Points::setDY(int dy) { this->dy = dy; }

string Points::getAStr()
{
	return coordsToStr(ax, ay);
}

string Points::getB()
{
	return coordsToStr(bx, by);
}

string Points::getC()
{
	return coordsToStr(cx, cy);
}

string Points::getD()
{
	return coordsToStr(dx, dy);
}

string Points::getAllPoints()
{
	return this->getAStr() + this->getB() + this->getC() + this->getD();
}

string coordsToStr(int a, int b)
{
	std::stringstream ss;

	ss << "[" << a << ";" << b << "]";

	return ss.str();
}

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