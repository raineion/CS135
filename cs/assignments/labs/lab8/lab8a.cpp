/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Processes temperature data from a file, storing it in a 
				 2D array to compute and display the lowest and 
				 highest temperatures, 
				 along with the average low and high temperatures.
Input: File name containing temperature data.
Output: Lowest temperature, highest temperature, 
		  average low temperature, average high temperature.
*/

#include <iostream> // i/o library
using namespace std; // Use the standard namespace

// Function prototypes
int getIntegerInput(string prompt, int min, int max);
char getCharacterInput(string prompt); 
void writeUpsideDownTriangle(int size, char character);
void writeRightsideUpTriangle(int size, char character);

int main() {
    // Minimums/maximums
    const int MIN = 2;
    const int MAX = 20;
    // Prompt for integer input
    string prompt1 = "Enter a count between " + to_string(MIN) + " and " + to_string(MAX) + "\n**";
    // Prompt for character input
    string prompt2 = "Enter a character\n**";
    
    // Get size of triangle
    int size = getIntegerInput(prompt1, MIN, MAX);
    // Get character to use when printing triangle
    char character = getCharacterInput(prompt2);
    cout << endl; // Print newline after character input
    // Write both triangles
    writeUpsideDownTriangle(size, character);
    writeRightsideUpTriangle(size, character);
    
    // Terminate the program
    return 0;
}

// Function definitions
int getIntegerInput(string prompt, int min, int max) {
    int input = 0;
    while (true) {
        cout << prompt; // Print prompt
        cin >> input; // Get integer input
        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(1000, '\n'); // Skip bad input
            cout << "\nError: Invalid input!\n";
        } else if (!cin.fail() && (input < min || input > max)) {
            cin.ignore(1000, '\n'); // It's important to clear the buffer here as well
            cout << "\nError: Invalid input!\n";
        } else {
            cout << endl; // Ensuring newline is printed only upon valid input
            return input; // Return valid input
        }
    }
}
// Function to get character input
char getCharacterInput(string prompt) {
    char input = 0; // Variable to store character input
    cout << prompt;
    cin >> input;
    cin.ignore(1000, '\n'); // Clear the newline character after character input
    return input;
}
// Function to write an upside-down triangle
void writeUpsideDownTriangle(int size, char character) {
    for (int i = size; i > 0; --i) {
        for (int j = 0; j < i; ++j) {
            cout << character;
        }
        cout << endl; // Print newline after each row
    }
}
// Function to write a right-side-up triangle
void writeRightsideUpTriangle(int size, char character) {
    for (int i = 1; i <= size; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << character;
        }
        cout << endl; // Print newline after each row
    }
}
