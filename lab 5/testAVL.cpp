//#pragma once
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <map>
//#include <vector>//#include "Vector.h"
//#include "AVL.h"
//#include "time.h"
//
//using namespace std;
//
//int testBSTClass() {
//	BST<int> IntTree;
//	BST<time> TimeTree;
//	time timeobj;
//
//	IntTree.insert(122);
//	IntTree.insert(123);
//	IntTree.insert(125);
//	IntTree.insert(12);
//	IntTree.insert(564);
//	IntTree.insert(54);
//	IntTree.preorderTraversal(); cout << endl;
//	IntTree.inorderTraversal(); cout << endl;
//	IntTree.postorderTraversal(); cout << endl;
//	//cout << "root:" << endl;
//	//IntTree.getRoot();//ptr to assign to var - cant print 
//	cout << "empty?" << IntTree.isEmpty() << endl;
//	cout << "search" << IntTree.search(54) << endl;
//	cout << endl;
//
//
//	//timeobj.setTime(13, 53);
//	//TimeTree.insert(timeobj);
//	TimeTree.insert(time(13, 53));
//	TimeTree.insert(time(3, 3));
//	TimeTree.insert(time(5, 5));
//	TimeTree.insert(time(26, 59));
//	TimeTree.insert(time(18, 34));
//	TimeTree.insert(time(9, 24));
//	TimeTree.insert(time(7, 55));
//	cout << "search "
//		<< TimeTree.search(time(7, 54)) << endl << "   "
//		<< TimeTree.search(time(7, 54)) << endl;
//	cout << "empty?" << TimeTree.isEmpty() << endl;
//	TimeTree.inorderTraversal();
//	cout << endl;
//	TimeTree.deleteNode(time(5, 5));
//	TimeTree.deleteNode(time(18, 34));
//	TimeTree.inorderTraversal();
//	cout << endl;
//	//TimeTree.preorderTraversal();
//	cout << endl;
//	//TimeTree.postorderTraversal();
//	cout << endl;
//	return 0;
//}