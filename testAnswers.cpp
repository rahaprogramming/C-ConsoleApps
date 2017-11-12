/*****************************************************************************
@author Ralph Harris
CSC 101 - Mr Rishel
11/2/2017


The history teacher at your school needs help in grading a True/False test. 
The students’ IDs and test answers are stored in a file.  The first entry in 
the file contains answers to the test in the form:

TFFTFFTTTTFFTFTFTFTT

Every other entry in the file is the student ID, followed by a blank, 
followed by the student’s responses.  For example, the entry:

ABC54301 TFTFTFTT TFTFTFFTTFT

Indicates that the student ID is ABC54301 and the answer to question 1 is
True, the answer to question 2 is False, and so on.  This student did not 
answer question 9.  The exam has 20 questions, and the class has more than 
150 students.  Each correct answer is awarded two points, each wrong answer
gets one point deducted, and no answer gets zero points.  Write a program 
that processes the test data.  The output should be the student’s ID, followed 
by the answers, followed by the test theScore, followed by the test grade. 
Assume the following grade scale: 

90% - 100%, A; 80% - 89.99%, B; 70% - 79.99%, C; 60% - 69.99%, D; and 0% - 59.99%, F.

Instructors Notes:  You may want to consider a parallel array structure for 
this assignment.  You should also think about a switch/case structure and, 
obviously, you will need to read and write files.
*****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include<iomanip>

using namespace std;

//variables
const int amountOfTestQuestions = 20;
const int amountOfStudents = 50;
void gradeTest(char studentAnswers[][amountOfTestQuestions], string studentID[], char correctAnswers[]);
char giveAGrade(int theScore);


int main()
{
	// initialize variables
	string studentID[amountOfStudents];
	char correctAnswers[amountOfTestQuestions + 1];
	char studentAnswers[amountOfStudents][amountOfTestQuestions];
	ifstream testAnswers("testAnswers.dat");
	ofstream outputFile("testAnswersOutput.dat");
	
	// correct answers will go first
	testAnswers.getline(correctAnswers, '/n');

	// each students id and answer
	for (int i = 0; i < amountOfStudents; i++) {
		testAnswers >> studentID[i]; // get student ids
		testAnswers.get(); 
		for (int j = 0; j < amountOfTestQuestions; j++)
			studentAnswers[i][j] = testAnswers.get(); // get the students answers
	}

	gradeTest(studentAnswers, studentID, correctAnswers);// run function
	
	system("pause");
	return 0;
}

// function that grades it
void gradeTest(char studentAnswers[][amountOfTestQuestions], string studentID[], char correctAnswers[]) {
	for (int i = 0; i < amountOfStudents; i++) {
		cout << "Student ID: " << studentID[i] << " ";
		int theScore = 0;
		cout << "Answers: ";
		for (int j = 0; j < amountOfTestQuestions; j++) {
			cout << studentAnswers[i][j];
			if (studentAnswers[i][j] == correctAnswers[j])
				theScore += 2; // a correct answer
			else if (studentAnswers[i][j] != correctAnswers[j] && studentAnswers[i][j] != ' ')
				theScore -= 1; // an incorrect answer
		}
		if (theScore < 0)
			theScore = 0; // Don't allow for minus theScores

		cout << " ";
		char grade = giveAGrade(theScore);
		cout << "Grade: " << grade << endl << endl;
	}
}

// function to assign a letter grade
char giveAGrade(int theScore) {
	double percent = static_cast<double>(theScore) / (amountOfTestQuestions * 2);
	cout << fixed << showpoint;
	cout << setprecision(1);
	cout << "Score: " << setw(5) << percent * 100 << "%" << " ";
	if (percent >= 0.9)
		return 'A';
	else if (percent >= 0.8)
		return 'B';
	else if (percent >= 0.7)
		return 'C';
	else if (percent >= 0.6)
		return 'D';
	else
		return 'F';
}

