#include <string>

#pragma once
class Points
{
private:

	int ax;
	int ay;

	int bx;
	int by;

	int cx;
	int cy;

	int dx;
	int dy;

public:

	Points(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);

	int getAX() const;
	void setAX(int x1);

	int getAY() const;
	void setAY(int y1);

	int getBX() const;
	void setBX(int x2);

	int getBY() const;
	void setBY(int y2);

	int getCX() const;
	void setCX(int x3);

	int getCY() const;
	void setCY(int y3);

	int getDX() const;
	void setDX(int x4);

	int getDY() const;
	void setDY(int y4);

	string getAStr();
	string getB();
	string getC();
	string getD();

	string getAllPoints();
};