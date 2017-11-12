/*********************************************************************
Author - Ralph Harrs

CSC 101 - Mr. Rishel

Three employees in a company are up for a special pay increase.  You are given a file, say Homework4_data.txt, with the following data:

Miller Andrew 65789.87 5

Green Sheila 75892.56 6

Sethi Amit 74900.50 6.1

Each input line consists of an employee’s last name, first name, current salary, and percent pay increase. 

For example, in the first input line, the last name of the employee is Miller, the first name is Andrew, the current salary is $65789.87

and the pay increase is 5%. Write a program that reads data from the specified file and stores the output in the file Ch3_Ex7Output.dat.

For each employee, the data must be output in the following form:

firstName lastName updatedSalary.

Format the output of decimal numbers to two decimal places.
*********************************************************************/

#include "stdafx.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;


int main() {

	// Variables used declared here
	string buffer[2]; // using this to store each line
	stringstream theStream; // the file stream

	// Open file streams
	ifstream employeePayFile("Homework4_data.txt");
	ofstream outputFile("Ch3_Ex7Output.dat");

	// If not the end of the file, continue iteration
	while (!employeePayFile.eof() && employeePayFile.good()) {

		// Get a line from the employee file (employeePayFile)
		getline(employeePayFile, buffer[0]); 
		
		//Put that line into our stream
		theStream << buffer[0];

		// Ignore any and all empty lines
		if (theStream.str() == "") continue;

		// Pass employee first name to location 1 and last name to buffer location 0
		theStream >> buffer[0] >> buffer[1];

		// format to output file according to directions - first name, last name.
		outputFile << buffer[1] << " " << buffer[0] << " ";
		
		// Continue stream... put salary and percentage increase into buffer 0 and 1 respectively
		theStream >> buffer[0] >> buffer[1]; // Salary and Percentage

		// Doing the math to increase salary. Enter result into buffer[1]
		buffer[0] = to_string(stof(buffer[0]) * (stof(buffer[1]) / 100)); 

		// Add increase to original pay and input into output file (current line). use setprecision(2) to set to 2 decimal places.
		outputFile << fixed << setprecision(2) << stof(buffer[0]) + stof(buffer[1]) << endl;

		// Clear everything out and get ready for next line of stream
		buffer[0].clear(); buffer[1].clear();
		theStream.str(""); theStream.clear();
	}

	// Indicate success or failure with appropriate message
	if (employeePayFile.fail() || employeePayFile.bad())
	{
		cout << "There is a problem opening this file. possibly wrong directory or filename. Please put in the same directory as payIncrease.cpp " << endl;
	}
	else 
	{
		cout << "New file created and pay successfully updated! " << endl;
	}

	// Close everything out - yayyyyy :)
	employeePayFile.close(); outputFile.close();

	system("pause");
	return 0;
	
}


