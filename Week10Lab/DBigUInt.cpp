// Name: Kaiwen Du
// File: DBigUInt.cpp (File Location Known)
// Date: 10-24-2024
// Collaborators: Anson Chee, Zach Peng
// Description: Class function file for DBigUInt.h.

#include "DBigUInt.h"

// Defining default constructor.
DBigUInt::DBigUInt() {
    // Initializing variable.
    capacity_ = 1;

    // Allocating heap memory for dynamic array.
    data_ = new unsigned short[capacity_];

    // Initializing pointer.
    *data_ = 0;
}

// Defining 1-parameter constructor.
DBigUInt::DBigUInt(const string &s) {
    // Initializing variables.
    capacity_ = s.length();
    data_ = new unsigned short[capacity_];

    // Inversing string data using ASCII method.
    for (int i = 0; i < capacity_; ++i) {
        // Reversing directly into array & converting to integer.
        data_[i] = s[s.length() - 1 - i] - '0';
    }
}

// Defining destructor.
DBigUInt::~DBigUInt() {
    // Freeing heap memory.
    delete[] data_;

    // Outputting status to user.
    cout << "Destructor Status: Success!" << endl;
}

// Defining Size function for DBigUInt class.
int DBigUInt::Size() const {
    // Returning function.
    return capacity_;
}

// Defining operator overloader for '[]' for DBigUInt class.
unsigned short DBigUInt::operator [](int pos) const {
    // Checking if given position exceeds capacity or negative.
    if (pos >= capacity_ || pos < 0) {
        return 0;
    }

    // Returning function.
    return data_[pos];
}

// Defining operator overloader for "+=" for DBigUInt class.
void DBigUInt::operator +=(const dbiguint & b) {
    // Initializing variable.
    int sum = 0;

    for (int i = 0; i < capacity_; ++i) {
        // Checking if sum of current digits is exceeding 10.
        if (data_[i] + b.data_[i] >= 10) {
            // Calculating current digit as remainder when divided by 10.
            sum = (data_[i] + b.data_[i]) % 10;

            // Storing digit back in current position.
            data_[i] = sum;

            // Carrying overflow to next position.
            data_[i + 1] += 1;
        } 
        else {
            // Adding data to sum.
            sum = data_[i] + b.data_[i];

            // Storing result in current position.
            data_[i] = sum;
        }
    }
}

// Defining Reserve function for DBigUInt class.
void DBigUInt::Reserve(int newcapacity) {
    // Checking if original is bigger than new capacity.
    if (capacity_ >= newcapacity) {
        return;
    }

    // Declaring unsigned pointer.
    unsigned short *temp;

    // Copying data to temporary pointer.
    for (int i = 0; i < capacity_; ++i) {
        *(temp + i) = *(data_ + i);
    }

    // Freeing heap memory.
    delete[] data_;

    // Allocating heap memory for dynamic array.
    data_ = new unsigned short[newcapacity];

    // Copying data back to original pointer.
    for (int i = 0; i < capacity_; ++i) {
        *(data_ + i) = *(temp + i);
    }
}

// Defining operator overloader for '<<'.
ostream& operator <<(ostream &out, const dbiguint &b) {
    // Outputting object array to output stream.
    for (int i = b.size() - 1; i >= 0; --i) {
        out << b[i];
    }

    // Returning function.
    return out;
}


void Dbiguint::clean()
{

    int i = 0;
    int count = 0;
    while (data_[i] == 0) { count ++; }

    int *temp = new int[capacity_ - count];
    for (int i = count - 1; i < capacity_; i++)
    {
        temp = data_[i];
    }

    capacity_-=count;

    delete[] data_;
    data_ = temp;
}