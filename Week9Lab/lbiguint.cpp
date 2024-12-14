#include "lbiguint.h"
#include "node.h"
#include <iostream>

lbiguint::lbiguint()
{
	head = tail = new node(0,nullptr);
}

lbiguint::lbiguint(const string& s) {
    head = nullptr;
    tail = nullptr;
    
    for (int i = s.length() - 1; i >= 0; --i) {
        if (i == s.length() - 1) {
            head = tail = new node(s[i] - '0', nullptr);
        }
        else {
            head = new node(s[i] - '0', head);
        }
    }
}

lbiguint::~lbiguint()
{
	node *temp = head;
	while (temp != nullptr)
	{
		temp = head->link();
		delete head;
		head = temp;
	}
}

int lbiguint::size() const
{
	cout << "Hello Size" << endl;
	node *currentNode = head;
	int count = 0;
	while (currentNode!=nullptr)
	{
		count++;
		currentNode = currentNode->link();
	}
	return count;
}

int lbiguint::operator [](int pos) const
{
	node *currentNode = head;
	int count = 0;
	if (pos >= size() || pos < 0) {return 0;}
	while (count!=pos)
	{
		count++;
		currentNode = currentNode->link();
	}
	return currentNode->data();
}

ostream & operator << (ostream &o, const lbiguint &lbigObj)
{
	for (int i =0; i < lbigObj.size(); i++)
	{
		cout << lbigObj[i] << endl;
	}
	return o;
}

int main()
{
	return 0;
	lbiguint myObj("120");
	cout << "Object not created?" << endl;
	cout << "Size: " << myObj.size() << endl;
	cout << "Test [] " << myObj[2] << endl;
}
