#pragma once
#include "unit.h"
#include <iostream>

using namespace std;

int testUnitClass() {
	unit unit_Obj_1;
	unit_Obj_1.print();

	unit* unitptr = new unit();
	unitptr->setUnit(354, 4456, 35);
	unitptr->print();

	unitptr->setSpeed(45.36);
	cout << unitptr->getSpeed();

	return 0;
}