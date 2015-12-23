/*
 * CustomVector.h
 *
 *  Created on: Jun 5, 2015
 *      Author: Joshua
 */

#ifndef CUSTOMVECTOR_H_
#define CUSTOMVECTOR_H_

#include <stdexcept>

using namespace std;

template <class T> class CustomVector
{
	private:
		T* data;      //The data storage array.
		int capacity; //Size of the array.
		int count;    //Number of elements held.

	public:
		static const int defaultSize = 10;

	public:
		CustomVector();
		CustomVector(int initialSize);
		~CustomVector();
		void add(T item);
		void push_back(T item);
		T& operator[](int i);
		int size();
};

template <class T> CustomVector<T>::CustomVector()
: CustomVector(defaultSize)
{
	/* After some research, it turns out that constructor chaining
	 * only became a thing in C++ as of the C++11 standard.
	 *
	 * If you want a common initialization scheme otherwise, just
	 * write common "init" method to handle the common details.
	 */
}

template <class T> CustomVector<T>::CustomVector(int initialSize)
{
	data = new T[initialSize];
	count = 0;
	capacity = initialSize;
}

template <class T> CustomVector<T>::~CustomVector()
{
	delete[] data;
}

template <class T> void CustomVector<T>::add(T item)
{
	if(count == capacity) {
		T* temp = new T[capacity * 2];
		for(int i=0; i<capacity; i++)
			temp[i] = data[i];

		delete[] data;
		capacity *= 2;
		data = temp;
	}

	data[count++] = item;
}

template <class T> void CustomVector<T>::push_back(T item)
{
	add(item);
}

template <class T> T &CustomVector<T>::operator[](int index)
{
	if(index >= count || index < 0)
	{
		throw exception();
	}

	return data[index];
}

template <class T> int CustomVector<T>::size()
{
	return count;
}

template <class T> ostream& operator<<(ostream& out, CustomVector<T>& vec)
{
	for(int i = 0; i < vec.size(); i++)
	{
		out << vec[i] << " ";
	}

	return out;
}

#endif /* CUSTOMVECTOR_H_ */
