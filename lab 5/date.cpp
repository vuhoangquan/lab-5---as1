//implemenetation
#include <iostream>
#include <string>
#include "date.h"

using namespace std;

//default contructor
date::date() // hearer file name ::header file location
{
	Date = 0;
	Month = 0;
	Year = 0;
}
//destructor
date::~date() {
}

//specific constructor
date::date(int dd, int mm, int yyyy) {
	Date = dd;
	Month = mm;
	Year = yyyy;
}

//setter
void date::setDay(int dd) {
	Date = dd;
}
void date::setMonth(int mm) {
	Month = mm;
}
void date::setYear(int yyyy) {
	Year = yyyy;
}
void date::setDate(int dd, int mm, int yyyy) {
	Date = dd;
	Month = mm;
	Year = yyyy;
}

//getter
void date::print() {
	cout << "date: " << Date << " month: " << Month << " year: " << Year;
}
int date::getDay() const {
	return Date;
}
int date::getMonth() const {
	return Month;
}
int date::getYear() const {
	return Year;
}
int date::getDateAsInt() {
	return Date + (Month * 100) + (Year * 10000);
}

//io operator overloading
ostream& operator <<(ostream& osObject, const date& date1)
{
	osObject << date1.Date << "/" << date1.Month << "/" << date1.Year << "  ";
	return osObject;
}
istream& operator >>(istream& isObject, date& date1)
{
	isObject >> date1.Date >> date1.Month >> date1.Year;
	return isObject;
}

//comparison operator overloading

bool date::operator < (date& rhs)const {
	if (this->getYear() < rhs.getYear()) {
		return true;
	}
	else if (this->getYear() == rhs.getYear()) {
		if (this->getMonth() < rhs.getMonth()) {
			return true;
		}
		else if (this->getMonth() == rhs.getMonth()) {
			if (this->getDay() < rhs.getDay()) {
				return true;
			}
			else {
				return false;
			}
		}
		else { return false; }
	}
	else {
		return false;
	}
}

bool date::operator == (date& rhs)const {
	if (this->getYear() == rhs.getYear()) {
		if (this->getMonth() == rhs.getMonth()) {
			if (this->getDay() == rhs.getDay()){
				return true;
			}
			else { return false; }
		}
		else { return false; }
	}
	else { return false; }
}

date& date::operator = (const int rhs) // copy assignment
{
	if (rhs == 0) {
		this->setDay(00);
		this->setMonth(00);
		this->setYear(0000);
	}
	return *this;
}