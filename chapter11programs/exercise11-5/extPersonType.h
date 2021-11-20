#ifndef extPersonType_H
#define extPersonType_H

#include <string>
#include "personType.h"
#include "dateType.h"
#include "addressType.h"
using namespace std;

class extPersonType: public personType {
    private:
        string relation; // family member, friend, etc.
        string phoneNum;
        dateType dateOfBirth;
        addressType wholeAddress; // object holding
        // all the person's address info
    public:
        void print() const;
        // Prints all of the person's info
        string getRelation() const;
        // Returns the person's relation
        string getPhoneNum() const;
        // Returns the phone number of the person
        dateType getDateOfBirth() const;
        // Returns a date object holding the person's
        // date of birth
        addressType getWholeAddress() const;
        // Returns an addressType ojbect holding all
        // of the person's addres info
        void setExtPersonInfo(dateType birthday,
            addressType addressObject, string
            firstName = "", string LastName = "", string
            relationship = "", string phoneNumber = "");
        // Sets all of the variables to the inputted
        // data values
        extPersonType();
        // Default constructor
        extPersonType(dateType birthday, addressType
            addressObject, string firstName = "",
            string LastName = "", string
            relationship = "", string phoneNumber = "");
        // Constrcutor with default values (except for 
        // date of birth and address)
};

#endif
