// ComputerType Struct
// James Taddei
// 10/27/21

#include <iostream>
#include <string>
using namespace std;

struct ComputerType {
    string manufacturer, operatingSystem, modelType;
    int ram, hardDrive, yearBuilt;
    double price;
};

void inputData(ComputerType &computer);
void outputData(const ComputerType &computer);

int main() {
    ComputerType myComputer;
    inputData(myComputer);
    outputData(myComputer);

    return 0;
}

void inputData(ComputerType &computer) {
    cout << "Enter manufacturer: ";
    getline(cin, computer.manufacturer);
    
    cout << "Enter RAM in GB: ";
    cin >> computer.ram;
    
    cout << "Enter hard drive size in TB: ";
    cin >> computer.hardDrive;
    
    cout << "Enter price: ";
    cin >> computer.price;
    
    cout << "Enter year built: ";
    cin >> computer.yearBuilt;
    cin.ignore();
    
    cout << "Enter model (desktop, laptop): ";
    getline(cin, computer.modelType);
    
    cout << "Enter operating system: ";
    getline(cin, computer.operatingSystem);
    cout << endl;
}

void outputData(const ComputerType &computer) {
    cout << "Manufacturer - " << computer.manufacturer << endl;
    cout << "RAM (GB) - " << computer.ram << endl;
}