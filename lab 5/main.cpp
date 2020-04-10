//main 
#pragma once
#include <iostream>
#include <string>// string included not basic string
#include <fstream>// file stream for file read write
#include "time.h"
#include "date.h"
#include "unit.h"
#include "Vector.h"//capital V to distinguish from STL vector
#include "BST.h"
#include <map>
//-------------------------------------------------------------------------
///Struct that store date, time, sensor data named as Unit
typedef struct {
	date* d;
	time* t;
	unit* u;
} WindlogType;

using namespace std;
//-------------------------------------------------------------------------
//declare functions
string month_to_int(int monthParam);
float Wh_to_kWh(float watt_per_min);
float Kmh_to_Ms(float speed_kmh);
void Print_partData(Vector<WindlogType>& windlog);
void Process_data(Vector<WindlogType>& windlog, BST<date>& SearchTree, map<int, int>& IndexMap, int month_input, int year_input, int s, int sr, int t, bool file_output);
void ShowDataOfAMthOfYear(Vector<WindlogType>& windlog);
void Menu(Vector<WindlogType>& windlog, BST<date>& SearchTree, map<int, int>& IndexMap);
void ReadFile(Vector<WindlogType>& windlog);
void SplitString(string singleLine, WindlogType& StructWind);
static void DisplayMenu();
static void ReadMetIndex(Vector<string>& FileVector);
bool SearchString(string singleline, string searchWord);
void IndexMonthYear(Vector<WindlogType>& windlog, BST<date>& SearchTree, map<int, int>& IndexMap);
bool checkNA(string line);
int searchBSTTime(int year_input, BST<date>& SearchTree, map<int, int>& IndexMap);


int testUnitClass();
int testMap();
int testBSTClass();
int testUnitClass();
//-------------------------------------------------------------------------

int main() {
	//testMap();
	//testBSTClass();
	//system("pause");
	//return 0;
	Vector<WindlogType> windlog;
	BST<date> SearchTree;
	map<int, int> IndexMap;


	ReadFile(windlog);
	IndexMonthYear(windlog, SearchTree, IndexMap);

	////test BST and STL map integration
	//cout << endl;
	//SearchTree.inorderTraversal();
	cout << endl;
	map<int, int>::iterator itrr;
	for (itrr = IndexMap.begin(); itrr != IndexMap.end(); ++itrr)
	{
		cout << itrr->first << " " << itrr->second << "\n";
	}
	//cout << endl;
	////test searchBSTTime and map get Vector data
	//int testINtSPecial = 0;
	//testINtSPecial = searchBSTTime(2012, SearchTree, IndexMap);
	//cout << testINtSPecial << endl;

	DisplayMenu();
	Menu(windlog, SearchTree, IndexMap);

	system("pause");
	return 0;
}
//-------------------------------------------------------------------------
///insert data from vector into BST and STL map
void IndexMonthYear(Vector<WindlogType>& windlog, BST<date>& SearchTree, map<int, int>& IndexMap) {
	bool year_changed = false, month_changed = false;
	int var_year = 0, var_month = 0;
	var_year = windlog.at(0).d->getYear();
	var_month = windlog.at(0).d->getMonth();
	//create date obj -> BST is aggregation of Vector
	date dateobj(windlog.at(0).d->getDay(), windlog.at(0).d->getMonth(), windlog.at(0).d->getYear());

	//add 1st rows in Vector to BST and map
	SearchTree.insert(dateobj);
	IndexMap.insert(pair<int, int>(dateobj.getDateAsInt(), 0));

	for (int i = 1; i < windlog.Size(); i++)//search whole dataset
	{
		//cout << windlog.at(i).d->getYear();
		if (var_month != windlog.at(i).d->getMonth() || var_year != windlog.at(i).d->getYear()) {
			month_changed = true;//if a year changed than month also changed

			//add into BST and STL map 
			dateobj.setDate(windlog.at(i).d->getDay(), windlog.at(i).d->getMonth(), windlog.at(i).d->getYear());
			SearchTree.insert(dateobj);
			IndexMap.insert(pair<int, int>(windlog.at(i).d->getDateAsInt(), i));
		}
		var_year = windlog.at(i).d->getYear();
		var_month = windlog.at(i).d->getMonth();
	}
}
//-------------------------------------------------------------------------
static void DisplayMenu() {
	cout << "---------------\nMENU: \n 1. show data from a month of a year \n 2. show data from a year \n 3. show data from a year \n 4. export data from a year to WindTempSolar.csv file \n 5. exit program \n---------------\n";
};
//-------------------------------------------------------------------------
///read txt file and get all datafile name store in a Vector
static void ReadMetIndex(Vector<string>& FileVector) {
	ifstream input;
	int j = 0;
	string FileArray[10] = { "","","","","","","","","","" };
	string* FileArrayPtr = new string[10];
	FileArrayPtr = FileArray;

	input.open("data/met_index.txt");
	while (!input.eof()) {

		getline(input, FileArray[j], '\n');//read filename from a met index
		FileArray[j] = "data/" + FileArray[j];//add data / to filename
		FileVector.push_back(*FileArrayPtr);//add into array to return
		FileArrayPtr++;//move pointer to next location
		j++;
	}
	input.ignore(100);

	if (input.is_open()) { input.close(); }
	//++++++++++++++++++++++++++++++++++++++++++++++++++++
	cout << "files name in met_index.txt:" << endl;
	for (int counting = 0; counting < FileVector.Size(); counting++) {
		//cout << FileArray[counting] << endl;
		cout << FileVector.at(counting) << endl;
	}
}
//-------------------------------------------------------------------------
string month_to_int(int monthParam)
{ //procedure to change from month(int) to month(full)
	switch (monthParam)
	{
	case 1:
		return "January";
		break;
	case 2:
		return "February";
		break;
	case 3:
		return "March";
		break;
	case 4:
		return "April";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "June";
		break;
	case 7:
		return "July";
		break;
	case 8:
		return "August";
		break;
	case 9:
		return "September";
		break;
	case 10:
		return "October";
		break;
	case 11:
		return "November";
		break;
	case 12:
		return "December";
		break;
	default:
		return "wrong_month";
		break;
	}
}
//-------------------------------------------------------------------------
float Wh_to_kWh(float watt_per_min) {
	return (watt_per_min / 6000.0);
}
//-------------------------------------------------------------------------
float Kmh_to_Ms(float speed_kmh) {
	return speed_kmh * 0.27778;
}
//-------------------------------------------------------------------------
void Print_partData(Vector<WindlogType>& windlog) {
	for (int i = 0; i < 30; i++) {
		cout << "print_check 30 nodes for vector:" << windlog.at(i).u->getSpeed() << ":" << windlog.at(i).u->getSolarRad() << ":" << windlog.at(i).u->getAirTemp() << endl;
	}
}
//-------------------------------------------------------------------------
///input string and a search Key Word, if keyword is found return true
bool SearchString(string singleline, string searchWord) {
	size_t found = singleline.find(searchWord);
	if (found != std::string::npos)
	{
		cout << "first " + searchWord + " is found at: " << found << '\n';
		string newsingleline = " ";
		swap(newsingleline, singleline);
		return true;
	}
	else {
		//cout << "searched " + searchWord + " not found" << endl;
		return false;
	}
}
//-------------------------------------------------------------------------
///search BST if its found then ref to map and get at(location) from there to return 
int searchBSTTime(int year_input, BST<date>& SearchTree, map<int, int>& IndexMap) {

	date dateobj(1, 1, year_input);
	if (SearchTree.search(dateobj) == true) {
		return (IndexMap.find(dateobj.getDateAsInt())->second);
	}
	else { //search BST == false
		//search next month
		for (int j = 0; j < 50; j++) {
			dateobj.setYear(year_input + j);
			for (int k = 1; k < 12; k++) {
				dateobj.setMonth(k);
				if (SearchTree.search(dateobj) == true) {
					return (IndexMap.find(dateobj.getDateAsInt())->second);
				}
			}
		}
		return 0;
	}
}
//-------------------------------------------------------------------------
void Process_data(Vector<WindlogType>& windlog, BST<date>& SearchTree, map<int, int>& IndexMap, int month_input, int year_input, int s, int sr, int t, bool file_output) {
	bool found = false;//indicate if search has any matching row
	int month_count = 1;//check from month 1 to 12
	ofstream output_file;//output file stream to .csv
	if (file_output == true) { output_file.open("data/WindTempSolar.csv"); }
	if (year_input == 1) { cout << "enter year: "; cin >> year_input; }
	if (month_input == 1) { cout << "enter month: "; cin >> month_count; }

	float involved_row = 0, sum_speed = 0, sum_solar_radatiation = 0, sum_air_temp = 0;/*for ave calculation*/
	//always output once
	cout << year_input << ":" << endl;
	output_file << year_input << ",\n";
	//search BST
	int search_from = 0, search_until = windlog.Size();
	search_from = searchBSTTime(year_input, SearchTree, IndexMap);
	search_until = searchBSTTime(year_input + 1, SearchTree, IndexMap);
	//cout <<"search from:"<< search_from <<". search  until:"<< search_until<<" \n";
	for (int i = search_from; i < search_until; i++)//search from the 1st rows that match inputted year
	{
		if (windlog.at(i).d->getYear() == year_input)//found year
		{
			found = true;
			if (month_count == windlog.at(i).d->getMonth()) {//calc month data
				if (s == 1) { sum_speed = sum_speed + windlog.at(i).u->getSpeed(); }
				if (sr == 1) { sum_solar_radatiation = sum_solar_radatiation + windlog.at(i).u->getSolarRad(); }
				if (t == 1) { sum_air_temp = sum_air_temp + windlog.at(i).u->getAirTemp(); }
				involved_row++;
			}
			else if (month_count < windlog.at(i).d->getMonth()) {
				if (sum_speed != 0 || sum_solar_radatiation != 0 || sum_air_temp != 0) {//output if some data is calculated
					cout << month_to_int(month_count) << " " << year_input << ":";
					if (s == 1) { printf(" %.1f km/h, ", (sum_speed / involved_row)); }
					if (sr == 1) { printf(" %.4f kWh/m2, ", Wh_to_kWh(sum_solar_radatiation / involved_row)); }
					if (t == 1) { printf(" %.2f degrees C ", (sum_air_temp / involved_row)); }
					cout << endl;
					if (file_output == true) {
						//print to file
						output_file << month_to_int(month_count) << "," << (sum_speed / involved_row) << "," << Wh_to_kWh(sum_solar_radatiation / involved_row) << "," << (sum_air_temp / involved_row) << "\n";
					}
					sum_speed = 0; involved_row = 0, sum_solar_radatiation = 0, sum_air_temp = 0;//reset value
				}
				else {//no data calculating 
					if (month_input != 1) {//run when only year is entered
						cout << month_to_int(month_count) << " " << year_input << ":1 No Data" << endl;
						if (file_output == true) {
							//print no data to file
							output_file << month_to_int(month_count) << "," << "nodata" << "\n";
						}
					}
				}
				month_count++;
			}
		}
		else {//if founded year and now the rows's year not match -> calc and output done -> skip all rows of other year

		}

	}
	//after search endded
	if (found == false) {//year not found - print "(month) year no data"
		if (month_input != 0) { cout << month_to_int(month_count) << " " << year_input << ":2 No Data" << endl; }
		else { cout << "Year: " << year_input << ": No Data" << endl; }
	}
	else {//if year found and output previous month done
		if (month_input == 0) {//if option require output for every month of a year --> apply for option 2,3,4
			if (sum_speed != 0 || involved_row != 0 || sum_solar_radatiation != 0 || sum_air_temp != 0) {// some calc has not output
				//print last month average
				cout << month_to_int(month_count) << " " << year_input << ":";
				if (s == 1) { printf(" %.1f km/h, ", (sum_speed / involved_row)); }
				if (sr == 1) { printf(" %.4f kWh/m2, ", Wh_to_kWh(sum_solar_radatiation / involved_row)); }
				if (t == 1) { printf(" %.2f degrees C ", (sum_air_temp / involved_row)); }
				cout << endl;
				if (file_output == true) {
					//print to file
					output_file << month_to_int(month_count) << "," << (sum_speed / involved_row) << "," << Wh_to_kWh(sum_solar_radatiation / involved_row) << "," << (sum_air_temp / involved_row) << "\n";
				}
				sum_speed = 0; involved_row = 0, sum_solar_radatiation = 0, sum_air_temp = 0;//reset value
				month_count++;
			}
			while (month_count <= 12) {//repeat print " no data" for all month that dont have data 
				cout << month_to_int(month_count) << " " << year_input << ":3 No Data" << endl;
				//print no data to file
				if (file_output == true) { output_file << month_to_int(month_count) << "," << "nodata" << "\n"; }
				month_count++;
			}
		}
	}
}
//-------------------------------------------------------------------------
///this is very different to other option so process_data function will not handle option 1
void ShowDataOfAMthOfYear(Vector<WindlogType>& windlog) {
	bool found = false;
	int month_input, year_input;
	cout << "enter year: "; cin >> year_input;
	cout << "enter month: "; cin >> month_input;
	float involved_row = 0, sum_speed = 0, sum_air_temp = 0;/*for ave calculation*/
	for (int i = 0; i < windlog.Size(); i++)//search whole dataset
	{
		if ((windlog.at(i).d->getMonth()) == month_input && (windlog.at(i).d->getYear()) == year_input)//found month, year
		{
			sum_speed = sum_speed + windlog.at(i).u->getSpeed();
			sum_air_temp = sum_air_temp + windlog.at(i).u->getAirTemp();
			involved_row++;
			found = true;
		}
	}
	if (found == false) {
		cout << month_to_int(month_input) << " " << year_input << ": No Data" << endl;
	}
	else {//output..
		cout << month_to_int(month_input) << " " << year_input << ":";
		printf(" %.1fkm/h, %.2f degrees C \n", (sum_speed / involved_row), (sum_air_temp / involved_row));
		//if (month_input == windlog.at(windlog.Size()).d.getMonth() && year_input==year_input + 1/*last month of file - each file only have 2 years*/) {
		//	cout << month_to_int(month_input) << " " << year_input << ":m01 No Data" << endl;
		//}
	}
}
//-------------------------------------------------------------------------
void Menu(Vector<WindlogType>& windlog, BST<date>& SearchTree, map<int, int>& IndexMap) {
	cout << "Menu Option:";
	bool repeat = true;
	while (repeat) {//loop till specific states "break;"
		cout << "\nPlease enter an number 1 - 5:  ";
		string input;
		cin >> input;
		if (input == "1") {
			ShowDataOfAMthOfYear(windlog);
			//Process_data(windlog, 1, 1, 1, 0, 1, false);//use windlog data, take no month input ,take year input, speed, no solar radiation, has tempertature, no file output
		}
		else if (input == "2") {
			Process_data(windlog, SearchTree, IndexMap, 0, 1, 1, 0, 1, false);//use windlog data, take no month input ,take year input, no speed, has solar radiation, no tempertature, no file output
		}
		else if (input == "3") {
			Process_data(windlog, SearchTree, IndexMap, 0, 1, 0, 1, 0, false);//use windlog data, take no month input ,take year input, no speed, has solar radiation, no tempertature, no file output
		}
		else if (input == "4") {
			Process_data(windlog, SearchTree, IndexMap, 0, 1, 1, 1, 1, true);//use windlog data, take no month input ,take year input, has speed, has solar radiation, has tempertature, has file output
		}
		else if (input == "6") {
			cout << "program exit.......  ";
			repeat = false;
		}
		else if (input == "5") {

		}
		else {
			cout << "input can only number 1, 2, 3, 4, 5 as specified!";
		}
	}
}
//-------------------------------------------------------------------------
void ReadFile(Vector<WindlogType>& windlog) {
	//read file 
	ifstream input; ofstream output_file;
	//system("dir");
	Vector<string> file_list;
	ReadMetIndex(file_list);
	for (int fileloop = 0; fileloop < file_list.Size(); fileloop++) {
		input.open(file_list.at(fileloop));
		//data/MetData-31-3.csv -- sample
		//data/MetData_Mar01-2015-Mar01-2016-ALL.csv

		input.ignore(500, '\n'); //skip 1st line, till end of line
		int count_line = 0;// for debug line
		string TrailSingleLine = "";
		while (!input.eof()) {
			count_line++;// cout << count_line << endl;
			string singleLine;
			WindlogType StructWind;
			getline(input, singleLine, '\n');

			//value checking for what is in the input_file (GIGO)
			if (singleLine == "" || singleLine == " ") {
				break;
			}

			//add to data structure
			SplitString(singleLine, StructWind);
			//add into windlog Vector
			windlog.push_back(StructWind);
			//compare with prev rows for mth change and yr change


		//test check
		//cout << " ssay " << sDay;
		//cout << "    smoth " << sMonth;
		//cout << "    syear " << sYear;
		//cout << "    shh " << sHH;
		//cout << "    smm " << sMM << endl;
		//cout << " ssay " << t_day;
		//cout << "    smoth " << t_month;
		//cout << "    syear " << t_year;
		//cout << "    shh " << t_hour;
		//cout << "    smm " << t_min << endl;
		//cout << "singleline:     " << singleLine << endl;//this should be all the sensor no
		//cout << "   Struct date: "; StructWind.d.print();
		//cout << "   Struct time: "; StructWind.t.print();
		//cout << "   Struct speed:" << StructWind.speed << endl;
		//windlog.at(0).d.print();
		//cout<<" "<<windlog.at(0).speed<<" ";
		//cout<<windlog.Size()<<" ";
		//cout<<windlog.getMaxLen()<<" ";
		}
		input.close();
		//test check
		/*cout<<"size "<<windlog.Size()<<" ";
		windlog.at(windlog.Size() - 1).t.print(); cout<< " ";
		windlog.pop();
		cout << "size " << windlog.Size() << " ";
		windlog.at(windlog.Size() - 1).t.print();*/
		// Vector <<- struct <<- date, timeObj, speed <<- primitive_input
	}
}
//-------------------------------------------------------------------------
bool checkNA(string line) {
	size_t found = line.find("N/A");
	if (found != std::string::npos)
	{
		cout << "first N/A is found at: " << found << '\n';
		if (found == 0) {
			return true;
		}
		else { return false; }
	}
	else { return false; }
}
//-------------------------------------------------------------------------
void SplitString(string singleLine, WindlogType& StructWind) {
	///process file string, convert into compatible type (stoi), create date time class, added to struct
	string sDay = "", sMonth = "", sYear = "", sHH = "", sMM = "";//string of date,mth,year,hour,min
	//read 1 singleline into date, month, year, hour, min as string
	sDay = singleLine.substr(0, singleLine.find("/"));//this read into date string
	singleLine = singleLine.substr(singleLine.find("/") + 1, singleLine.size());//this remove the read part, AND the delimiter Symbol
	sMonth = singleLine.substr(0, singleLine.find("/"));//this read into month string
	singleLine = singleLine.substr(singleLine.find("/") + 1, singleLine.size());
	sYear = singleLine.substr(0, singleLine.find(" "));//this read into year string
	singleLine = singleLine.substr(singleLine.find(" ") + 1, singleLine.size());
	sHH = singleLine.substr(0, singleLine.find(":"));//this read into hour string
	singleLine = singleLine.substr(singleLine.find(":") + 1, singleLine.size());
	sMM = singleLine.substr(0, singleLine.find(","));//this read into min string
	singleLine = singleLine.substr(singleLine.find(",") + 1, singleLine.size());

	//store date, time var as int
	int t_day, t_month, t_year, t_hour, t_min;
	//change date, time string into int
	t_day = stoi(sDay);
	t_month = stoi(sMonth);
	t_year = stoi(sYear);
	t_hour = stoi(sHH);
	t_min = stoi(sMM);
	//read sensor data
	unit* UnitPtr = new unit();

	//// **/**/**** **:**,DP,Dta,Dts,EV,QFE,QFF,QNH,RF,RH,S,SR,ST1,ST2,ST3,ST4,Sx,T
	////				  0 ,1  ,2  ,3 ,4  ,5  ,6  ,7 ,8 ,9,10,11 ,12 ,13 ,14 ,15,16,\n
	for (int i = 0; i <= 17; i++) {
		if (i == 9) {
			if (checkNA(singleLine) == true) { UnitPtr->setSpeed(0); }
			UnitPtr->setSpeed(stof(singleLine.substr(0, singleLine.find(","))));
		}
		else if (i == 10) {
			if (checkNA(singleLine) == true) { UnitPtr->setSolarRad(0); }
			UnitPtr->setSolarRad(stof(singleLine.substr(0, singleLine.find(","))));
		}
		else if (i == 17) {
			if (checkNA(singleLine) == true) { UnitPtr->setAirTemp(0); }
			UnitPtr->setAirTemp(stof(singleLine.substr(0, singleLine.find(","))));
		}
		singleLine = singleLine.substr(singleLine.find(",") + 1, singleLine.size());
	}
	date* datePtr = new date(t_day, t_month, t_year);
	time* timePtr = new time(t_hour, t_min);
	StructWind.d = datePtr;
	StructWind.t = timePtr;
	StructWind.u = UnitPtr;
}
//-------------------------------------------------------------------------