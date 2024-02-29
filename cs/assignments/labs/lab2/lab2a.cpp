/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1021
Description: Practice basic arithmetic operation.
Input: Users are prompted to enter numerical values.
Output: The program displays the results of the arithmetic calculations.
*/

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592;

int main() {
    double degrees = 0;
    cout << "Enter an angle value, in degrees"<< endl;
    cout << "**";
    cin >> degrees;

    double radians = degrees * PI / 180.0;
    double sine = sin(radians);
    double cosine = cos(radians);
    double tangent = tan(radians);

    cout << "\n" << degrees << " degrees = " << radians << " radians\n";
    cout << "sin(" << degrees << ") = " << sine << "\n";
    cout << "cos(" << degrees << ") = " << cosine << "\n";
    cout << "tan(" << degrees << ") = " << tangent << "\n";

    return 0;
}
