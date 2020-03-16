//implemenetation
#include <iostream>
#include <string>
#include "time.h"
using namespace std;

//default contructor
time::time() // hearer file name ::header file location
{
	Hour = 0; Min = 0;
}
//destructor
time::~time() {

}

//specific constructor
time::time(int hr, int mm) {
	Hour = hr;
	Min = mm;
}

//setter
void time::setHour(int hr) {
	Hour = hr;
}
void time::setMin(int mm) {
	Min = mm;
}

void time::setTime(int hr, int mm) {
	Hour = hr;
	Min = mm;

}

//getter
void time::print() {
	cout << "hour: " << Hour << " min: " << Min;
}
int time::getHour() const {
	return Hour;
}
int time::getMin() const {
	return Min;
}
//
//
//ostream& operator <<(ostream& osObject, const time& time1)
//{
//	osObject << time1.Hour << ":" << time1.Min;
//	return osObject;
//}
//istream& operator >>(istream& isObject, time& time1)
//{
//	isObject >> time1.Hour >> time1.Min;
//	return isObject;
//}
