// Kinetic Energy Calculator
// James Taddei
// 10/6/21

#include <iostream>
#include <iomanip>
using namespace std;

double kineticEnergy(double mass, double velocity);

int main() {
    double objMass, objVelocity;
    
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "Enter the object's mass and velocity: ";
    cin >> objMass >> objVelocity;
    
    cout << endl << "An object with a mass of " << objMass << " kilograms"
    << " and a velocity of " << objVelocity << " m/s^2 = " <<
    kineticEnergy(objMass, objVelocity) << endl;
    
    return 0;
}

double kineticEnergy(double mass, double velocity) {
    return (0.5 * mass * velocity * velocity); // ke = 0.5*m*v^2
}