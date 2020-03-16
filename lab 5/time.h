#pragma once
//-------------------------------------------------------------------------
#ifndef H_time //if not define
#define H_time
//-------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
//-------------------------------------------------------------------------
/**
 * @class time
 * @brief manages hours and minutes in program
 *
 *
 */
class time {
	/**
	 * @brief overload input and output to show, store all time info
	 */
	 //friend ostream& operator << (ostream&, const time&);//declaration (of vector?)
	 //friend istream& operator >> (istream&, time&);
public:
	/**
	 * @brief set default value for hour and minute
	 */
	time();
	/**
	 * set hour and min
	 * @param hh - hour, mm - minute
	 */
	time(int hh, int mm);
	~time(); //destructor

	//setters
	/**
	 * @brief store hour and minute to program
	 * @param hr - hour, mm - minute
	 */
	void setTime(int hr, int mm);
	/**
	 * @brief store hour  to program
	 * @param hr - hour
	 */
	void setHour(int hr);
	/**
	 * @brief store minute  to program
	 * @param mm - minute
	 */
	void setMin(int mm);
	//getter
	/*
	 *@brief extract hour,min from program
	*/
	void print();
	/**
	 * @brief extract hour from program
	 * @return int
	 */
	int getHour() const;
	/**
	 * @brief extract minute from program
	 * @return int
	 */
	int getMin() const;
	//printf
	/**
	 * @brief show hour and minute to program
	 * @return void
	 */

private:
	///hour in data
	int Hour;
	///minute in data
	int Min;
};
#endif // !H_time
