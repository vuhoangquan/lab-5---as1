
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#define DEFAULT_SIZE 3
#define MAX_SIZE 1000000
using namespace std;
// The class declaration must have doxygen comments – put these in

template <class T>
class Vector{
public:
	Vector(int length = DEFAULT_SIZE);
	~Vector();

	// basic
	int Size() { return len; };
	int isEmpty() { return len == 0; };
	void push_back(T item);
	// added minimum
	T& at(int i);
	//void resize(int newSize);
	//optional
	void pop();
	//test

	int getMaxLen() { return maxLen; };
private:
	void resize(int newSize);
	T* list;
	int len;
	int maxLen;// store the ma
	// void resize();
	// void resize(int s);
};

template <class T>
Vector<T>::Vector(int length)
{
	if (length <= 0)
	{
		cout << "Vector size must be positive" << endl;
		maxLen = DEFAULT_SIZE;
	}
	else {
		maxLen = length;
	}
	len = 0;// Vector is empty at first
	list = new T[maxLen];
}

template <class T>
Vector<T>::~Vector()
{
	if (list != nullptr)
	{
		delete[] list;
		list = nullptr;
	}
}

template <class T>
void Vector<T>::resize(int newSize) 
{
	T* newList = new T[maxLen];
	T* newListP = newList;
	T* oldListP = list;
	while (oldListP != (list + len)) {//while != last address of list
		*(newListP) = *(oldListP);
		newListP++;//move to next location/address
		oldListP++;
	}//this loop swap value until the last location of list
	maxLen = newSize;
	delete[] list;
	list = newList;
}

template <class T>
void Vector<T>::push_back(T item)
{
	if (len >= maxLen / 2)
	{
		//resize();
		Vector::resize(maxLen * 2);
	}
	list[len++] = item;
}

template<class T>
void Vector<T>::pop()
{
	//resize
	if (len < maxLen /2) 
	{
		Vector::resize(maxLen / 2);
	}
	len--;
}

template<class T>
T& Vector<T>::at(int i)
{
	if ((i >= 0) && (i < len))
	{
		return list[i];
	}
	//default return 1st element
	return list[0];
}
#endif


//#pragma once
////-------------------------------------------------------------------------
//#ifndef H_Vector 
//#define H_Vector
////-------------------------------------------------------------------------
//#include <iostream>
//#include <string>
//using namespace std;
////-------------------------------------------------------------------------
//template <class Type>
///**
// * @class Vector
// * @brief manages Vector template functions and data in it
// *
// * @date 25/06/2019
// */
//class Vector {
//public:
//	/**
//	 * @brief set default length and capacity for Vector list
//	 */
//	Vector();
//	/**
//	 * @brief  free memory that hold Vector list
//	 */
//	~Vector();
//	/**
//	 * @brief add new instance into Vector list. Also check list capacity to resize it if needed
//	 * @param memory location of new instance
//	 * @return void
//	 */
//	void push_back(const Type& i);
//	/**
//	 * @brief return location of a instance in list
//	 * @param index number of instance required
//	 * @return Type&
//	 */
//	Type& at(int i);
//	/**
//	 * @brief change the size of current list and move data from current list to new list created
//	 * @param size of new list
//	 * @return void
//	 */
//	void resize(int newSize);
//	/**
//	 * @brief return size of list
//	 * @return int
//	 */
//	int size();
//	/**
//	 * @brief print all data stored in list
//	 * @return void
//	 */
//	void print();
//private:
//	///maximum data can be store in the Vector list
//	int capacity;
//	///pointer pointed to location of Vector list
//	Type* list;
//	//amount of data Vector list
//	int length;
//};
//
////implementation
//template <class Type>
//void Vector<Type>::push_back(const Type& i)
//{
//	if ((capacity / 2) == length)
//	{
//		Vector::resize(capacity * 2.0);
//	}
//	list[length] = i;
//	length++;
//}
//
//template <class Type>
//Type& Vector <Type>::at(int i)//return 1st location in list if parameter value is not found
//{
//	if ((i >= 0) && (i < length))
//	{
//		return list[i];
//	}
//	return list[0];
//}
//
//template <class Type>
//int Vector<Type>::size()
//{
//	return length;
//}
//
//template <class Type>
//Vector<Type>::Vector() {
//	length = 0;
//	capacity = 200;
//	list = new Type[capacity];
//}
//
//template <class Type>
//Vector<Type>::~Vector() {
//	delete[] list;
//}
//
//template <class Type>
//void Vector<Type>::resize(int newSize) {
//	Type* newList = new Type[capacity];
//	Type* newListP = newList;
//	Type* oldListP = list;
//	while (oldListP != (list + length)) {//while != last address of list
//		*(newListP) = *(oldListP);
//		newListP++;//move to next location/address
//		oldListP++;
//	}//this loop swap value until the last location of list
//	capacity = newSize;
//	delete[] list;
//	list = newList;
//}
//
//template <class Type>
//void Vector<Type>::print() {
//	for (int i = 0; i < length; i++) {
//		cout << "list " << list[i] << endl;
//	}
//}
//#endif//Vector_H
