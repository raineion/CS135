/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Learn how to read from a file and handle errors
Input: file name
Output: sum of numbers in file or error message
*/

#include <iostream> // input and output
#include <fstream> // file input and output
#include <string> // string manipulation

using namespace std; // standard library

int main() {
    string filename; // The name of the file to open
    ifstream inputFile; // The file to read from
    int runningTotal = 0; // Initialize running total

    while (true) {
        cout << "Enter file name\n**";
        cin >> filename;
        cout << endl; // newline 

        inputFile.open(filename);
        if (!inputFile) {
            cout << "Error: Invalid file name\n";
            // clea the state
            cin.clear();
            cin.ignore(100, '\n');
        } else {
            // If the file was successfully opened, break out of the loop
            break;
        }
    }

    int num1 = 0, num2 = 0;
    while (!inputFile.eof()) {
        if (inputFile >> num1 >> num2) {
            // Successfully read two numbers
            int sum = num1 + num2;
            runningTotal += sum;
            cout << num1 << " + " << num2 << " = " << sum << endl;
        } else {
            // clear the error and ignore the rest of the line
            inputFile.clear();
            inputFile.ignore(100, '\n');
            cout << "Error in line\n";
        }
    }

    cout << "\nRunning total = " << runningTotal << endl;

    inputFile.close();
    return 0;
}