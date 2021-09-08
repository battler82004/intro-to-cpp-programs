/*
  Title: Exercise 3-12 (Distance Calculator)
  Description: This program will find the distance between cars A and
  B based on their inputted speeds and how long they've been moving.
  Author: James Taddei
  Date: 9/7/21
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Variable declaration
    double speedOfA, speedOfB, numOfHours, numOfMins, elapsedTime, travelledByA, travelledByB, shortestDistance;

    // Program description
    cout << "This program will find the shortest distance " << 
    "between cars A and B based on their inputted speeds (in mph)" <<     " and how long they've been moving." << endl;

    // Variable input
    cout << "Speed of Car A (in mph): ";
    cin >> speedOfA;

    cout << endl << "Speed of Car B (in mph): ";
    cin >> speedOfB;

    cout << endl << "Elapsed time (in hours and minutes, separated by a space): ";
    cin >> numOfHours >> numOfMins;

    // Calculations
    elapsedTime = numOfHours + (numOfMins / 60.0); // The elapsed time in hours (as a decimal)
    travelledByA = speedOfA * elapsedTime; // Distance travelled by car A
    travelledByB = speedOfB * elapsedTime; // Distances travelled by car B
    shortestDistance = sqrt(pow(travelledByA, 2) + pow(travelledByB, 2)); // Shortest distance between the 2 cars based on the pythagorean theorem

    // Final outputs
    cout << endl << fixed;
    cout << "The shortest distance between the cars is " <<
    shortestDistance << " miles." << endl;


    return 0;
}
