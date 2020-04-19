//this is vector but without repeated value
#ifndef SET_H
#define SET_H

#include <iostream>

#define DEFAULT_SIZE 3
#define MAX_SIZE 100000
using namespace std;

template <class T>
class Set {
public:
	Set(int length = DEFAULT_SIZE);
	~Set();
	int Size() { return len; };
	int isEmpty() { return len == 0; };
	void Insert(T item);
	T& at(int i);
	void Pop();
	int getMaxLen() { return maxLen; };
	void intersection(Set<T> ,Set<T>&);
private:
	void Resize(int newSize);
	T* list;
	int len;
	int maxLen;
};

template <class T>
Set<T>::Set(int length)
{
	if (length <= 0)
	{
		cout << "Set size must be positive" << endl;
		maxLen = DEFAULT_SIZE;
	}
	else {
		maxLen = length;
	}
	len = 0;// Set is empty at first
	list = new T[maxLen];
}

template <class T>
Set<T>::~Set()
{
	if (list != nullptr)
	{
		list = nullptr;
		len = 0;
		delete[] list;
	}
}

template <class T>
void Set<T>::Resize(int newSize)
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
void Set<T>::Insert(T item)
{
	bool repeat1 = false;

	for (int n = 0; n < len; n++) {
		if (list[n] == item) {
			//cout << "repeated insert" << endl; 
			repeat1 = true;
		}
	}
	if (repeat1 == false) {
		if (len >= maxLen / 2) {
			Set::Resize(maxLen * 2);
		}
		list[len++] = item;
		//cout << "inserted" << endl;
	}

	
}


template<class T>
void Set<T>::Pop()
{
	//resize
	if (len < maxLen / 2)
	{
		Set::Resize(maxLen / 2);
	}
	len--;
}

template<class T>
T& Set<T>::at(int i)
{
	if ((i >= 0) && (i < len))
	{
		return list[i];
	}
	//default return 1st element
	return list[0];
}

template <class T>
void Set<T>::intersection( Set<T> set2, Set<T>& set3) {
	int i = 0, j = 0;
	while (i != len && j != set2.Size()) {
		if (list[i] == set2.at(j)) {
			set3.Insert(set2.at(j));
			i++; j++;
		}
		else if (list[i] < set2.at(j)) {
			i++;
		}
		else {
			j++;
		}
	}
}
#endif //SET_H
