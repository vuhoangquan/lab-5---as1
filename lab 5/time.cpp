//implemenetation
#include <iostream>
#include <string>
#include "time.h"
using namespace std;

//operator overloading
ostream& operator <<(ostream& osObject, const time& time1)
{
	osObject << time1.Hour << ":" << time1.Min;
	return osObject;
}
istream& operator >>(istream& isObject, time& time1)
{
	isObject >> time1.Hour >> time1.Min;
	return isObject;
}

//comparison operator overloading
bool time::operator < (time& rhs)const {
	if (this->getHour() < rhs.getHour()) {
		return true;
	}
	else if (this->getHour() == rhs.getHour()) {
		if (this->getMin() < rhs.getMin()) {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}

bool time::operator == (time& rhs)const {
	if (this->getHour() == rhs.getHour()) {
		if (this->getMin() == rhs.getMin()) {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}

time& time::operator = (const int rhs) // copy assignment
{
	if (rhs == 0) {
		this->setHour(00);
		this->setMin(00);
	}

	return *this;
}

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