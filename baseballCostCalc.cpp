// Program to calculate baseball purchases
// Author: James Taddei

// Prompt:
// Write a program which calculates how much a 
// little league baseball team spent last year on baseballs.
// Variables: numOfBaseballs (int), price (double), totalPurchased (double)

#include <iostream>
using namespace std;

int main() {
    // Variable definitions
    int baseballs;
    double price, totalPurchased;
    
    // User input
    cout << "Enter number of baseballs purchased: ";
    cin >> baseballs;
    cout << "Enter the price of a baseball: ";
    cin >> price;
    
    // Calculate purchase price
    totalPurchased = baseballs * price;
    
    // Output results
    cout << "You spent $" << totalPurchased << " on baseballs" << endl;
    
    return 0;
}
