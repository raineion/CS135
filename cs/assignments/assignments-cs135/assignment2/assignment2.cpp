/*
Name: Daniel Martinez Julio, 2001941913, CS 135, Section 1023
Description: Perform calculations for a sales receipt.
Input: Item name, cost, and quantity as strings and doubles respectively.
Output: Subtotal, tax, total, change, and a formatted receipt.
*/

#include <iostream> // input/output
#include <iomanip> // formatting
#include <string> // strings
#include <cmath> // math functions

using namespace std; // namespace

const double TAX_RATE = 0.0825; // tax rate

void printHeader(); // function prototype

int main() // main function
{
     printHeader(); // call the printHeader function

     // variables
     string name; // item name
     int qty = 0.0; // quantity
     double cost = 0.0, subtotal = 0.0, tax = 0.0,
            total = 0.0, change = 0.0, tendered = 0.0,
            multiplier = 0.0, roundedTax = 0.0;

     // get name
     cout << "Item Name: ";
     getline(cin, name); // get the entire line

     // get cost
     cout << "Item Cost: ";
     cin >> cost;

     // get quantity
     cout << "Quantity:  ";
     cin >> qty; 
     // empty line
     // calculate the subtotal, tax, and total
     subtotal = cost * qty; // calculate the subtotal
     // empty line
     // 2.1: Fix tax rounding
     // used ceil to round up the tax to the nearest cent
     multiplier = 100; // multiplier for rounding
     tax = subtotal * TAX_RATE; // calculate the tax 
     roundedTax = ceil(tax * multiplier) / multiplier; // round the tax
     // empty line
     // swapped tax to roundedTax to fix the rounding issue
     total = subtotal + roundedTax; // calculate the total
     cout << fixed << setprecision(2); // set the precision
     cout << "\nSubtotal:  " << subtotal << endl // subtotal print
          << "Tax:       " << roundedTax << endl // tax print
          << "Total:     " << total << endl // total print
          << endl; // empty line
     // empty line
     // get amount tendered
     cout << "Amount tendered from customer: "; // prompt
     cin >> tendered; // get the amount tendered
     // empty line
     // calculate change
     // had to swap cost to total to get the correct change
     change = tendered - total; // calculate the change
     cout << "\nChange Due: " << change << endl; // change print
     // empty line
     // 2.2: Print the receipt
     cout << "\n/\\/\\/\\/\\/\\/\\/\\/\\/\\" // receipt print
          << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n" // receipt print
          << "|                                      |\n" // empty line
          << "|             UNLV CS Shop             |\n" // unlv cs
          << "|         4505 S Maryland Pkwy         |\n" // address
          << "|          Las Vegas,NV 89154          |\n" // address
          << "|            (702) 895-3011            |\n" // phone #
          << "|                                      |\n" // empty line
          << "| " << left << setw(25) << name << " " // Left align
          << right << fixed << setprecision(2) // Left align the name
          << setw(6) << cost << " x " << qty << " |\n" // cost/qty print
          << "|                                      |\n" // empty line
          << "| Subtotal  " << setw(26) << right << subtotal << " |\n"
          << "| Tax Rate" << setw(27) << fixed << setprecision(2) 
          << (TAX_RATE * 100) << "%" << " |\n" // tax rate print
          << "| Tax  " << setw(31) << right // tax print
          << setprecision(2) << roundedTax << " |\n" // tax print
          << "| Total  " << setw(29) << right << total << " |\n"
          << "|                                      |\n" // empty line
          << "| Tendered " << setw(27) << right << tendered << " |\n"
          << "| Change  " << setw(28) << right << change << " |\n"
          << "|                                      |\n" // empty line
          << "\\/\\/\\/\\/\\/\\/\\/\\/\\" // receipt print
          << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\n"; // receipt print
     // empty line
     return 0; // return from main function
} // end of main function
// printHeader function
void printHeader() 
{         // print the header
     cout << "+------------------------------------"s
          << "-----------------------------------------+ \n" // line
          << "|    UU     UU  NNNN     NN  LL      " // unlv
          << " VV      VV         CCCCCC    SSSSSSSS   | \n" // unlv
          << "|   /UU    /UU /NN/NN   /NN /LL      " // unlv
          << "/VV     /VV        CC////CC  SS//////    | \n" // unlv
          << "|   /UU    /UU /NN//NN  /NN /LL      " // unlv
          << "/VV     /VV       CC    //  /SS          | \n" // unlv
          << "|   /UU    /UU /NN //NN /NN /LL      " // unlv
          << "//VV    VV       /CC        /SSSSSSSSS   | \n" // unlv
          << "|   /UU    /UU /NN  //NN/NN /LL      "
          << " //VV  VV        /CC        ////////SS   | \n" // unlv
          << "|   /UU    /UU /NN   //NNNN /LL      " // unlv
          << "  //VVVV         //CC    CC        /SS   | \n" // unlv
          << "|   //UUUUUUU  /NN    //NNN /LLLLLLLL" // unlv
          << "   //VV           //CCCCCC   SSSSSSSS    | \n" // shop
          << "|    ///////   //      ///  //////// " // unlv
          << "    //             //////   ////////     | \n" // line
          << "|                                    " // empty line
          << "                                         | \n" // line
          << "|                  SSSSSSSS  HH      " // SSSSSSSS
          << "HH    OOOOOOO    PPPPPPP                 | \n" // line
          << "|                 SS//////  /HH     /"
          << "HH   OO/////OO  /PP////PP                | \n" // line
          << "|                /SS        /HH     /" // SS
          << "HH  OO     //OO /PP   /PP                | \n" // line
          << "|                /SSSSSSSSS /HHHHHHHH"
          << "HH /OO      /OO /PPPPPPP                 | \n" // line
          << "|                ////////SS /HH//////" // SS
          << "HH /OO      /OO /PP////                  | \n" // line
          << "|                       /SS /HH     /" // SS
          << "HH //OO     OO  /PP                      | \n" // line
          << "|                 SSSSSSSS  /HH     /" // line
          << "HH  //OOOOOOO   /PP                      | \n" // line
          << "|                ////////   //      /" // SS
          << "/    ///////    //                       | \n" // line
          << "+------------------------------------" // line
          << "-----------------------------------------+ \n"; // line
} // end of printHeader function
