#include <iostream>
using namespace std;

void max_avg(int a[], int size, int *max, int *avg);

int main(){



	// /*
	// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// 	STEP 2 is AFTER THIS POINT
	// */

	// int n1=53, n2=72;
	// int *p1=&n1, *p2=&n2;
	// double n4=6.3, *p4=&n4;
	// //which of the following do or don't compile? Why or why not?
	
	// n4 = n1;//Step 1
	// /*
	// Step 1 compiles since we are allowed to assigned a double to an int
	// */
	// n1 = n4;//Step 2
	// /*
	// Step 2 compiles since we are allowed to assigned a int to a double
	// */
	// p1 = p4;//Step 3 

	// /*
	// Step 3 has an error because you cannot assign a pointer of type int
	// to a pointer of type double.
	// */


	// p2 = &p1;//Step 4

	// /*
	// Step 4 is incorrect since you cannot point a pointer to another pointer.
	// p2 is pointing to the address  of a pointer, which is not possible
	// In order to point to a pointer, you need **.
	// */
	// p4 = &n1;//Step 5

	// /*
	// 	Step 5 is incorrect since cannot have a point of type double point
	// 	to a value of int.
	// */
	// &n1 = &n2;//Step 6

	// /*
	// 	Step 6 is incorrect since you cannot change or assign the memory 
	// 	address of a variable
	// */
	// *p1 = *p2;//Step 7

	// /*
	// 	Step 7 is correct since we are changing the dereferenced value of p1
	// 	to p2
	// */

	// cout << *p1 << endl;
	// /*
	// */



	//Write down what will be printed by the line of code below

	//Draw the memory picture for the code below, up until the next comment
	// int * p1, n1=53, *p2, n2=72, *p3;
	// //Step 1: Draw a picture of the memory at this point
	// p1 = &n1;
	// //Step 2: Draw a picture of the memory at this point
	// p2 = &n2;
	// //Step 3: Draw a picture of the memory at this point
	// p3 = p1;
	// //Step 4: Draw a picture of the memory at this point
	// *p3 = 35;
	// //Step 5: Draw a picture of the memory at this point
	// n2 = 21;
	// //Step 6: Draw a picture of the memory at this point
	// p1=&n2;
	// //Step 7: Draw a picture of the memory at this point
	// //Write down what will be printed by the line of code below
	// cout<<"n1= "<<n1<<", n2= "<<n2<<", *p1= "<<*p1<<", *p2= "<<*p2<<", *p3= "<<*p3<<endl;

	//++++++++++++++++++++++++++++++
	//STEP 3
	int a[] = {1,2,3,4,5};
	int *m;
	int *av;

	max_avg(a, 5, m, av );




	return 0;
}

void max_avg(int a[], int size, int *max, int *avg)
{
	int maximum = 0;
	int average = 0;
	for (int i=0;i<size;i++)
	{
		if (a[i] > maximum)
		{
			maximum = a[i];
		}
		average+=a[i];
	}

	average /= size;

	max = &maximum;
	avg = &average;

	cout << *max << endl;
	cout << *avg << endl;



}