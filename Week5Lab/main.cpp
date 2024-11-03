#include "dbiguint.h"
#include <iostream>

using namespace std;

int main()
{
	dbiguint myObj("999");
	cout << myObj.size() << endl;
	cout << myObj[1] << endl;

	cout<< "++++++++++" << endl;

	cout << myObj << endl;

	cout<< "++++++++++" << endl;

	myObj.reserve(5);
	cout<< "++++++++++" << endl;

	cout << myObj << endl;

	cout << "-----" << endl;
	dbiguint myObj1("99");
	cout << "++";
	myObj+=myObj1;
	cout << myObj;
}