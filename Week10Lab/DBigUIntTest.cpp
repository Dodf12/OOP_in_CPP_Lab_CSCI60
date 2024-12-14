// Name: Kaiwen Du
// File: DBigUIntTest.cpp (File Location Known)
// Date: 10-24-2024
// Collaborators: Anson Chee, Zach Peng
// Description: Main test program for DBigUInt.h.

#include "DBigUInt.h"

int main() {
    // Declaring variables.
    string test1 = "000123456789";
    string test2 = "12345";

    // Declaring class objects.
    dbiguint dbiguint1;
    dbiguint dbiguint2(test1);
    dbiguint dbiguint3(test2);

    // Outputting first object data to user.
    cout << "Zero Parameter:\t\t";
    for (int i = 0; i < 1; ++i) {
        cout << dbiguint1[i] << " ";
    }

    // Outputting second object data to user.
    cout << "\nInverted '123456789':\t";
    for (int i = 0; i < test1.length(); ++i) {
        cout << dbiguint2[i] << " ";
    }

    // Outputting third object data to user.
    cout << "\nInverted '12345':\t";
    for (int i = 0; i < test2.length(); ++i) {
        cout << dbiguint3[i] << " ";
    }
   
    // Adding second object with third object.
    dbiguint2 += dbiguint3;

    // Outputting result of second object data to user.
    cout << "\nAdding #1 & #2:\t\t";
    for (int i = 0; i < test1.length(); ++i) {
        cout << dbiguint2[i] << " ";
    }

    //Dbiguitn Clean
    string test3 = "000123456789";
    dibguint dibgiunit4(test3);
    for (int i = 0; i < test1.length(); ++i) {
        cout << dbiguint4[i] << " ";
    }
    dbiguint4.clean();
    
    for (int i = 0; i < test1.length(); ++i) {
        cout << dbiguint4[i] << " ";
    }

    // Ending program with newline.
    cout << endl;

    return 0;
}