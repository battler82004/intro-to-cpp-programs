#include <iostream>
using namespace std;

int main() {
    double length, width, area;
    
    cout << "Enter the length of the garden: ";
    cin >> length;
    cout << "Enter the width of the garden: ";
    cin >> width;
    
    area = length * width;
    cout << "The area of the garden is " << area << " square feet."
        << endl;
}
