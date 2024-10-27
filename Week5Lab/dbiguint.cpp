#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#include "dbiguint.h"

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//  


dbiguint::dbiguint()
{
    data_= new unsigned short[1];
    *data_=0;
    //cout << *data_;
}

dbiguint::dbiguint(const string & s)
{
    capacity_ = 0;
    for(char c: s)
    {
        capacity_++;
    }
    cout << "length" << capacity_ << endl;;



    data_ = new unsigned short[capacity_];
    for (int i = capacity_ -1; i>=0; i--)
    {
        data_[capacity_ -i -1] = s[i]- '0';
        cout<<data_[capacity_ -i -1]<<endl;
    }
}

int dbiguint::size() const
{
    return capacity_;
}

unsigned short dbiguint::operator [](int pos) const
{
    if(pos < capacity_)
    {
        return data_[pos];
    }
    else { return 0; }
}


ostream & operator << (ostream & out, const dbiguint & b)
{
    for (int i = b.size() -1; i>=0; i--)
    {
        out<<b[i]<<endl;
    }
    return out;
}

void dbiguint::reserve(int newcapacity)
{
    if (newcapacity > capacity_) 
    { 
        unsigned short *temp = new unsigned short[newcapacity];

        for (int i = 0; i < newcapacity; i++) {
            if (i != capacity_) {
                temp[i] = data_[i];
            }
            else {
                temp[i] = 0;
            }
        }
        capacity_ = newcapacity;
        delete[] data_;
        data_ = temp;

    }

}

void dbiguint::operator +=(const dbiguint & b)
{
    int carryOver= 0;
    
    for (int i=0; i<capacity_; i++)
    {
        if (data_[i] + b.data_[i] >= 10)
        {
            carryOver = (data_[i] + b.data_[i]) % 10;
            data_[i] = carryOver;
            (data_[i+1])++;
        }
        else
        {
            carryOver = data_[i] + b.data_[i];
            data_[i] = carryOver;
        }

    }
}




















