/*
  Title: Exercise 2-9 (Test Score Averager)
  Description: This program will find the average score of 5 inputted test scores.
  Author: James Taddei
  Date: 8/31/21
*/

#include <iostream>
using namespace std;

int main() {
    double testScoreOne, testScoreTwo, testScoreThree, testScoreFour, testScoreFive, totalTestScores, avgTestScore;

    cout << "This program will find the average of 5 inputted test scores." << endl;

    cout << "Enter the first test score: ";
    cin >> testScoreOne;

    cout << endl << "Enter the second test score: ";
    cin >> testScoreTwo;

    cout << endl << "Enter the third test score: ";
    cin >> testScoreThree;

    cout << endl << "Enter the fourth test score: ";
    cin >> testScoreFour;

    cout << endl << "Enter the fifth test score: ";
    cin >> testScoreFive;

    totalTestScores = testScoreOne + testScoreTwo + testScoreThree + testScoreFour + testScoreFive;
    avgTestScore = totalTestScores / 5;

    cout << endl << "Your average test score is: " << avgTestScore << endl;

    return 0;
}
