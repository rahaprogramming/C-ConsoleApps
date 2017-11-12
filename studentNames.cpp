/***********************************************************************************
@author Ralph Harris
CSC 101 - Mr Rishel
11/2/2017
Programming Exercise 9 on page 518

You are given a file consisting of students’ names in the following form:
lastName, firstName middleName. (Note that some students may not have a middle name.) 
Write a program that converts each name to the following form: firstName middleName
lastName.  Your program must read each student’s entire name into a single variable
and must contain a function that takes as input a string, consisting of a student’s 
complete name, and returns a string consisting of the altered name.

Use the string function find to find the index of ,
the function length to find the length of the string
the function substr to extract the firstName, middleName and lastName.
***********************************************************************************/

#include "stdafx.h"


#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

//using namespace
using namespace std;
string fixNames(string fullName)
{
	//initialize variable
	string firstName = "";
	string middleName = "";
	string lastName = "";
	string fixedNames;
	int comma = fullName.find(',', 0);
	lastName = fullName.substr(0, comma);
	fullName = fullName.substr(comma - 1 + 2);
	int afterComma = fullName.find(' ', 0);
	firstName = fullName.substr(0, afterComma);
	middleName = fullName.substr(afterComma + 1);

	if (middleName == firstName)
	{
		middleName = "";
	}
	// use length function as directed
	if (middleName.length() > 0)
	{
		fixedNames = firstName + " " + middleName + " " + lastName;
	}
	else {
		fixedNames = firstName + " " + lastName;
	}
	return fixedNames;
	// Clear everything out
	firstName.erase(); lastName.erase(); middleName.erase();// used erase() from Table 7-1
}

int main() {
	// Variables used - no comments for self explanatory variables

	string eachStudentLine; // store each line in while statement
	
	
	string outputVariable; // used to display result to the console

	// Open file streams
	ifstream studentInfo("Homework7_data.txt");
	ofstream outputFile("studentInfoOutput.dat");

	// Indicate success or failure with appropriate message
	if (studentInfo.fail() || studentInfo.bad())
	{
		cout << "There is a problem opening this file. possibly wrong directory or filename. Please put in the same directory as studentNames.cpp " << endl;
	}
	else
	{
		cout << "New file created (studentInfoOutput.dat) and successfully updated: " << endl << endl;
	}

	// If not the end of the file, continue iteration
	while (!studentInfo.eof() && studentInfo.good()) {

		string fullName;
		//put line into fullName
		getline(studentInfo, fullName);
		string studentName = fixNames(fullName);
		
		//enter fixed name into output file.
		outputFile << studentName << endl;

		//create variable with the same output as our file 
		outputVariable = studentName;

		//output result to the console for easy error checking etc... - comment out?
		cout << outputVariable << endl;

	}
	cout << endl;// for readability


				 // Close everything out
	studentInfo.close(); outputFile.close();

	system("pause");
	return 0;

}
