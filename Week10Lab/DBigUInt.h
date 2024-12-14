// Name: Kaiwen Du
// File: DBigUInt.h (File Location Known)
// Date: 10-24-2024
// Collaborators: Anson Chee, Zach Peng
// Description: Header file for DBigUInt.

#ifndef DBIGUINT_H
#define DBIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class DBigUInt {
public:
    // Declaring default constructor.
    DBigUInt();

    // Declaring 1-parameter constructor.
    DBigUInt(const string &s);

    // Declaring destructor.
    ~DBigUInt();

    // Declaring Size function.
    int Size() const;

    // Declaring operator overloader for '[]'.
    unsigned short operator [](int pos) const;

    // Declaring operator overloader for '+='.
    void operator +=(const dbiguint & b);

    void clean();

private:
    // Declaring variables & pointers.
    size_t capacity_;
    unsigned short *data_;

    // Declaring private Reserve function.
    void Reserve(int newcapacity);
};

#endif