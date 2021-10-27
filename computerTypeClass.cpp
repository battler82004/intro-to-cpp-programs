// ComputerType Class
// James Taddei
// 10/27/21

#include <iostream>
#include <string>
using namespace std;

class ComputerType {
    private:
        string manufacturer, operatingSystem, modelType;
        int ram, hardDrive, yearBuilt;
        double price;
    public: 
        void setManufacturer(string man); // assignment methods
        void setRam(int r);
        void setHardDrive(int hd);
        void setPrice(double pr);
        
        string getManufacturer();
    
    /* advantage of using methods for inputting data is that it
    allows you to limit what can be entered and prevent accidental 
    changes; private means that can't be directly accessed (outputted or 
    changed. Typically, structs are public while classes have private 
    data and public functions (methods) to access the data. Set is the 
    standard prefix for assigning to variables. Get is the standard for 
    accessing (outputing) the variables. Because getManufacturer is 
    defined in the class, it has access to the private data there */
};

//                v--- tells where to find the setManu prototype
void ComputerType::setManufacturer(string man) {
    manufacturer = man;
}

string ComputerType::getManufacturer() {
    return manufacturer;
}

void inputData(ComputerType &computer);
void outputData(const ComputerType &computer);

int main() {
    ComputerType myComputer;
    inputData(myComputer);
    outputData(myComputer);

    return 0;
}

void inputData(ComputerType &computer) {
    string tempStr;
    
    cout << "Enter manufacturer: ";
    getline(cin, tempStr);
    computer.setManufacturer(tempStr);
    
    cout << endl;
}

void outputData(ComputerType &computer) {
    cout << "Manufacturer - " << computer.getManufacturer() << endl;
}