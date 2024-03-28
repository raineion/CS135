/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1023
Description: Perform calculations for a sales receipt.
Input: Item name, cost, and quantity as strings and doubles respectively.
Output: Subtotal, tax, total, change, and a formatted receipt.
*/

#include <iostream> 
#include <iomanip>
#include <cmath>

using namespace std;

const double TAX_RATE = 0.0825;

void printHeader();

// Designated start of the program.

int main(int argc, char const *argv[])
{
	// variables
	int qty = 0;
	double cost = 0.0, subtotal = 0.0, tax = 0.0,
		   total = 0.0, tendered = 0.0, change = 0.0;
	string name = "", cardNumber = "";
	char selection = '\0';
	string cardType = "";
	int firstDigit = 0;
	char response = 0;
	char isValid = true; 


	printHeader();
// 4.4 TODO: Loop until user wants to quit
do {
	do {
		cout << "Item Name: ";
		getline(cin, name);
		if (name.length() < 1 || name.length() > 25)
		{
			cout << "Error: Invalid name.\n";
		}
	} while (name.length() < 1 || name.length() > 25);

	// 4.1 TODO: Loop until valid cost is input
	do {
	cout << "Item Cost: ";
	cin >> cost;

	cin.clear();
	cin.ignore(100, '\n');

	if (!cin || cost < 0.01 || cost >= 1000.00)
		{
			cout << "Error: Invalid cost.\n";
		}
	} while (!cin || cost < 0.01 || cost >= 1000.00);

	// 4.1 TODO: Loop until valid qty is input
	do {
		cout << "Quantity:  ";
		cin >> qty;

		cin.clear();
		cin.ignore(100, '\n');

		if (!cin || qty < 1 || qty >= 10)
		{
			cout << "Error: Invalid quantity.\n";
		}
	} while (!cin || qty < 1 || qty >= 10);

		// Calculate the subtotal, tax, and total
		subtotal = cost * qty;
		tax = ceil(subtotal * TAX_RATE * 100.0) / 100.0;
		total = subtotal + tax;

		cout << fixed << setprecision(2)
		<< "\nSubtotal:  " << subtotal << endl
		<< "Tax:       " << tax << endl
		<< "Total:     " << total << endl
		<< endl;

	// Get cash/card selection
	// 4.2 TODO: Loop until valid selection is made
	do {
	cout << "(C/c) - Cash\n(D/d) - Card\nSelection: ";
	cin >> selection;
	if (!cin || (selection != 'c' && selection != 'C' 
		&& selection != 'd' && selection != 'D'))
	{
		cout << "Error: Invalid selection.";
		cout << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	} while 
	(selection != 'c' && selection != 'C' 
	&& selection != 'd' && selection != 'D');

	switch (selection)
	{
	// Cash
	case 'c':
	case 'C':
	// Get amount tendered
	// 4.1 TODO: Loop until valid tendered amount is input
	do {
		cout << "\nAmount tendered from customer: ";
		cin >> tendered;

		cin.clear();
		cin.ignore(100, '\n');

		if (!cin || tendered < total)
		{
			cout << "Error: Invalid amount tendered.";
		}
	} while (!cin || tendered < total);

	// Calculate change
	change = tendered - total;
	cout << "\nChange Due: " << change << endl;

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
		<< "| Tax Rate " << setw(26)
		<< TAX_RATE * 100 << "% |\n"
		<< "| Tax " << setw(32) << tax << " |\n"
		<< "| Total " << setw(30) << total << " |\n"
		<< "|" << setw(40) << "|\n"
		<< "| Tendered " << setw(27) << tendered << " |\n"
		<< "| Change " << setw(29) << change << " |\n"
		<< "|" << setw(40) << "|\n"
		<< "\\/\\/\\/\\/\\/\\/\\/\\/\\"
		<< "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n";
	break;
	// Card
	case 'd':
	case 'D':
	// Get card number
	// 4.1/4.3 TODO: Loop until valid cardNumber is input
	cin.ignore(100, '\n'	);
	do {
		isValid = true;
		cout << "\nCard Number: ";
		getline(cin, cardNumber);

		if (cardNumber.length() != 16)
		{
			isValid = false;
		}
		else 
		{
			for (size_t i = 0; i < cardNumber.length(); i++)
			{
				if (!isdigit(cardNumber[i]))
				{
					isValid = false;
					break;
				}
			}
			if (cardNumber.length() == 16) {
				firstDigit = cardNumber[0] - '0';

				switch (firstDigit) {
					case 3:
						cardType = "Amex";
						break;
					case 4:
						cardType = "Visa";
						break;
					case 5:
						cardType = "Master";
						break;
					case 6:
						cardType = "Discover";
						break;
					default:
						isValid = false;
						break;
				}
			}
		}
		if (!isValid)
		{
			cout << "Error: Invalid card number.";
		}
	} while (!isValid);
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
		<< "| Tax Rate " << setw(26)
		<< TAX_RATE * 100 << "% |\n"
		<< "| Tax " << setw(32) << tax << " |\n"
		<< "| Total " << setw(30) << total << " |\n"
		<< "|" << setw(40) << "|\n"
		<< "| " << left << setw(37) << "Card Sale"
		<< "|\n"
		<< "| Type" << right << setw(32) << cardType << " |\n"
		<< "| Card" << right << setw(32)
		<< "XXXXXXXXXXXX" + cardNumber.substr(12) << " |\n"
		<< "|" << setw(40) << "|\n"
		<< "\\/\\/\\/\\/\\/\\/\\/\\/\\"
		<< "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n";
		break;
		// Invalid Selection
		default:
		cout << "Error: Invalid selection.\n";
		}

		// 4.4 TODO: Ask user if they want to continue
		cout << endl << "Enter (C/c) to Continue: ";
		cin >> response;
		cin.ignore(100, '\n');
		} while (response == 'C' || response == 'c');
	return 0;
}
// Prints program header.
void printHeader()
{
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
}
