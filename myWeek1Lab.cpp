#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int max(int arr[], int len);
void swap(int arr2[], int len);
void swap2(int arr3[], int len);
void sort(int arr4[], int len);

int main()
{
	//Initializing array with 100 values
	int numbers[100];
	for (int i = 0;i<100;i++)
	{
		numbers[i] = 0;
	};


	ifstream in_stream;
	in_stream.open("numbersToSort.txt");
	if(in_stream.fail())
	{
		cout << "File opening fail";
	}
	cout << "Horray" << endl;

	int n;
	int arr_index = 0;
	
	//Pass this as the length of the array
	int length = 0;
	
	while(in_stream>>n)
	{
		numbers[arr_index] = n;
		//cout << numbers[arr_index] << endl;
		arr_index++;
		length++;

	};
	in_stream.close( );

	// cout << max(numbers, length) << endl;

	swap2(numbers, length);

	int ex_arr[] = {5,3,8,1,9,3,2};
	sort(ex_arr,7);




	return 0;

};

int max(int arr[], int len)
{
	int temp = 0;
	int index =0;


	for (int i = 0; i< len; i++)
	{
		if (arr[i] > temp)
		{
			temp = arr[i];
			index = i;
		};
	};
	
	return index;
};

void swap(int arr2[], int len)
{

	for (int j = 0; j < len; j++)
	{
		cout << arr2[j] << endl;
	}

	cout << "=====================" << endl;

	int maxNumIndex = max(arr2,len);

	int maxNum = arr2[maxNumIndex];
	int lastNum = arr2[len-1];

	arr2[len-1] = maxNum;
	arr2[maxNumIndex] = lastNum;

	for (int i = 0; i < len; i++)
	{
		cout << arr2[i] << endl;
	}



};

void swap2(int arr3[], int len)
{
	for (int j = 0; j < len; j++)
	{
		cout << arr3[j] << endl;
	}

	cout << "=====================" << endl;

	int maxNumIndex = max(arr3,len);

	int maxNum = arr3[maxNumIndex];
	int SecondlastNum = arr3[len-2];

	arr3[len-2] = maxNum;
	arr3[maxNumIndex] = SecondlastNum;

	for (int i = 0; i < len; i++)
	{
		cout << arr3[i] << endl;
	}
};

void sort(int arr4[], int len)
{
	for (int k = 0; k < len; k++)
	{
		cout << arr4[k] << endl;
	};

	int cycles = 0;

	int i = 0;

	int change_tracker = true;

	while (change_tracker)
	{
		if (i >= len)
		{

		}
		else 
		{
			if (arr4[i] > arr4[i+1])
			{
				arr4[i] = arr4[i+1];
			};
		};

	};

	for (int j = 0; j < len; j++)
	{
		cout << arr4[j] << endl;
	};
};



;