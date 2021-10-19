/*
  Title: Exercise 8-7 (Election Evaluator)
  Description: This program takes in 5 candidates and the number of
  votes that they received and outputs the candidates, the number of
  votes they received, the percent of votes they received, and the
  winner of the election.
  Author: James Taddei
  Date: 10/18/21
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Named constants
const int LEN_OF_LIST = 5;

// Function Prototypes
int totalVotes(const int listOfVotes[]);
void electionWinner(const int listOfVotes[],
  const string listOfNames[]);

int main() {
  // Variable declaration
  string inName;
  string listOfNames[LEN_OF_LIST];
  int inVotes, totalNumOfVotes;
  int listOfVotes[LEN_OF_LIST];

  // Program description
  cout << "This program takes in 5 candidates and the number of "
  << "votes that they received and outputs the candidates, the " <<
  "number of votes they received, the percent of votes they " <<
  "received, and the winner of the election." << endl;

  // Variable input
  for (int i = 0; i < LEN_OF_LIST; i++) {
    cin >> inName >> inVotes;
    listOfNames[i] = inName;
    listOfVotes[i] = inVotes;
  }

  // Manipulates the output and finds the total num of votes
  cout << showpoint << fixed << setprecision(2);
  totalNumOfVotes = totalVotes(listOfVotes);

  // Outputs the header for table
  cout << "Candidate   Votes Received   % of Total Votes" << endl;
  for (int j = 0; j < LEN_OF_LIST; j++) { // Outputs the table
    cout << setw(12) << listOfNames[j] << setw(17) << listOfVotes[j]
    << setw(19) << (static_cast<double>(listOfVotes[j]) /
    totalNumOfVotes) * 100 << endl;
  }

  // Outputs the total num of votes and the winner
  cout << endl << "Total Votes: " << totalNumOfVotes << endl;
  electionWinner(listOfVotes, listOfNames);

  return 0;
}

// Returns the total num of votes
int totalVotes(const int listOfVotes[]) {
  int totalNumOfVotes = 0;
  for (int i = 0; i < LEN_OF_LIST; i++) {
    totalNumOfVotes += listOfVotes[i];
  }

  return totalNumOfVotes;
}

// Outputs the election winner
void electionWinner(const int listOfVotes[],
  const string listOfNames[]) {

  int currWinnerIndex = 0;
  for (int i = 0; i < LEN_OF_LIST; i++) {
    if (listOfVotes[i] > listOfVotes[currWinnerIndex]) {
      currWinnerIndex = i;
    }
  }

  cout << endl;
  cout << "The Winner of the Election is " <<
  listOfNames[currWinnerIndex] << endl;
}
