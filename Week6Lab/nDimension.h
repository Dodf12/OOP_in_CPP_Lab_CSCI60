#ifndef nDimension_H
#define nDimension_H

#include <iostream>
#include <cassert>
#include <iostream>

using namespace std;

template <class T>
class nDimension
{
	private:
		T point_[10];
		int size_;
	public:
		nDimension();
		nDimension(int s);

		nDimension(int s, T a[]);

		//Getter
		T getItem(int index);

		int getSize();

		//Opeartor Overloading
		void operator=(const nDimension& other);

};

template <class T>
nDimension<T>::nDimension() { size_ = 0; }

template <class T>
nDimension<T>::nDimension(int s) 
{ 
	if (size_ > 10) { size_ = 10; }
	size_ = s; 
}

template <class T>
nDimension<T>::nDimension(int s, T a[])
{
	if (s > 10) { size_ = 10;}
	size_ = s;

	for (int i = 0;i < size_; i++)
	{
		point_[i] = a[i];
	}
}

template <class T>
T nDimension<T>::getItem(int index)
	{
		assert(index<size_);
		return point_[index];
	}

template <class T>
int nDimension<T>::getSize() { return size_; }


//T must be of the same type, otherwise will not work
template <class T>
void nDimension<T>::operator=(const nDimension& other)
{
	size_ = other.size_;
	for (int i = 0; i < size_; i++)
	{
		point_[i] = other.point_[i];
	}
}

#endif // DBIGUINT_H