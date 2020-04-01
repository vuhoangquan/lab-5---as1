#pragma once
#pragma once
//-------------------------------------------------------------------------
#ifndef H_unit //if not define
#define H_unit
//-------------------------------------------------------------------------
#include <iostream>
#include <string>	
using namespace std;
//-------------------------------------------------------------------------
/**
 * @class unit
 * @brief manages all and data from sensor read from file in program
 *
 *
 */
class unit {
	/**
	 * @brief overload input and output to show, store all sensor data info
	 */
	 //friend ostream& operator << (ostream&, const time&);//declaration (of vector?)
	 //friend istream& operator >> (istream&, time&);
public:
	/**
	 * @brief set default value for all sensor data
	 */
	unit();
	/**
	 * set wind speed, solar radiation, air temperature
	 * @param sp - wind speed, sr - solar radiation, airtemp - air temperature
	 */
	unit(float sp, float sr, float airtemp);
	~unit(); //destructor

	//setters
	/**
	 * @brief store sensor data for program
	 * @param sp - wind speed, sr - solar radiation, airtemp - air temperature
	 */
	void setUnit(float sp, float sr, float airtemp);
	/**
	 * @brief store speed for program
	 * @param sp - speed
	 */
	void setSpeed(float sp);
	/**
	 * @brief store solar radtiation for program
	 * @param sr - solar radiation
	 */
	void setSolarRad(float sr);
	/**
	* @brief store air temperature for program
	* @param airtemp - air temperature
	*/
	void setAirTemp(float airtemp);
	//getter
	/*
	 *@brief extract all sensor data from program to terminal
	*/
	void print();
	/**
	 * @brief extract speed from program
	 * @return int
	 */
	float getSpeed() const;
	/**
	 * @brief extract solar radtiation from program
	 * @return float
	 */
	float getSolarRad() const;
	/**
	 * @brief extract air temperature from program
	 * @return float
	 */
	float getAirTemp() const;


private:
	///wind speed in data
	float speed;
	///solar radiation in data
	float solar_radiation;
	/// air temperature in data
	float air_temperature;
};
#endif // !H_unit
