// Pos/Neg Finder
// James Taddei
// 9/13/21

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    
    if (num > 0)
        cout << endl << num << " is positive" << endl;
    else if (num < 0)
        cout << num << " is negative" << endl;
    else
        cout << num << " is zero" << endl;

    return 0;
}