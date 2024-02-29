/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Practice using Variables.
Input: The user should be prompted to enter the input values.
Output: The result of the arithmetic should be output.
*/

#include <iostream>

using namespace std;

int main() {
    long long int num1 = 0, num2 = 0;
    double dbl1 = 0, dbl2 = 0;

    cout << "Enter an Integer\n**"; // user enters an integer
    cin >> num1;

    cout << "\nEnter another Integer\n**"; // user enters another integer
    cin >> num2;

    // arithmetic operations
    cout << "\n" << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
    cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
    cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
    cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
    cout << num1 << " % " << num2 << " = " << (num1 % num2) << endl;

    // user enters two doubles and prints
    cout << "\nEnter a Double\n**";
    cin >> dbl1;

    // user enters another double and prints
    cout << "\nEnter another Double\n**";
    cin >> dbl2;

    // perform division and print
    cout << "\n" << dbl1 << " / " << dbl2 << " = " << (dbl1 / dbl2) << endl;

    return 0;
}

