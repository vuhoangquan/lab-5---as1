#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Vector.h"
#include <vector>

using namespace std;

int testVectorDelete() {
	vector<float> HigestSRTime;
	HigestSRTime.push_back(123.15);
	HigestSRTime.push_back(14.56);
	HigestSRTime.push_back(235.54);
	HigestSRTime.push_back(46.34);
	cout<<HigestSRTime.size();
	cout<<" "<<HigestSRTime.at(0);

	HigestSRTime.~vector();
	cout<<" "<<HigestSRTime.size()<<endl;
	HigestSRTime.push_back(51.42);
	HigestSRTime.push_back(3.56);
	HigestSRTime.push_back(3.5);
	HigestSRTime.push_back(7.8);
	HigestSRTime.push_back(65.1);

	cout << " " << HigestSRTime.size() << endl;
	cout << " " << HigestSRTime.at(0);
	cout << " " << HigestSRTime.at(1);
	cout << " " << HigestSRTime.at(2);


	//Vector<float> HigestSRTime2;
	//HigestSRTime2.Push(123.15);
	//HigestSRTime2.Push(14.56);
	//HigestSRTime2.Push(235.54);
	//HigestSRTime2.Push(46.34);
	//cout<<" "<<HigestSRTime2.Size();
	//cout<<" "<< HigestSRTime2.at(0);

	//HigestSRTime2.~Vector();
	//cout<<" "<<HigestSRTime2.Size();
	//HigestSRTime2.Push(0.151);

	//cout<<" "<<HigestSRTime2.at(0);


	return 0;
}