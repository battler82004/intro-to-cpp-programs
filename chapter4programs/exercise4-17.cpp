/*
  Title: Exercise 4-17 (Lowest Price/Sq Ft Calc)
  Description: This program takes the base price and finished area
  (in sq ft) of three house models (colonial, split-entry, and
  single-story) and outputs which one has the lowest cost per sq ft.
  Author: James Taddei
  Date: 9/13/21
*/

#include <iostream>
using namespace std;

int main() {
    // Variable delcaration
    double price1, price2, price3, area1, area2, area3;
    double pricePerSqFt1, pricePerSqFt2, pricePerSqFt3;

    cout << "This program takes the base price and finished area " <<
    "(in sq ft) of three house models (colonial, split-entry, and " <<
    "single-story) and outputs which one has the lowest cost per " <<
    "sq ft." << endl;

    // Variable input
    cout << "Enter the base price and finished area (in sq ft) of the colonial model: ";
    cin >> price1 >> area1;

    cout << endl << "Enter the base price and finished area " <<
    "(in sq ft) of the split-entry model: ";
    cin >> price2 >> area2;

    cout << endl << "Enter the base price and finished area " <<
    "(in sq ft) of the single-story model: ";
    cin >> price3 >> area3;

    // Calculations
    pricePerSqFt1 = price1 / area1;
    pricePerSqFt2 = price2 / area2;
    pricePerSqFt3 = price3 / area3;

    // If the colonial model has a lower cost than the split-entry
    if (pricePerSqFt1 < pricePerSqFt2) {
      if (pricePerSqFt1 < pricePerSqFt3) { // Colonial < Single-story
        cout << endl << "The price per square foot of the " <<
        "colonial model is the least." << endl;
      } else if (pricePerSqFt1 == pricePerSqFt3) { // Colonial = Single-story
        cout << endl << "The price per square foot of the " <<
        "colonial and single-story models tie for the least." << endl;
      } else { // Colonial > Single-story
        cout << endl << "The price per square foot of the " <<
        "single-story model is the least." << endl;
      }
    }
    // If the colonial has an equal cost to the split-entry
    else if (pricePerSqFt1 == pricePerSqFt2) {
      if (pricePerSqFt2 < pricePerSqFt3) { // Split-entry < Single-story
        cout << endl << "The price per square foot of the " <<
        "colonial and split-entry models tie for the least." << endl;
      } else if (pricePerSqFt2 == pricePerSqFt3) { // Split-entry = Single-story
        cout << endl << "The price per square foot all three " <<
        "models are the same." << endl;
      } else { // Split-entry > Single-story
        cout << endl << "The price per square foot of the " << 
        "single-story model is the least." << endl;
      }
    }
    // If the colonial model has a higher cost than the split-entry
    else {
      if (pricePerSqFt2 < pricePerSqFt3) { // Split-entry < Single-story
        cout << endl << "The price per square foot of the " <<
        "split-entry model is the least." << endl;
      } else if (pricePerSqFt2 == pricePerSqFt3) { // Split-entry = Single-story
        cout << endl << "The price per square foot of the " <<
        "single-story and split-entry models tie for the least." <<
        endl;
      } else { // Split-entry > Single-story
        cout << endl << "The price per square foot of the " <<
        "single-story model is the least." << endl;
      }
    }

    return 0;
}
