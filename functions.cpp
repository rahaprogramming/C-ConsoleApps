// functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	inline string file_get_contents(string const path)
		 {
		return (stringstream() << ifstream(path).rdbuf()).str();
		}
    return 0;
}

// program to demonstrate file handling
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	for (int i = 1; i <= 5; i++){for (int j = 1; j <= i; j++){cout << "*";}cout << endl;}// declare variables
	
	string fName, lName;
	
	int age = 0;
	
	double currSalary = 0, percentRaise = 0, newSalary = 0;// create an input file stream and an output file stream
	
	ifstream getMeSomeData;           // the input file stream is named "getMeSomeData"
	
	ofstream writeItToAFile;    // the output file stream is named "writeItToAFile"
								
								// connect the input file stream to an actual file
	
	getMeSomeData.open("test.data.txt");// if the file cannnot be opened, print an error message and return
	
	if (!getMeSomeData){cout << "Input file could not  be opened." << endl;return 1;}
	
	// connect the output file stream to an actual file
	// if the file does not exist, create it
	
	// if the file does exist, overwrite it
	
	writeItToAFile.open("output.data");
	
	// check to make sure the file gets created and/or opened
	
	if (!writeItToAFile){cout << "Output file could not be opened." << endl;return 1;}

	while (!getMeSomeData.eof()) 
	{// read a line of data from the input file and store it in a string//
		
	getMeSomeData >> fName >> lName >> age >> currSalary >> percentRaise;
	
	newSalary = currSalary + currSalary * percentRaise;
	
	// write the string to the output file using the output file 
	streamwriteItToAFile << fName << "\t" << lName <<  "\t" << age <<"\t" << currSalary << "\t" << newSalary << endl;}
	
	// close the file 
	streamswriteItToAFile.close();
	getMeSomeData.close();
	return 0;}