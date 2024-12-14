#include <iostream>
#include "bag.h"
using namespace std;





int main()
{
	int arr[5];
	bag<int> a;
	a.insert(1);
	a.insert(1);
	a.insert(1);
	a.insert(1);
	a.insert(1);
	a.insert(1);

	for (auto it = a.begin(); it != a.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "Range based forloop" << endl;
	for (int i : a)
	{
		cout << i << endl;
	}

	for (bag<int>::iterator it = a.begin(); it != a.end(); ++it)
	{
		cout << *it << endl;
	}
}