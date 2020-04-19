
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#define DEFAULT_SIZE 3
#define MAX_SIZE 100000
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
	void Push(T item);
	// added minimum
	T& at(int i);
	//void Resize(int newSize);
	//optional
	void Pop();
	//test

	int getMaxLen() { return maxLen; };
private:
	void Resize(int newSize);
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
		len = 0;
	}
}

template <class T>
void Vector<T>::Resize(int newSize) 
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
void Vector<T>::Push(T item)
{
	if (len >= maxLen / 2)
	{
		//resize();
		Vector::Resize(maxLen * 2);
	}
	list[len++] = item;
}

template<class T>
void Vector<T>::Pop()
{
	//resize
	if (len < maxLen /2) 
	{
		Vector::Resize(maxLen / 2);
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
