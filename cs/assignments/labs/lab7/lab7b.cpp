/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Reads temperature data from 
             a file into a 2D array, calculates statistics
Input: File name
Output: Lowest temperature, highest temperature, 
        average low temperature, average high temperature
*/

#include <iostream> // i/o library
#include <fstream> // file i/o library
#include <string> // string library
#include <iomanip> // i/o manipulation library

using namespace std; // Use the standard namespace

int main() {
    // Declare variables
    string filename; 
    ifstream iFile;
    const int MONTHS = 12;
    float arr[MONTHS][2];
    string city;
    int year = 0;

    while (true) {
        cout << "Enter file name\n**";
        cin >> filename; // Get file name from user
        cout << endl;

        iFile.open(filename);
        if (!iFile) {
            cout << "Error: Invalid File Name\n";
            iFile.clear(); // Clear the error flag
        } else {
            break;
        }
    }

    // Read city and year
    iFile >> city >> year; 
    cout << city << " " << year << endl;

    // Read temperatures into the array
    for (int i = 0; i < MONTHS; i++) {
        iFile >> arr[i][0] >> arr[i][1];
    }

    iFile.close(); // Close the file

    // Initialize variables for statistics
    float lowestTemp = arr[0][0], highestTemp = arr[0][1];
    float totalLowTemp = 0, totalHighTemp = 0;

    // Compute statistics
    for (int i = 0; i < MONTHS; i++) {
        if (arr[i][0] < lowestTemp) lowestTemp = arr[i][0];
        if (arr[i][1] > highestTemp) highestTemp = arr[i][1];
        totalLowTemp += arr[i][0];
        totalHighTemp += arr[i][1];
    }

    // Output
    cout << fixed << setprecision(2);
    cout << "Lowest temperature of the year was "
         << lowestTemp << "° F.\n";
    cout << "Highest temperature of the year was " 
         << highestTemp << "° F.\n";
    cout << "Average low temperature of the year was " 
         << (totalLowTemp / MONTHS) << "° F.\n";
    cout << "Average high temperature of the year was " 
         << (totalHighTemp / MONTHS) << "° F.\n";

    return 0;
}
