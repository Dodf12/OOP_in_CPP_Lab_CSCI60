#include "lbiguint.h"
#include "node.h"
#include <iostream>
using namespace std;

int main()
{
	return 0;
	lbiguint myObj("120");
	cout << "Object not created?" << endl;
	cout << "Size: " << myObj.size() << endl;
	cout << "Test [] " << myObj[2] << endl;
}