//implemenetation
#include <iostream>
#include <string>
#include "unit.h"

using namespace std;

//default contructor
unit::unit() // hearer file name ::header file location
{
	speed = 0;
	solar_radiation = 0;
	air_temperature = 0;
}
//destructor
unit::~unit() {
}

//specific constructor
unit::unit(float sp, float sr, float airtemp) {
	speed = sp;
	solar_radiation = sr;
	air_temperature = airtemp;
}

//setter
void unit::setSpeed(float sp) {
	speed = sp;
}
void unit::setSolarRad(float sr) {
	solar_radiation = sr;
}
void unit::setAirTemp(float airtemp) {
	air_temperature = airtemp;
}
void unit::setUnit(float sp, float sr, float airtemp) {
	speed = sp;
	solar_radiation = sr;
	air_temperature = airtemp;
}

//getter
void unit::print() {
	cout << "wind speed: " << speed << " solar radiation: " << solar_radiation << " air temperature: " << air_temperature;
	cout << endl;
}
float unit::getSpeed() const {
	return speed;
}
float unit::getSolarRad() const {
	return solar_radiation;
}
float unit::getAirTemp() const {
	return air_temperature;
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
