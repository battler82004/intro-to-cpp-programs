#include <iostream>
#include "addressType.h"
using namespace std;

// Returns the street address
string addressType::getStreetAddress() const {
  return streetAddress;
}

// Returns the city's name
string addressType::getCity() const {
  return city;
}

// Returns the state's name
string addressType::getState() const {
  return state;
}

// Returns the zip code
int addressType::getZipCode() const {
  return zipCode;
}

// Prints the address info
void addressType::print() const {
  cout << streetAddress << endl;
  cout << city << ", " << state << " - " << zipCode;
}

// Sets all of the data members to the inputted values
void addressType::setAddress(string address, string
  cityName, string stateName, int zipCodeNum) {
  
  streetAddress = address;
  city = cityName;
  state = stateName;
  zipCode = zipCodeNum;
}

// Constructor with default values
addressType::addressType(string address, string
  cityName, string stateName, int zipCodeNum) {
  
  streetAddress = address;
  city = cityName;
  state = stateName;
  zipCode = zipCodeNum;
}
