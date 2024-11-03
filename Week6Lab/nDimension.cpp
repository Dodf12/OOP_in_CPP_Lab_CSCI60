#include <iostream>
#include <cassert>
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

int main()
{
	int arr[5] = {1,2,3,4,5};
	int arr2[2] = {1,2};

	nDimension<int> obj(5, arr);
	nDimension<int> obj2(2, arr2);

	cout << obj.getItem(1) << endl;
	cout << obj.getSize() << endl;

	obj = obj2;

	cout << obj.getItem(1) << endl;
	cout << obj.getSize();
}