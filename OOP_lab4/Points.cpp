#include <stdlib.h>
#include <utility>
#include <sstream>
#include <iostream>
#include "Points.h"

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

Points::~Points()
{
	cout << "Desctruction of Points " << this->getAllPointsStr() << endl;
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

string Points::getAllPointsStr() const
{
	return this->getAStr() + this->getBStr() + this->getCStr() + this->getDStr();
}

string coordsToStr(int a, int b)
{
	std::stringstream ss;

	ss << "[" << a << ";" << b << "]";

	return ss.str();
}

string Points::getAStr() const
{
	return coordsToStr(this->ax, this->ay);
};

string Points::getBStr() const
{
	return coordsToStr(this->bx, by);
};

string Points::getCStr() const
{
	return coordsToStr(this->cx, this->cy);
};

string Points::getDStr() const
{
	return coordsToStr(this->dx, this->dy);
}