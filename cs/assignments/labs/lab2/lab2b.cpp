/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Perform circle calculations.
Input: Radius as a double.
Output:  Circumference and area of a circle.
*/

#include <iostream>
#include <iomanip>

using namespace std;


const double PI = 3.141592;

int main() {
    double radius = 0;
    cout << "Enter the radius of a circle" << endl;
    cout << "**";
    cin >> radius;

    cout << endl; // extra line 

    double circumference = 2 * PI * radius;
    double area = PI * radius * radius;

    cout << fixed << setprecision(2);

    cout << "+--------+---------------+---------+" << endl;
    cout << "| radius | circumference | area    |" << endl;
    cout << "+--------+---------------+---------+" << endl;
    cout << "| " << setw(6) << left << radius << " | ";
    cout << setw(14) << left << circumference << "| ";
    cout << setw(7) << left << area << " |" << endl;
    cout << "+--------+---------------+---------+" << endl;

    return 0;
}