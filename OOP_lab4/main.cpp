#include <iostream>
#include "Quadrilateral.h"

#define QUADR_COORDS 1,0, 2,1, 5,5, 1,2

using namespace std;

int main()
{
    Quadrilateral* quadr1 = new Quadrilateral(QUADR_COORDS);

    cout << "Quadrilateral " << quadr1->getAllPointsStr() << endl << endl;

    if (quadr1->isReal())
    {
        cout << "Square: " << quadr1->getSquare() << endl;
        cout << "Diagonal AC" << quadr1->getAStr() << quadr1->getCStr() << ": " << quadr1->getACLength() << endl;
        cout << "Diagonal BD" << quadr1->getBStr() << quadr1->getDStr() << ": " << quadr1->getBDLength() << endl;
    }
    else
    {
        cout << "Quadrilateral does not exist" << endl;
    }

    cout << endl;

    delete quadr1;

    return 0;
}
