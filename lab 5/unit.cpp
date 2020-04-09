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

//io operator overloading
ostream& operator <<(ostream& osObject, const unit& unit1)
{
	osObject << unit1.speed << "/" << unit1.solar_radiation << "/" << unit1.air_temperature;
	return osObject;
}
istream& operator >>(istream& isObject, unit& unit1)
{
	isObject >> unit1.speed >> unit1.solar_radiation >> unit1.air_temperature;
	return isObject;
}

//comparison operator overloading 
bool unit::operator < (unit& rhs)const {
	if (this->getSpeed() < rhs.getSpeed()) {
		return true;
	}
	else if (this->getSolarRad() < rhs.getSolarRad()) {
		return true;
	}
	else if (this->getAirTemp() < rhs.getAirTemp()) {
		return true;
	}
	else { return false; }
}


bool unit::operator == (unit& rhs)const {
	if (this->getSpeed() == rhs.getSpeed()) {
		return true;
	}
	else if (this->getSolarRad() == rhs.getSolarRad()) {
		return true;
	}
	else if (this->getAirTemp() == rhs.getAirTemp()) {
		return true;
	}
	else { return false; }
}

unit& unit::operator = (const int rhs) // copy assignment
{
	if (rhs == 0) {
		this->setSpeed(0.0);
		this->setSolarRad(0.0);
		this->setAirTemp(0.0);
	}
	return *this;
}