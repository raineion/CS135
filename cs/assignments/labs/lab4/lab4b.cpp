/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: This program calculates the sum of even and odd numbers up to a given count.
Input: A count between 2 and 10000
Output: The sum of even numbers and the sum of odd numbers
*/

#include <iostream> // input and output
using namespace std; // standard library

int main() {
    // Declare variables
    int number = 0;
    int sumEven = 0, sumOdd = 0;

    do {
        cout << "Enter a count between 2 and 10000\n**";
        cin >> number;
        cout << endl; // New line
        if (cin.fail() || number <= 1 || number > 10000) {
            // clear/ignore failure and output error
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error: Invalid entry, please retry" << endl;
        }
    } while (cin.fail() || number <= 1 || number > 10000);

    // sum of all even numbers
   for (int i = 2; i <= number; i += 2) {
        sumEven += i;
    }

    // sum odd numbers 
    int i = 1; // Start at 1
    while (i <= number) {
        sumOdd += i;
        i += 2; // move to the next odd number
    }
    // Output
    cout << "Sum of even numbers: " << sumEven << endl;
    cout << "Sum of odd numbers:  " << sumOdd << endl;
    return 0; // Successful program termination
}
