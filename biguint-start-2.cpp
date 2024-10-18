
/* CONTRIBUTERS:
Abhinav Pala
Matthias Masiero
Hayden Leung
*/



#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

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
//                        <<, >>


class biguint
{
public: 

    static const int CAPACITY = 20;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with value 0
    biguint() 
    {
        for (int i = 0 ; i<CAPACITY; i++)
        {
            data_[i] = 0;
        }

    }
    

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(string s)
    {

        int stringLength = s.length();

        int j = 0;
        for (int i = stringLength; i >= 0 ; i--)
        {
            data_[i] = s[j-1] - 48;
            j++;
            // cout << i << " " << data_[i] << endl;
        }

        for (int j = stringLength; j <CAPACITY;j++)
        {
            data_[j] = 0;
        }

        // for (int i = 0 ; i<CAPACITY; i++)
        // {
        //     cout << data_[i] << endl;
        // }

    }

    // CONSTANT MEMBER FUNCTIONS

    // pre: none
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](int pos)
    {
        if (pos >= CAPACITY)
        {
            return 0;
        }

         return data_[pos];
        
    }

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(biguint b) ;



    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry if any
    
    void operator += (biguint b)
    // pre: this is > b, since unsigned
    // post: b is subtracted to this biguint; ignore last borrow if any
    {
        int carryOver= 0;
        for (int i=0; i<CAPACITY; i++)
        {
            carryOver = data_[i] + b[i];
            data_[i] = carryOver%10;
            data_[i+1] += carryOver/10;
        }
    }

    void operator -= (biguint b);

private:

    unsigned short data_[CAPACITY];

    // INVARIANTS:
    //    data_[i] holds the i^th digit of this biguint or 0 if not used
    //    data_[0] holds the least significant (units) digit
};

int main()
{
    biguint b1("654321");
    biguint b2("654321");

    cout << 654321 * 2 << endl, 

    b1+=b2;

    cout << "Looping through the array to make sure sum is right" << endl;
    for (int i = 0; i<20; i++)
    {
            cout << b1[i] << endl;
    }


    return 0;
}

// nonmember functions

biguint operator + ( biguint b1,  biguint b2);
biguint operator - ( biguint b1,  biguint b2);

bool operator < ( biguint b1,  biguint b2);
bool operator <= ( biguint b1,  biguint b2);
bool operator != ( biguint b1,  biguint b2);
bool operator == ( biguint b1,  biguint b2);
bool operator >= ( biguint b1,  biguint b2);
bool operator > ( biguint b1,  biguint b2);
std::ostream& operator <<(std::ostream& out,  biguint b);

