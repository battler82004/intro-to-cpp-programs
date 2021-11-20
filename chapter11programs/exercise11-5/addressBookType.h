#ifndef addressBookType_H
#define addressBookType_H

#include <fstream>
#include <string>
#include "addressType.h"
#include "extPersonType.h"
using namespace std;

class addressBookType {
    private:
        extPersonType contacts[500]; // array of contacts
        int filledIndex = 0; // index of the highest
        // filled in value in contacts
    public:
        void loadDataFromFile(ifstream &inFile);
        // Copies all of the data from inFile into
        // the contacts array
        extPersonType getContact(int index) const;
        // Returns the contact at an index
        void swap(int a, int b);
        // Swaps the contacts at indexes a and b
        // of contacts array
        int searchByLastName(string lastName) const;
        // Returns the index of the contact with a last
        // name equal to the parameter. If no one with
        // the name exists, -1 is returned
        void printBirthdaysInMonth(int month) const;
        // Prints the names of all of the people with
        // a birthday in the inputted month
        void printNamesBetween(string name1, string
            name2) const;
        // Prints the names of all of the people with
        // last names between the two inputted names
        void printRelationType(string relationship) const;
        // Prints the names of all of the people with
        // the inputted relationship type
        void print() const;
        // Outputs all of the data of all of the contacts
        // in the aray contacts
        void printContact(int index) const;
        // Prints the info the contact at the inputted
        // index of array contacts
        void saveToFile(ofstream &outFile) const;
        // Outputs all of the data in contacts into
        // outFile
        void sort();
        // Sorts all of the elements in contacts
};

#endif
