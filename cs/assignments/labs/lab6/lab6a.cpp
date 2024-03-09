/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Learn how to read from a file and handle errors
Input: file name
Output: sum of numbers in file or error message
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string filename;
    ifstream inputFile;
    double numbers[100];
    double temp = 0;
    int validNumbersCount = 0; 
    double min = 0, max = 0, sum = 0, average = 0;

    // Keep prompting for the file name until a valid file is opened
    while (true) {
        cout << "Enter a file name\n";
        cout << "**";
        cin >> filename; // Get the file name
        cout << endl; // newline
        inputFile.open(filename);
        if (!inputFile) {
            cout << "Error: Invalid file name.\n";
            inputFile.clear();
        } else {
            break; 
        }
    }

    // Read from the file
    while (inputFile >> temp || !inputFile.eof()) {
        if (inputFile.fail()) {
            inputFile.clear(); // Clear the error flag
            inputFile.ignore(100, '\n'); // Ignore invalid input
            cout << "Error: Invalid input in file.\n";
        } else {
            if (validNumbersCount == 0) {
                min = max = temp; // Set the first number as min and max
            } else {
                if (temp < min) min = temp;
                if (temp > max) max = temp;
            }
            sum += temp; // Add temp to sum
            numbers[validNumbersCount++] = temp; // Store number in the array
        }
    }

    // Calculate average
    if (validNumbersCount > 0) {
        average = sum / validNumbersCount; // Calculate average
    }

    // Output the results
    cout << fixed << setprecision(2);
    cout << endl;
    cout << "Amount of Elements Read In: " << validNumbersCount << "\n";
    cout << "Forwards: ";
    for (int i = 0; i < validNumbersCount; i++) {
        cout << numbers[i];
        if (i < validNumbersCount - 1) cout << ", ";
    }
    cout << "\nBackwards: ";
    for (int i = validNumbersCount - 1; i >= 0; i--) {
        cout << numbers[i];
        if (i > 0) cout << ", ";
    }
    cout << "\nMinimum: " << min << "\n";
    cout << "Maximum: " << max << "\n";
    cout << "Sum: " << sum << "\n"; 
    cout << "Average: " << average << "\n";

    inputFile.close(); // Close the file

    return 0;
}
