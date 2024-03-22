/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1023
Description: Convert package dimensions 
             from metric to imperial, calculate volumes.
Input: Package dimensions (length/width/height) 
       and units from a file.
Output: Converted dimensions, volumes in 
        cubic inches, and totals to files.
*/

#include <iostream> // For standard input/output
#include <fstream> // For file I/O
#include <string> // For string class
#include <iomanip> // For output formatting

using namespace std; // Using the standard namespace

// Function to convert metric units to inches
double convertToInches(double value, const string& unit) {
    if (unit == "mm") return value / 25.4;
    if (unit == "cm") return value / 2.54;
    if (unit == "m") return value * 39.37;
    return -1; // Return -1 for invalid units
}

int main() {
    ifstream inputFile; // Input file stream
    // Output files for conversions and totals
    ofstream conversionsFile("conversions.txt"), 
             totalsFile("totals.txt");
    // File name and unit of measurement
    string fileName, unit;
    // Package dimensions and volume
    double length = 0, width = 0, 
           height = 0, volume = 0; 
    int validPackages = 0, invalidPackages = 0, 
        lineNumber = 0;
    // Total volume of all packages
    double totalVolume = 0;

    // Prompt for input file name
    while (true) {
        cout << "Enter a file name: ";
        getline(cin, fileName);
        inputFile.open(fileName);

        if (!inputFile) {
            cout << "Error: Invalid file name\n";
        } else {
            break; // File opened successfully
        }
    }

    // Read and process each line of the file
    cout << endl;
    while (true) {
        lineNumber++; // Increment line number with each iteration
        inputFile >> length >> width >> height;

        if(inputFile.eof()) {
            break; // Break the loop 
        }

        if(inputFile.fail()) {
            inputFile.clear(); // Clear error state
            inputFile.ignore(100, '\n'); // Skip bad input
            cout << "Error: Invalid package on line " 
                 << lineNumber << endl;
            invalidPackages++;
            continue; // Skip this line
        }
            
        // Ensure the unit is valid before converting
        inputFile >> unit;
        if(inputFile.fail() || convertToInches(1, unit) == -1) {
            cout << "Error: Invalid package on line " 
                 << lineNumber << endl;
            invalidPackages++;
            inputFile.clear(); // Clear error state
            inputFile.ignore(100, '\n'); // Skip to next line
            continue;
        }
        
        // Convert the dimensions to inches
        double convertedLength = convertToInches(length, unit);
        double convertedWidth = convertToInches(width, unit);
        double convertedHeight = convertToInches(height, unit);

        // Calculate the volume of the package
        volume = convertedLength * convertedWidth * convertedHeight;
        conversionsFile << fixed << setprecision(3);
        conversionsFile << convertedLength << " " << convertedWidth 
        << " " << convertedHeight << " " << volume << "in^3\n";
        validPackages++; // Increment valid packages
        totalVolume += volume; // Add volume to total
    }

    // totals file
    totalsFile << "Valid: " << validPackages 
    << "\nInvalid: " << invalidPackages 
    << "\nTotal Volume: " << fixed << setprecision(3) 
    << totalVolume << "\n";

    inputFile.close(); // Close the input file
    conversionsFile.close(); // Close the conversions file
    totalsFile.close(); // Close the totals file

    return 0; // Exit the program
}

