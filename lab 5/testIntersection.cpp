#pragma once 
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Set.h"

using namespace std;


int IntersectionTest() {
	Set<float> Set1;
	Set1.Insert(2.4);
	//Set1.Insert(2.4);
	Set1.Insert(5.4);
	Set1.Insert(9.9);
	Set1.Insert(18.4);
	Set1.Insert(22.4);
	cout << Set1.Size() << endl;

	/*for (int i = 0; i < Set1.Size(); i++) {
		cout << Set1.at(i) << endl;
	}*/

	Set<float> Set2;
	Set2.Insert(2.4);
	Set2.Insert(3.3);
	Set2.Insert(5.2);
	Set2.Insert(9.9);
	Set2.Insert(18.4);
	Set2.Insert(22.4);
	Set<float> newSet;
	try {
		Set1.intersection(Set2, newSet);
	}
	catch (int e) {
		cout << "err" << endl;
	}
	for (int k = 0; k < newSet.Size(); k++) {
		cout << newSet.at(k)<<" ";
	}
	cout << endl;
	return 0;
}