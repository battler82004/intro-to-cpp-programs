#ifndef addressType_H
#define addressType_H

#include <string>
using namespace std;

class addressType {
    private:
        string streetAddress, city, state;
        int zipCode;
    public:
        string getStreetAddress() const;
        // Returns the street address
        string getCity() const;
        // Returns the city's name
        string getState() const;
        // Returns the state's name
        int getZipCode() const;
        // Returns the zip code
        void print() const;
        // Prints the address info
        void setAddress(string address = "", string
            cityName = "", string stateName = "", int
            zipCodeNum = 0);
        // Sets all of the data members to the inputted
        // values
        addressType(string address = "", string
            cityName = "", string stateName = "", int
            zipCodeNum = 0);
        // Constructor with default vlaues
};

#endif
