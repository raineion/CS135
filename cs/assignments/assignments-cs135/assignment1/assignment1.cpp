/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1023
Description: Perform circle calculations.
Input: Radius as a double.
Output:  Circumference and area of a circle.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

const double TAX_RATE = 0.0825;

int main(int argc, char const *argv[])
{
	// Variables declarations
	string name = "";
	double cost = 0.0, subtotal = 0.0, tax = 0.0,
		   total = 0.0, tendered = 0.0, change = 0.0;
	int qty = 0;

	// Program header
	cout << "+------------------------------------"
		 << "-----------------------------------------+ \n"
		 << "|    UU     UU  NNNN     NN  LL      "
		 << " VV      VV         CCCCCC    SSSSSSSS   | \n"
		 << "|   /UU    /UU /NN/NN   /NN /LL      "
		 << "/VV     /VV        CC////CC  SS//////    | \n"
		 << "|   /UU    /UU /NN//NN  /NN /LL      "
		 << "/VV     /VV       CC    //  /SS          | \n"
		 << "|   /UU    /UU /NN //NN /NN /LL      "
		 << "//VV    VV       /CC        /SSSSSSSSS   | \n"
		 << "|   /UU    /UU /NN  //NN/NN /LL      "
		 << " //VV  VV        /CC        ////////SS   | \n"
		 << "|   /UU    /UU /NN   //NNNN /LL      "
		 << "  //VVVV         //CC    CC        /SS   | \n"
		 << "|   //UUUUUUU  /NN    //NNN /LLLLLLLL"
		 << "   //VV           //CCCCCC   SSSSSSSS    | \n"
		 << "|    ///////   //      ///  //////// "
		 << "    //             //////   ////////     | \n"
		 << "|                                    "
		 << "                                         | \n"
		 << "|                  SSSSSSSS  HH      "
		 << "HH    OOOOOOO    PPPPPPP                 | \n"
		 << "|                 SS//////  /HH     /"
		 << "HH   OO/////OO  /PP////PP                | \n"
		 << "|                /SS        /HH     /"
		 << "HH  OO     //OO /PP   /PP                | \n"
		 << "|                /SSSSSSSSS /HHHHHHHH"
		 << "HH /OO      /OO /PPPPPPP                 | \n"
		 << "|                ////////SS /HH//////"
		 << "HH /OO      /OO /PP////                  | \n"
		 << "|                       /SS /HH     /"
		 << "HH //OO     OO  /PP                      | \n"
		 << "|                 SSSSSSSS  /HH     /"
		 << "HH  //OOOOOOO   /PP                      | \n"
		 << "|                ////////   //      /"
		 << "/    ///////    //                       | \n"
		 << "+------------------------------------"
		 << "-----------------------------------------+ \n";

	// Input
	cout << "Item Name: ";
	getline(cin, name);
	cout << "Item Cost: ";
	cin >> cost;
	cout << "Quantity:  ";
	cin >> qty;
	cout << endl; // Blank line
    
	// Calculations
	subtotal = cost * qty;
	tax = subtotal * TAX_RATE;
	total = subtotal + tax;

	// Output
    cout << "Subtotal:  " << subtotal << endl;
    cout << "Tax:       "  << tax << endl;
    cout << "Total:     " << total << endl;
    cout << endl; // Blank line

	cout << "Amount tendered from customer: ";
	cin >> tendered;
	cout << endl; // Blank line
	change = tendered - total;

	cout << "Change Due: " << change << endl;
	return 0;
}
