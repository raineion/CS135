/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: This program calculates the sum of even and odd numbers up to a given count.
Input: A count between 2 and 10000
Output: The sum of even numbers and the sum of odd nuodd n
*/

#include <iostream> // input and output

using namespace std; // standard library

int main() {
    int count = 0; // The count of numbers to sum

    do {
        cout << "Enter a count between 2 and 20\n";
        cout << "**";
        cin >> count;
        cout << endl; // New line after the sequence
        if(cin.fail() || count < 2 || count > 20) {
            cin.clear(); // Clear the error flag
            cin.ignore(100, '\n');
            cout << "Error: Invalid entry, please retry\n";
        }
    } while(cin.fail() || count < 2 || count > 20);

    // Upside-down triangle
    for(int i = count; i > 0; --i) {
        for(int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    // Rightside-up triangle
    int stars = 1; // The number of stars to print
    while(stars <= count) {
        for(int i = 0; i < stars; ++i) {
            cout << "*";
        }
        cout << endl;
        stars++;
    }

    return 0;
}