/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Calculate the largest of two floating point numbers and the largest of two strings.
Input: Two floating point numbers and two strings.
Output: The largest of the two floating point numbers and the largest of the two strings.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    double num1 = 0.0, num2 = 0.0;
    string str1 = "", str2 = "";

    // Floating point numbers
    cout << "Enter a floating point number" << endl;
    cout << "**";
    cin >> num1;
    cout << endl;

    cout << "Enter another floating point number" << endl;
    cout << "**";
    cin >> num2;
    cout << endl;
    // Output information
    cout << "You entered " << num1 << " and " << num2 << endl;
    if (num1 > num2) {
        cout << "The largest is " << num1 << endl;
    } else {
        std::cout << "The largest is " << num2 << endl;
    }
    // Extra line
    std::cout << endl;


    // Strings
    cout << "Enter a string" << endl;
    cout << "**";
    cin >> str1;
    cout << endl;

    cout << "Enter a second string" << endl;
    cout << "**";
    cin >> str2;
    cout << endl;
    // Output information
    cout << "You entered \"" << str1 << "\" and \"" << str2 << "\"" << endl;
    if (str1 > str2) {
        cout << "The largest is \"" << str1 << "\"" << endl;
    } else {
        cout << "The largest is \"" << str2 << "\"" << endl;
    }

    return 0;
}
