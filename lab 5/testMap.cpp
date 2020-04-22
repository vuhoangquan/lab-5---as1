#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "date.h"
#include "time.h"

typedef struct{
	date* d;
    class time* t;

} dateTimeType;

//typedef struct {
//	date d;
//	time t;
//
//} dateTimeType2;


inline bool operator < (const dateTimeType& lhs, const dateTimeType& rhs) {
	if (lhs.d < rhs.d) {
		return true;
	}
	else if (lhs.d == rhs.d) {
		if (lhs.t < rhs.t) {
			return true;
		}
		else { return false; }
	}
	else {
		return false;
	}
}

inline bool operator == (const dateTimeType& lhs, const dateTimeType& rhs) {
	if (lhs.d == rhs.d) {
		if (lhs.t == rhs.t) {
			return true;
		}
		else {return false;}
	}
	else { return false; }
}

using namespace std;

int testMap() {
	//primitive data type map
	map<string, int> myMap;
	//insert value into map
	myMap.insert(pair<string, int>("John", 200));
	myMap.insert(pair<string, int>("Jill", 300));
	myMap.insert(pair<string, int>("TOm", 50));
	myMap.insert(pair<string, int>("May", 10));
	myMap.insert(pair<string, int>("John", 300));
	
	//define interrator called "it"
	map<string, int>::iterator it;
	for (it = myMap.begin(); it != myMap.end(); ++it)
	{
		cout << it->first << " " << it->second << "\n";
	}
	myMap.erase("TOm");
	cout << myMap.find("John")->second << endl;

	for (it = myMap.begin(); it != myMap.end(); ++it)
	{
		cout << it->first << " " << it->second << "\n";
	}
	cout << endl << endl;


	//complex map
	map<int, dateTimeType> map02;
	dateTimeType Struct_01;
	date* datePtr01 = new date(12, 10, 1998);
    class time* timePtr01 = new class time(12, 1);
	Struct_01.d = datePtr01;
	Struct_01.t = timePtr01;
	map02[1245] = Struct_01;
	map02.insert(pair<int, dateTimeType>(915, Struct_01));//equalvilent with line above

	dateTimeType Struct_02;
	date* datePtr02 = new date(6, 0, 1582);
    class time* timePtr02 = new class time(23, 59);
	Struct_02.d = datePtr02;
	Struct_02.t = timePtr02;
	map02[5132] = Struct_02;
	map02.insert(pair<int, dateTimeType>(916, Struct_02));

	dateTimeType Struct_03;
	date* datePtr03 = new date(26, 10, 1500);
    class time* timePtr03 = new class time(04, 52);
	Struct_03.d = datePtr03;
	Struct_03.t = timePtr03;
	map02[5132] = Struct_03;

	map<int, dateTimeType>::iterator it02;
	for (it02 = map02.begin(); it02 != map02.end(); ++it02)
	{
		cout << it02->first << " " << "\n";
		it02->second.d->print(); cout << endl;
		it02->second.t->print(); cout << endl;
	}

	cout << "\n ///complex map 2 \n" << endl;//complex map
	map<dateTimeType, int> map2;
	dateTimeType Struct_1;
	date* datePtr1 = new date(12, 10, 1998);
    class time* timePtr1 = new class time(12, 1);
	Struct_1.d = datePtr1;
	Struct_1.t = timePtr1;
	map2[Struct_1] = 1244;

	map2.insert(pair<dateTimeType, int>(Struct_1, 2135));

	dateTimeType Struct_2;
	date* datePtr2 = new date(6, 0, 1582);
    class time* timePtr2 = new class time(23, 59);
	Struct_2.d = datePtr2;
	Struct_2.t = timePtr2;
	map2[Struct_2] = 158;

	dateTimeType Struct_3;
	date* datePtr3 = new date(2, 10, 2020);
    class time* timePtr3 = new class time(12, 02);
	Struct_3.d = datePtr3;
	Struct_3.t = timePtr3;
	map2[Struct_3] = 25135;

	dateTimeType Struct_4;
	date* datePtr4 = new date(2, 10, 2020);
    class time* timePtr4 = new class time(02, 61);
	Struct_4.d = datePtr4;
	Struct_4.t = timePtr4;
	map2[Struct_4] = 25135;

	dateTimeType Struct_5;
	date* datePtr5 = new date(2, 9, 2020);
    class time* timePtr5 = new class time(12, 02);
	Struct_5.d = datePtr5;
	Struct_5.t = timePtr5;
	map2[Struct_5] = 25135;

	map<dateTimeType, int>::iterator it2;
	for (it2 = map2.begin(); it2 != map2.end(); ++it2)
	{
		it2->first.d->print(); cout << endl;
		it2->first.t->print(); cout << endl;
		cout << it2->second << " "  << "\n";
	}
	//-> map output with random order; inline operator overloading failed?
	//=> conclusion: complex map cannot have struct as a key
	

	system("pause");
	return 0;

	//map<dateTimeType, int> map2;
	//dateTimeType Struct_1;
	//Struct_1.d->setDate(12, 10, 1998);
	//Struct_1.t->setTime(12, 10);
	//map2[Struct_1] = 100;

	//Struct_1.d->setDate(14, 10, 1998);
	//Struct_1.t->setTime(1, 10);
	//map2[Struct_1] = 20;

	//map<dateTimeType, int>::iterator it2;
	//for (it2 = myMap.begin(); it2 != myMap.end(); ++it2)
	//{
	//	cout << it2->first << " " << it2->second << "\n";
	//}
}
