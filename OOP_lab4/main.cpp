#include <iostream>
#include "Quadrilateral.h"
#include "main.h"

#define QUADR_COORDS 1,0, 2,1, 5,5, 1,2
#define INVALID_COORDS 0,0, 1,1, 0,1, 1,0

using namespace std;

void CheckQuadrilateral(Quadrilateral* quadr)
{
    cout << "Quadrilateral " << quadr->getAllPointsStr() << endl << endl;

    if (quadr->isReal())
    {
        cout << "Square: " << quadr->getSquare() << endl;
        cout << "Diagonal AC" << quadr->getAStr() << quadr->getCStr() << ": " << quadr->getACLength() << endl;
        cout << "Diagonal BD" << quadr->getBStr() << quadr->getDStr() << ": " << quadr->getBDLength() << endl;
    }
    else
    {
        cout << "Quadrilateral does not exist" << endl;
    }

    cout << endl;

    delete quadr;
}

int main()
{
    Quadrilateral* quadr1 = new Quadrilateral(QUADR_COORDS);
    Quadrilateral* quadr2 = new Quadrilateral(INVALID_COORDS);

    CheckQuadrilateral(quadr1);
    CheckQuadrilateral(quadr2);
}
