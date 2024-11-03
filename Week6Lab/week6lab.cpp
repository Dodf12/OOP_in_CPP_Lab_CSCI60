
#include <iostream>
using namespace std;


#include <string>
#include <cassert>

template <typename T>
int count_exact(T a[], int size, T find);

template <typename T>
T frequent(T a[], size_t size);

int main()


{
	int arr[6] = {6,2,3,2,6,2};

	string arr2[3] = {"hello","string","hello"};

	cout << count_exact(arr, 6 , 2) << endl;
	string guess = "hello";
	cout << count_exact(arr2, 3, guess) << endl;

	cout << "Frequent: " << frequent(arr, 6) << endl;
	cout << "Frequent String: " << frequent(arr2,3);


}

//Objects need to be overloaded with [] and ==
template <typename T>
int count_exact(T a[], int size, T find)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == find) {count++; }
	}

	return count;
};


template <typename T>
T frequent(T a[], size_t size)
{
	assert( size < 50);
	int max;
	T maxElement;
	for (int i = 0; i < size; i++)
	{
		if (count_exact(a, size, a[i]) > max)
		{
			maxElement = a[i];
			max = count_exact(a, size, a[i]);
		}
	}

	return maxElement;


}