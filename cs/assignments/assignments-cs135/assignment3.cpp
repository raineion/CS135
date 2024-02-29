/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1023
Description: Perform calculations for a sales receipt.
Input: Item name, cost, and quantity as strings and doubles respectively.
Output: Subtotal, tax, total, change, and a formatted receipt.
*/

#include <iostream> // input and output
#include <iomanip> // format output 
#include <cmath> // math functions

using namespace std; // standard library

const double TAX_RATE = 0.0825; // tax rate

void printHeader(); // function prototype

// Designated start of the program.
int main()
{
	printHeader();
	// Variable declarations
	int qty = 0;
	double cost = 0.0, subtotal = 0.0, tax = 0.0, multiplier = 0.0,
		   total = 0.0, tendered = 0.0, change = 0.0;
	string name = ""; 

	// Get name, cost, and quantity
	cout << "Item Name: "; // prompt
	getline(cin, name); // input
	// 3.1 TODO: Quit program if name length < 1 or name length > 25
	if (name.length() < 1 || name.length() > 25) {
		cout << "Error: Invalid name." << endl;
		return 0; // end
	}

	cout << "Item Cost: "; // prompt
	cin >> cost; // input
	// 3.1 TODO: Quit program if cost < 0 or cost >= 1000
	if (cost < 0 || cost >= 1000) {
		cout << "Error: invalid cost." << endl;
		return 0; // end
	}
	// 3.3 TODO: Quit program if input failure
	if (cin.fail()) {
		cout << "Error: Invalid cost." << endl;
		return 0; // end
	}
	cout << "Quantity:  "; // prompt
	cin >> qty; // input
	// 3.1 TODO: Quit program if qty < 1 or qty > 9
	if (qty < 1 || qty > 9) {
		cout << "Error: Invalid quantity." << endl;
		return 0; // end
	}
	// 3.3 TODO: Quit program if input failure
	if (cin.fail()) {
		cout << "Error: Invalid input." << endl;
		return 0; // end
	}

	// Calculate the subtotal, tax, total, and change
	subtotal = cost * qty; // calculate subtotal
	multiplier = pow(10.0, 2); // multiplier for rounding
	tax = ceil(subtotal * TAX_RATE * multiplier) / multiplier;
	total = subtotal + tax; // calculate total

	cout << fixed << setprecision(2) // format output
		 << "\nSubtotal:  " << subtotal << endl // subtotal
		 << "Tax:       " << tax << endl // tax
		 << "Total:     " << total << endl // total
		 << endl; // new line

	// 3.4 TODO: Get cash/card selection
	// Get cash/card selection
	char selection = 0; // payment selection
	cout << "(C/c) - Cash\n(D/d) - Card\nSelection: ";
	cin >> selection; // input
	
	// 3.4 TODO: Place logic for tendered/change/cash receipt 
	//           in the cash cases of a switch statement.
	//          Add logic for cards/default to switch statement.
	switch (selection) {
		case 'C': 
		case 'c': 
			cout << "\nAmount tendered from customer: ";
			cin >> tendered; // input
			if (tendered < total) {
				cout << "Error: Invalid amount tendered." << endl;
				return 0; // end
			} // end of if
			change = tendered - total; // calculate change
			cout << "\nChange Due: " << change << endl;
			if (cin.fail()) {  
				cout << "Error: Invalid input." << endl;
				return 0; // end
			} // end of if
			// Print the receipt
			cout << "\n/\\/\\/\\/\\/\\/\\/\\/\\/\\"
				<< "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n"
				<< "|" << setw(40) << "|\n"
				<< "|             UNLV CS Shop             |\n"
				<< "|         4505 S Maryland Pkwy         |\n"
				<< "|          Las Vegas,NV 89154          |\n"
				<< "|            (702) 895-3011            |\n"
				<< "|" << setw(40) << "|\n"
				<< "| " << left << setw(26) << name
				<< right << setw(6) << cost << " x " << qty << " |\n"
				<< "|" << setw(40) << "|\n"
				<< "| Subtotal " << setw(27) << subtotal << " |\n"
				<< "| Tax Rate " << setw(26) << TAX_RATE * 100 << "% |\n"
				<< "| Tax " << setw(32) << tax << " |\n"
				<< "| Total " << setw(30) << total << " |\n"
				<< "|" << setw(40) << "|\n"
				<< "| Tendered " << setw(27) << tendered << " |\n"
				<< "| Change " << setw(29) << change << " |\n"
				<< "|" << setw(40) << "|\n"
				<< "\\/\\/\\/\\/\\/\\/\\/\\/\\"
				<< "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n";
			break; 
		case 'D':
		case 'd': {
			// Card payment logic
			string cardNumber; // card number
			cout << "\nCard number: "; // prompt
			cin >> cardNumber; // input
			if (cin.fail()) { 
				cout << "Error: Invalid input." << endl; 
				return 0; // end
			} // end of if
			if (cardNumber.length() != 16) {
				cout << "Error: Invalid card number." << endl;
				return 0; // end
			} // end of if
			// empty line
			// Print the card receipt
			cout << "\n/\\/\\/\\/\\/\\/\\/\\/\\/\\"
				 << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n"
				 << "|" << setw(40) << "|\n"
				 << "|             UNLV CS Shop             |\n"
				 << "|         4505 S Maryland Pkwy         |\n"
				 << "|          Las Vegas,NV 89154          |\n"
				 << "|            (702) 895-3011            |\n"
				 << "|" << setw(40) << "|\n"
				 << "| " << left << setw(26) << name // item name
				 << right << setw(6) << cost << " x " << qty << " |\n"
				 << "|" << setw(40) << "|\n"
				 << "| Subtotal " << setw(27) << subtotal << " |\n"
				 << "| Tax Rate " << setw(26) << TAX_RATE * 100 << "% |\n"
				 << "| Tax " << setw(32) << tax << " |\n"
				 << "| Total " << setw(30) << total << " |\n"
				 << "|" << setw(40) << "|\n"
				 << "| Card Sale " << setw(29) << "|\n" // card sale
				 << "| Card " << right << setw(27) << string(12, 'X') 
				 << cardNumber.substr(cardNumber.length() - 4) << " |\n"
				 << "|" << setw(40) << "|\n" // card number
				 << "\\/\\/\\/\\/\\/\\/\\/\\/\\"
				 << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n";
			break; // end of case 'D' and 'd'
		} // end of case 'D' and 'd'
		default: // default case
			cout << "Error: Invalid selection." << endl; 
			return 0; // end
	}
	return 0; // end
} // end of main

// Prints program header.
void printHeader()
{ 
	cout << "+------------------------------------" // program header
		 << "-----------------------------------------+ \n"
		 << "|    UU     UU  NNNN     NN  LL      " // program header
		 << " VV      VV         CCCCCC    SSSSSSSS   | \n"
		 << "|   /UU    /UU /NN/NN   /NN /LL      " // program header
		 << "/VV     /VV        CC////CC  SS//////    | \n"
		 << "|   /UU    /UU /NN//NN  /NN /LL      " // program header
		 << "/VV     /VV       CC    //  /SS          | \n"
		 << "|   /UU    /UU /NN //NN /NN /LL      " // program header
		 << "//VV    VV       /CC        /SSSSSSSSS   | \n"
		 << "|   /UU    /UU /NN  //NN/NN /LL      " // program header
		 << " //VV  VV        /CC        ////////SS   | \n"
		 << "|   /UU    /UU /NN   //NNNN /LL      " // program header
		 << "  //VVVV         //CC    CC        /SS   | \n"
		 << "|   //UUUUUUU  /NN    //NNN /LLLLLLLL" // program header 
		 << "   //VV           //CCCCCC   SSSSSSSS    | \n"
		 << "|    ///////   //      ///  //////// " // program header
		 << "    //             //////   ////////     | \n"
		 << "|                                    " // program header
		 << "                                         | \n"
		 << "|                  SSSSSSSS  HH      " // program header
		 << "HH    OOOOOOO    PPPPPPP                 | \n"
		 << "|                 SS//////  /HH     /" // program header
		 << "HH   OO/////OO  /PP////PP                | \n"
		 << "|                /SS        /HH     /" // program header
		 << "HH  OO     //OO /PP   /PP                | \n"
		 << "|                /SSSSSSSSS /HHHHHHHH" // program header
		 << "HH /OO      /OO /PPPPPPP                 | \n"
		 << "|                ////////SS /HH//////" // program header
		 << "HH /OO      /OO /PP////                  | \n"
		 << "|                       /SS /HH     /" // program header
		 << "HH //OO     OO  /PP                      | \n"
		 << "|                 SSSSSSSS  /HH     /" // program header
		 << "HH  //OOOOOOO   /PP                      | \n" 
		 << "|                ////////   //      /" // program header
		 << "/    ///////    //                       | \n"
		 << "+------------------------------------" // program header
		 << "-----------------------------------------+ \n";
} // end of printHeader
