#include "nDimension.h"

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