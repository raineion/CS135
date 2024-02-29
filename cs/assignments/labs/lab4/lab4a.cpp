/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: this program is to create a sequence of numbers
Input: Starting number, ending number, increment value
Output: The sequence of numbers
*/

#include <iostream> // input and output

using namespace std; // standard library

int main() {
    // Declare variables
    int startingNumber = 0, endingNumber = 0, increment = 0;

    cout << "Enter a starting number\n";
    cout << "**";
    if (!(cin >> startingNumber)) {
        cout << "\nError: invalid entry." << endl;
        return 0; // Exit program with an error code
    }

    cout << "\nEnter an ending number\n";
    cout << "**";
    if (!(cin >> endingNumber)) {
        cout << "\nError: invalid entry." << endl;
        return 0; // Exit program with an error code
    }

    if (startingNumber > endingNumber) {
        cout << "\nError: end must be greater than start." << endl;
        return 0; // Exit program with an error code
    }

    cout << "\nEnter a value to increment by\n";
    cout << "**";
    if (!(cin >> increment)) {
        cout << "\nError: invalid entry." << endl;
        return 0; // Exit program with an error code
    }
    cout << endl; // New line after the sequence
    while (startingNumber <= endingNumber) {
        cout << startingNumber << " ";
        startingNumber += increment;
    }

    cout << endl; // New line after the sequence

return 0; // Successful program termination
}