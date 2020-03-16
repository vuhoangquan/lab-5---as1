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

//
//ostream& operator <<(ostream& osObject, const date& date1)
//{
//	osObject << date1.Date << "/" << date1.Month << "/" << date1.Year;
//	return osObject;
//}
//istream& operator >>(istream& isObject, date& date1)
//{
//	isObject >> date1.Date >> date1.Month >> date1.Year;
//	return isObject;
//}
