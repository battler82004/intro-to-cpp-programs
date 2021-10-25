/*
  Title: Exercise 9-4 (Menu Order Calc)
  Description: This program takes in a menu file, output the menu to
  the user, allows the user to select which items they'd like to
  purchase, and outputs what the user bought and their total cost.
  Author: James Taddei
  Date: 10/25/21
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Structure definitions
struct menuItemType
{
    string menuItem;
    double menuPrice;
    bool hasBeenPurchased = false;
};

// Named constants
const int NUM_OF_MENU_ITEMS = 8;

// Function prototypes
void getData(menuItemType menulist[]);
void showMenu(const menuItemType menuList[]);
void userOrder(menuItemType menuList[]);
void printCheck(menuItemType menuList[]);

int main() {
  // Variable declaration
  menuItemType menuList[NUM_OF_MENU_ITEMS];

  // Program description
  cout << "This program takes in a menu file, output the menu to "
  << "the user, allows the user to select which items they'd like to "
  << "purchase, and outputs what the user bought and their total " <<
  "cost." << endl;

  // Output manipulation
  cout << fixed << showpoint << setprecision(2);

  getData(menuList); // Copies the menu into an array from a file
  showMenu(menuList); // Displays the menu to the user
  userOrder(menuList); // Prompts the user to input their order
  printCheck(menuList); // Outputs the users order and its cost

  return 0;
}

// Loads the file data into the array menuList
void getData(menuItemType menuList[]) {
  ifstream menuFile("Ch9_Ex4Data.txt"); // Creates the in file

  // Intakes all of the menu items and their prices
  for (int i = 0; i < NUM_OF_MENU_ITEMS; i++) {
    getline(menuFile, menuList[i].menuItem);
    menuFile >> menuList[i].menuPrice;
    menuFile.ignore(); // Because we have getline following cin
  }

  menuFile.close();
  return;
}

// Outputs the menu to the user
void showMenu(const menuItemType menuList[]) {
  cout << "Welcome to Johnny's Restaurant" << endl <<
  "----Today's Menu----" << endl;
  // Outputs each item on the menu and its price
  for (int i = 0; i < NUM_OF_MENU_ITEMS; i++) {
    cout << i + 1 << ": " << setw(16) << left << menuList[i].menuItem
    << "$" << menuList[i].menuPrice << endl;
  }

  return;
}

// Prompts the user to input their order
void userOrder(menuItemType menuList[]) {
  // Variable declaration
  char moreSelections;
  int itemNum;

  cout << endl << "You can make up to 8 single order selections" <<
  endl << "Do you want to make selection Y/y (Yes), N/n (No): ";
  cin >> moreSelections; // Asks the user if they want to order

  if (moreSelections == 'Y' || moreSelections == 'y') {
    do {
      // This intakes the item the user wants and tells the program
      // that that item has been ordered
      cout << endl << "Enter item number: ";
      cin >> itemNum;
      menuList[(itemNum - 1)].hasBeenPurchased = true;

      cout << endl << endl <<
      "Select another item Y/y (Yes), N/n (No): ";
      cin >> moreSelections; // Checks if the user wants to add more
      // to their order
    } while (moreSelections == 'Y' || moreSelections == 'y');
  }

  return;
}

// Outputs the user's order and its cost
void printCheck(menuItemType menuList[]) {
  // Variable declaration
  double subtotal = 0, taxAmount, totalCost;

  cout << endl << endl << "Welcome to Johnny's Resturant" << endl;
  // This goes through each item and checks if it has been ordered
  for (int i = 0; i < NUM_OF_MENU_ITEMS; i++) {
    if (menuList[i].hasBeenPurchased) {
      cout << setw(16) << left << menuList[i].menuItem << "$" <<
      menuList[i].menuPrice << endl; // Outputs the item if ordered

      subtotal += menuList[i].menuPrice; // Adds the price to the
      // subtotal if ordered
    }
  }

  taxAmount = subtotal * 0.05;
  totalCost = subtotal + taxAmount;
  cout << setw(16) << left << "Tax" << "$" << taxAmount << endl;
  cout << setw(16) << left << "Amount Due" << "$" << totalCost << endl;

  return;
}
