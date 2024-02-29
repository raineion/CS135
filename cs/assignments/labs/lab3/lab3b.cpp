/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Determine the range of a letter grade.
Input: A letter grade
Output: The range of the letter grade
*/

#include <iostream> // input and output

using namespace std; // standard library

int main() {
    char grade = 0; // letter grade
    cout << "Enter a letter grade\n"; // prompt
    cout << "**"; 
    cin >> grade; // input

    switch (grade) {
        case 'A': 
        case 'a':
            cout << "\nGrade range is 90 - 100"; // outputs within range
            break;
        case 'B':
        case 'b':
            cout << "\nGrade range is 80 - 89.99"; 
            break;
        case 'C':
        case 'c':
            cout << "\nGrade range is 70 - 79.99";
            break;
        case 'D':
        case 'd':
            cout << "\nGrade range is 60 - 69.99";
            break;
        case 'F':
        case 'f':
            cout << "\nGrade range is 0 - 59.99";
            break;
        default:
            cout << "\nError: '" << grade 
            << "' is not a valid letter grade\n"; // outputs error
    }

    return 0; // end
}