#pragma once
//-------------------------------------------------------------------------
#ifndef H_date //if not define
#define H_date
//-------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
//-------------------------------------------------------------------------
/**
 * @class date
 * @brief manages date, month, year data in program
 *
 *
 */
class date {
	/**
	 * @brief  overload input and output to show, store all date info
	 *
	 */
	friend ostream& operator << (ostream&, const date&);
	friend istream& operator >> (istream&, date&);
public:
	bool operator < (date& rhs)const;
	bool operator == (date& rhs)const;
	date& operator = (const int rhs);
	/**
	 * @brief set default value for all date data
	 */
	date();
	/**
	 * @brief  set date month year
	 * @param  dd - date, mm - month, yyyy - year from dataset
	 *
	 */
	date(int dd, int mm, int yyyy);
	~date(); //destructor

	//setters
	/**
	 * @brief  store date to program
	 * @param  dd - date in dataset
	 * @return void
	 */
	void setDay(int dd);
	/**
	 * @brief  store month to program
	 * @param  mm - month in dataset
	 * @return void
	 */
	void setMonth(int mm);
	/**
	 * @brief  store year to program
	 * @param  yyyy - year in dataset
	 * @return void
	 */
	void setYear(int yyyy);
	/**
	 * @brief  store date, month, year to program
	 * @param  dd - date, mm - month, yyyy - year in dataset
	 * @return void
	 */
	void setDate(int dd, int mm, int yyyy);

	//getter
	/**
	* @brief extract date,month,year from program
	*/
	void print();
	/**
	 * @brief extract date from program
	 * @return int
	 */
	int getDay() const;
	/**
	 * @brief extract month from program
	 * @return int
	 */
	int getMonth() const;
	/**
	 * @brief extract year from program
	 * @return int
	 */
	int getYear() const;

	int getDateAsInt();

private:
	///date of recorded data
	int Date;//data members
	///month of recorded data
	int Month;
	///year of recorded data
	int Year;
};
#endif // !H_date
