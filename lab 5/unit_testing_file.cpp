#pragma once
#include <iostream>
#include <fstream>
#include "date.h"
#include "time.h"
#include"Vector.h"

using namespace std;

//void menuOption2(Vector<WindlogType>& windlog) {
//	bool found = false;
//	int year_input, month_count = 1;//count the month of a year
//	cout << "enter year: "; cin >> year_input; cout << endl;
//
//	float involved_row = 0, sum_speed = 0, sum_air_temp = 0;/*for ave calculation*/
//	for (int i = 0; i < windlog.Size(); i++)//search whole dataset
//	{
//		if (windlog.at(i).d.getYear() == year_input)//found year
//		{
//			found = true;
//			if (month_count == windlog.at(i).d.getMonth()) {//calc month data
//				sum_speed = sum_speed + windlog.at(i).speed;
//				sum_air_temp = sum_air_temp + windlog.at(i).air_temperature;
//				involved_row++;
//			}
//			else if (month_count < windlog.at(i).d.getMonth()) {
//				if (sum_speed != 0) {//output
//					cout << month_to_int(month_count) << " " << year_input << ":";
//					printf(" %.1fkm/h, %.2f degrees C \n", (sum_speed / involved_row), (sum_air_temp / involved_row));
//					sum_speed = 0; involved_row = 0; sum_air_temp = 0;//reset value
//				}
//				else {//no data calculating
//					cout << month_to_int(month_count) << " " << year_input << ": No Data" << endl;
//				}
//				month_count++;
//			}
//			/*cout << month_to_int(month_count) << " " << year_input << ":";
//			printf(" %.1fkm/h, %.2f degrees C \n", (sum_speed / involved_row), (sum_air_temp / involved_row));
//			month_count++;*/
//		}
//	}
//	if (found == false) {//year no found
//		cout << "Year: " << year_input << ": No Data" << endl;
//	}
//	else {
//		cout << (sum_speed / involved_row) << ":" << month_count << endl;
//		while (month_count <= 12) {
//			//cout << month_to_int(month_count) << " " << year_input << ":";
//			printf(" %.1fkm/h, %.2f degrees C \n", (sum_speed / involved_row), (sum_air_temp / involved_row));
//			month_count++;
//		}
//	}
//}
//void menuOption3(Vector<WindlogType>& windlog) {
//	Process_data(windlog, 0, 1, 0, 1, 0, false);//use windlog data, take no month input ,take year input, no speed, has solar radiation, no tempertature, no file output
//}
//void menuOption4(Vector<WindlogType>& windlog) {
//	Process_data(windlog, 0, 1, 1, 1, 1, true);//use windlog data, take no month input ,take year input, has speed, has solar radiation, has tempertature, has file output
//}

int Unit_test() {
	//set value into objects
	//passed

	time timeobj;
	date dateobj;

	cout << "test the cimpliler of buggy vccomm " << endl << endl;
	timeobj.setHour(12); timeobj.setMin(04); timeobj.getHour();
	dateobj.setDay(42); dateobj.setMonth(23); dateobj.setYear(3285);
	cout << "show timeobj value: " << timeobj.getHour(); cout << " " << timeobj.getMin();
	cout << "\nshow dateobj value: " << dateobj.getDay(); cout << " " << dateobj.getMonth(); cout << " " << dateobj.getYear();
	cout << endl;
	timeobj.print();
	cout << endl;
	dateobj.print();
	cout << "\nend..." << endl;
	return 0;
}

int Unit_test2() {
	//this is very useful snippet to avoid GIGO
	//passed
	string filename;
	ifstream input; ofstream output_file;
	//system("dir");
	//test small file
	input.open("data/MetData_Mar01-2014-Mar01-2015-ALL.csv");// data/MetData_Mar01-2014-Mar01-2015-ALL.csv for full test. MetData-31-3.csv
	input.ignore(500, '\n'); //skip 1st line, till end of line
	//cout << input.peek();
	while (!input.eof()) {
		string temp;
		getline(input, temp, '\n');
		cout << temp << endl;// output till end of line
	}
	return 0;
	//just ~ cat data/MetData-31-3.csv (-.-)
}

int Unit_test3() {
	//this test vector function
	//passed
	Vector<int> intArray;
	intArray.push_back(1758);
	cout << intArray.getMaxLen() << endl;//expected 3 - default value
	intArray.push_back(12);
	cout << intArray.getMaxLen() << endl;//expected 6 - double max length
	cout << " " << intArray.Size() << endl;//expect 2
	intArray.push_back(98);
	intArray.push_back(1758);
	cout << intArray.getMaxLen() << endl;//expected 12 - double max length
	intArray.push_back(15);
	cout << " " << intArray.Size() << endl;//expect 5
	intArray.push_back(98);
	cout << intArray.at(4) << endl;//expect 15 or 1758

	Vector<date> dateArr;
	date dateTemp;
	dateTemp.setDate(12, 7, 5673);
	dateArr.push_back(dateTemp);
	cout << dateArr.getMaxLen() << endl;//expected 3 - default value
	dateTemp.setDate(01, 12, 1925);
	dateArr.push_back(dateTemp);
	cout << dateArr.getMaxLen() << endl;//expected 6 - doubled
	dateTemp.setDate(27, 1, 1999);
	dateArr.push_back(dateTemp);
	cout << " " << dateArr.Size() << endl;//expect 3
	dateArr.at(1).print();//expect day: 1 month: 12 year: 1925 
	return 0;
}
//
//int Unit_test4() {
//	//passed
//	Vector<WindlogType> windStructArr;
//	WindlogType struct1;
//	struct1.d.setDate(1, 2, 9021);
//	struct1.t.setTime(23, 54);
//	struct1.speed = 15;
//	windStructArr.push_back(struct1);
//	windStructArr.push_back(struct1);
//	struct1.d.setDate(12, 9, 431);
//	struct1.t.setTime(2, 35);
//	struct1.speed = 02;
//	windStructArr.push_back(struct1);
//	struct1.d.setDate(7, 5, 575);
//	struct1.t.setTime(6, 4);
//	struct1.speed = 0;
//	windStructArr.push_back(struct1);
//	windStructArr.push_back(struct1);
//	cout << " " << windStructArr.Size() << endl;//expect 5
//	cout << windStructArr.getMaxLen() << endl;//expected 12 - doubled
//	windStructArr.push_back(struct1);
//	windStructArr.push_back(struct1);
//	cout << windStructArr.at(3).d.getYear() << endl;//expect 575
//	windStructArr.at(3).t.print();//expect hour: 6 min: 4
//	return 0;
//	// Vector <<- struct <<- date, timeObj, speed <<- primitive_input
//}

int Unit_test5() {
	//process, split raw string 
	//passed
	string raw_data = "12/23/5754 16:23, 35,7,34,9.2,45,1,,\n13/3/1256 4:2,";
	string un_process_string = "12/23/5754 16:23, 35,7,34,9.2,45,1,,";
	cout << un_process_string.find("3") << endl;//get 1st orcurrence of " " -expect 4
	cout << un_process_string.substr(0, un_process_string.find("/")) << endl;//expect 12
	un_process_string = un_process_string.substr(un_process_string.find("/"), un_process_string.size());//this remove the readed part
	cout << un_process_string.substr(0, un_process_string.find(",")) << endl;//expect /23/7554 16:23
	un_process_string = un_process_string.substr(un_process_string.find(","), un_process_string.size());


	//singleLine.substr(0, singleLine.find(",");
	cout << un_process_string;
	return 0;
}
//previous unit testing fucntion will not work since it was originally placed in main -> moved here to clear main.cpp clutter
//any fucntion after this should work since this will be for assignment 2 unit test
