/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Reads names and scores from a file into arrays, handles invalid file names.
Input: File name and name to search
Output: Names and scores or error message
*/

#include <iostream> // i/o library
#include <fstream>  // file i/o library
#include <string>  // string library
#include <iomanip>  // i/o manipulation library

using namespace std; // Use the standard namespace

int main() {
    const int MAX_SIZE = 100;
    string names[MAX_SIZE];
    double scores[MAX_SIZE];
    int count = 0; // Initialize count to 0
    string filename, toFind;
    ifstream inputFile;

    // Prompt for file name and open it
    while (true) {
        cout << "Enter a file name\n**";
        cin >> filename;
         cout << endl; // newline
        inputFile.open(filename);
        if (inputFile.is_open()) {
            // Break out of the loop if the file is successfully opened
            break;
        } else {
            // Output error message but do not use continue
            cout << "Error: Invalid file name.\n";

            inputFile.clear(); // Reset the stream state to allow for further attempts
        }
    }   // Read data from file into parallel arrays
    while (inputFile >> names[count] >> scores[count]) {
        count++;
        if (count >= MAX_SIZE) {
            break; // Prevents overflow of the arrays
        }
    }
    inputFile.close(); // Close the input file

    // Prompt for a name to search
    cout << "Enter a name to search\n";
    cout << "**";
    cin >> toFind;
    cout << endl; // newline

    

    // Print names and scores forwards
    cout << "Names Forward: ";
    for (int i = 0; i < count; i++) {
        cout << names[i];
         if (i < count - 1) {
            cout << ", ";
         }
    }
    cout << "\nScores Forward: ";
    for (int i = 0; i < count; i++) {
        cout << scores[i];
         if (i < count - 1) {
            cout << ", ";
         }

    }
    cout << endl;

    // Print names and scores backwards
    cout << "Names Reverse: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << names[i];
         if (i > 0) {
               cout << ", ";
         }
    }
    cout << "\nScores Reverse: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << scores[i];
         if (i > 0) {
               cout << ", ";
         }
    }
    cout << endl; // newline

    // Calculate statistics for the entered name
    double sum = 0.0; // Initialize sum to 0
    int minIndex = -1, maxIndex = -1, foundCnt = 0;
    for (int i = 0; i < count; i++) {
        if (names[i] == toFind) {
            sum += scores[i]; 
            foundCnt++; // Increment the count of found names
            if (minIndex == -1 || scores[i] < scores[minIndex]) {
                minIndex = i; // Set the index of the minimum score
            }
            if (maxIndex == -1 || scores[i] > scores[maxIndex]) {
                maxIndex = i; // Set the index of the maximum score
            }
        }
    }

    if (foundCnt == 0) {
        cout << "Error: " << toFind << " is not a student in the list\n";
    } else {
        cout << foundCnt << " results for " << toFind << endl;
        cout << "Minimum: " << fixed << setprecision(2) << scores[minIndex] << endl;
        cout << "Maximum: " << fixed << setprecision(2) << scores[maxIndex] << endl;
        cout << "Sum:     " << fixed << setprecision(2) << sum << endl;
        cout << "Average: " << fixed << setprecision(2) << (sum / foundCnt) << endl;
    }

    return 0;
}
