#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>//#include "Vector.h"
#include "BST.h"
#include "time.h"
#include "date.h"

using namespace std;
//
//inline bool operator < (const date& lhs, const date& rhs) {
//	if (lhs.getYear() < rhs.getYear()) {
//		return true;
//	}
//	else if (lhs.getYear() == rhs.getYear()) {
//		if (lhs.getMonth() < rhs.getMonth()) {
//			return true;
//		}
//		else if (lhs.getMonth() == rhs.getMonth()) {
//			if (lhs.getDay() < rhs.getDay()) {
//				return true;
//			}
//			else {
//				return false;
//			}
//		}
//		else { return false; }
//	}
//	else {
//		return false;
//	}
//}
//
//inline bool operator == (const date& lhs, const date& rhs) {
//	if (lhs.getYear() == rhs.getYear()) {
//		if (lhs.getMonth() == rhs.getMonth()) {
//			if (lhs.getDay() == rhs.getDay()) {
//				return true;
//			}
//			else { return false; }
//		}
//		else { return false; }
//	}
//	else { return false; }
//}



int testBSTClass() {
	BST<int> IntTree;
	BST<time> TimeTree;
	BST<date> DateTree;

	date dateobj(12,10,1993);
	cout << dateobj.getDateAsInt() << endl;

	IntTree.insert(122);
	IntTree.insert(123);
	IntTree.insert(125);
	IntTree.insert(12);
	IntTree.insert(564);
	IntTree.insert(54);
	IntTree.preorderTraversal(); cout << endl;
	IntTree.inorderTraversal(); cout << endl;
	IntTree.postorderTraversal(); cout << endl;
	//cout << "root:" << endl;
	//IntTree.getRoot();//ptr to assign to var - cant print 
	cout << "empty?" << IntTree.isEmpty() << endl;
	cout << "search" << IntTree.search(54) << endl;
	cout << endl;


	//timeobj.setTime(13, 53);
	//TimeTree.insert(timeobj);

	TimeTree.insert(time(13, 53));
	TimeTree.insert(time(12, 53));
	TimeTree.insert(time(3, 3));
	TimeTree.insert(time(5, 5));
	TimeTree.insert(time(26, 59));
	TimeTree.insert(time(18, 34));
	TimeTree.insert(time(9, 24));
	TimeTree.insert(time(7, 55));
	cout << "search "
		<< TimeTree.search(time(7, 54)) << endl << "   "
		<< TimeTree.search(time(7, 54)) << endl;
	cout << "empty?" << TimeTree.isEmpty() << endl;
	TimeTree.inorderTraversal();
	cout << endl;
	TimeTree.deleteNode(time(5, 5));
	TimeTree.deleteNode(time(18, 34));
	TimeTree.inorderTraversal();
	cout << endl;
	//TimeTree.preorderTraversal();
	cout << endl;
	//TimeTree.postorderTraversal();
	cout << endl;

	DateTree.insert(date(12, 10, 2003));
	DateTree.insert(date(13, 6, 2003));
	DateTree.insert(date(12, 11, 2003));
	DateTree.insert(date(12, 10, 2001));
	DateTree.insert(date(12, 1, 2008));
	DateTree.insert(date(6, 20, 1953));
	DateTree.insert(date(12, 10, 2003));
	DateTree.insert(date(12, 553, 2003));
	DateTree.insert(date(1, 10, 2003));
	DateTree.inorderTraversal(); cout << endl;
	cout << "search: " << DateTree.search(date(1, 10, 2003)) << endl;

	DateTree.preorderTraversal(); cout << endl;
	DateTree.deleteNode(date(12, 10, 2003));
	DateTree.deleteNode(date(1, 10, 2003));// this wont run because root has been deleted
	DateTree.inorderTraversal(); cout << endl;

	cout << "\n ///complex map  with BST as key \n" << endl;//integrate BST and MAP
	cout << "\n ..can not compile.. \n" << endl;
	//map<date, int> MapBST;
	//MapBST[DateTree.getInfo(date(12, 10, 2003))] = 2123;
	//MapBST[DateTree.getInfo(date(13, 6, 2003))] = 10;
	//MapBST[DateTree.getInfo(date(12, 10, 2001))] = 2123;
	//MapBST[DateTree.getInfo(date(6, 20, 1953))] = 201535;
	//MapBST[DateTree.getInfo(date(12, 553, 2003))] = 245;

	//map<date, int>::iterator itr222;
	//for (itr222 = MapBST.begin(); itr222 != MapBST.end(); ++itr222)
	//{
	//	itr222->first.getYear();cout << "  ";
	//	itr222->first.getMonth();
	//	cout << endl;
	//	cout << itr222->second << " " << "\n";
	//}
	return 0;
}