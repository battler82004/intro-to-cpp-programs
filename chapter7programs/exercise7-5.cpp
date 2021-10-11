/*
  Title: Exercise 7-5 (Tax Amount Calc)
  Description: This program takes a person's marrital status, number of
  children (if married), gross income, and percent contributed towards
  pension and calculates their tax amount.
  Author: James Taddei
  Date: 10/11/21
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const double STANDARD_EXEMP_SINGLE = 4000;
const double STANDARD_EXEMP_MARRIED = 7000;

// Function prototypes
void getData(double& income, double& percentContributedToPension,
  bool& married, int& numOfChildren);
double taxableIncomeCalc(double incomeIn, double
  percentContributedToPensionIn, bool marriedIn, int numOfChildrenIn);
double taxAmount(double taxableIncomeIn);

int main() {
  // Variable declaration
  double income, percentContributedToPension, taxableIncome, taxableAmount;
  bool married;
  int numOfChildren;

  // Program description
  cout << "This program takes a person's marrital status, number of "
  << "children (if married), gross income, and percent contributed " <<
  " towards pension and calculates their tax amount." << endl << endl;

  // Variable input
  getData(income, percentContributedToPension, married,
    numOfChildren);
  
  // Calculates the person's taxable income
  taxableIncome = taxableIncomeCalc(income,
    percentContributedToPension, married, numOfChildren);

  // Calculates the taxes owed by the person
  taxableAmount = taxAmount(taxableIncome);

  // Output manipulation and final output
  cout << setprecision(2) << fixed << showpoint;
  cout << "Your tax would be: $" << taxableAmount << endl;

  return 0;
}

// Data input for the program
void getData(double& income, double& percentContributedToPension,
  bool& married, int& numOfChildren) {
  
  char marriageStatus; // Variable declaration

  cout << "Marrital status: ";
  cin >> marriageStatus;

  if (marriageStatus == 'm') {
    married = true;
    cout << "Number of children (under 14 years): ";
    cin >> numOfChildren;
  }
  else
    married = false;

  cout << endl << "Gross salary (include spouse if you're married): $";
  cin >> income;

  cout << endl << "Percentage of gross income contributed to pension: ";
  cin >> percentContributedToPension;
  cout << endl;
}

// Calculates the person's taxable income
double taxableIncomeCalc(double incomeIn, double
  percentContributedToPensionIn, bool marriedIn, int numOfChildrenIn) {
  
  // Variable declaration
  double taxableIncome = incomeIn;
  int numOfPersonalExempts = 1;

  if (marriedIn)
    taxableIncome -= STANDARD_EXEMP_MARRIED;
  else
    taxableIncome -= STANDARD_EXEMP_SINGLE;

  taxableIncome -= (percentContributedToPensionIn / 100) * incomeIn;

  if (marriedIn)
    numOfPersonalExempts = 2 + numOfChildrenIn;

  taxableIncome -= numOfPersonalExempts * 1500;

  return taxableIncome;
}

// Calculates the person's tax amount
double taxAmount(double taxableIncomeIn) {
  if (taxableIncomeIn <= 15000)
    return 0.15 * taxableIncomeIn;
  else if (taxableIncomeIn <= 40000)
    return 2250 + (0.25 * (taxableIncomeIn - 15000));
  else
    return 8460 + (0.35 * (taxableIncomeIn - 40000));
}
