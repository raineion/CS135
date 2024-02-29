/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: This program calculates the sum of even and odd numbers up to a given count.
Input: A count between 2 and 10000
Output: The sum of even numbers and the sum of odd nuodd n
*/

#include <iostream> // input and output
#include <fstream> // file input and output
#include <string> // string manipulation

using namespace std; // standard library

int main() {
    string filename; // The name of the file to open
    ifstream inputFile; // The file to read from
    int runningTotal = 0;

    while (true) {
        cout << "Enter file name\n";
        cout << "**";
        cin >> filename;
        cout << endl; // New line after the sequence

        inputFile.open(filename);
        if (!inputFile) {
            cout << "Error: Invalid file name\n";
            cin.clear(); // Clear any error flags
            // Ignore any characters in the input buffer
            cin.ignore(100, '\n');
        } else {
            break; // File opened successfully
        }
    }

    int num1, num2;
    while (inputFile >> num1 >> num2) {
        if (inputFile.fail()) {
            inputFile.clear(); // Clear fail bit
            inputFile.ignore(100, '\n'); // Ignore rest of line
            cout << "Error in line\n";
        } else {
            int sum = num1 + num2;
            runningTotal += sum;
            cout << num1 << " + " << num2 << " = " << sum << endl;
        }
    }

    cout << "Running total = " << runningTotal << endl;

    inputFile.close();
    return 0;
}