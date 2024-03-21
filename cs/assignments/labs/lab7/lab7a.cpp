/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Reads data from a file into a 2D array, handles invalid file names
Input: File name
Output: Row sums and column sums
*/

#include <iostream> // i/o library
#include <fstream>  // file i/o library
#include <iomanip>  // i/o manipulation library

using namespace std; // Use the standard namespace

int main() {
    const int ROWS = 7;
    const int COLS = 10;
    double arr[ROWS][COLS];
    string filename;
    ifstream iFile;

    // Loop until a valid file is opened
    while (true) {
        cout << "Enter a file name\n**";
        cin >> filename;
        iFile.open(filename);

        if (iFile) break; // Successfully opened the file
        cout << endl; // newline
        cout << "Error: Invalid File Name\n";
        iFile.clear();
    }

    // Read the file data into the array
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            iFile >> arr[i][j];
        }
    }
    iFile.close(); // Close the file as it's no longer needed

    // Set the precision for all floating point outputs
    cout << fixed << setprecision(1);

    // Sum and print row sums
    cout << "\nROW SUMS:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        double rowSum = 0.0;
        for (int j = 0; j < COLS; ++j) {
            cout << left << setw(4) << arr[i][j] << (j < COLS - 1 ? " + " : " = ");
            rowSum += arr[i][j];
        }
        cout << setw(3) << rowSum << endl;
    }

    // Sum and print column sums
    cout << "\nCOLUMN SUMS:" << endl;
    for (int j = 0; j < COLS; ++j) {
        double colSum = 0.0;
        for (int i = 0; i < ROWS; ++i) {
            cout << setw(4) << arr[i][j];
            colSum += arr[i][j];
            if (i < ROWS - 1) {
                cout << " + ";
            } else {
                // For the last element, print the sum instead of the operand
                cout << " = " << setw(5) << colSum << endl;
            }
        }
    }

    return 0;
}