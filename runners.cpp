/*****************************************************************************************
@Author Ralph Harris
CSC 101 for Mr. Rishel's class
Programming Lab and Homework 9
11/23/2017

Jason, Samantha, Ravi, Sheila, and Ankit are preparing for an upcoming marathon. Each day
of the week, they run a certain number of miles and write them into a notebook. At the end
of the week, they would like to know the number of miles run each day, the total miles for 
the week, and average miles run each day. Write a program to help them analyze their data. 
Your program must contain parallel arrays: an array to store the names of the runners and 
a two-dimensional array of five rows and seven columns to store the number of miles run by
each runner each day. Furthermore, your program must contain at least the following functions:

1) A function to read and store the runners’ names and the numbers of miles run each day; 

2) A function to find the total miles run by each runner and the average number of miles run each 
day;

3) A function to output the results. 

Your may assume that the input data is stored in a file and each line of data is in the 
following form: 

runnerName milesDay1 milesDay2 milesDay3 milesDay4 milesDay5 milesDay6 milesDay7.



*****************************************************************************************/

#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

void getData(double data[][8], string names[], string const& path);// gets data an puts into our arrays
void getAverage(double data[][8]);// puts average into average[] array
void tabular(double data[][8], string names[], double avg[]);// displays everything
double average[5];// array to store averages

int main()
{
	
	double milesRan[5][8];// array for miles ran
	string names[5];//array for names
	
	getData(milesRan, names, "Lab9_data.txt");// run getData() and put file into arrays
	getAverage(milesRan);// get averages and put into average[] array
	tabular(milesRan, names, average);// display everything in tabular format

	system("pause");
    return 0;
}

void getData(double data[][8], string names[], string const& path)
{
	ifstream file(path);// open file as variable "file"
	string line;// variable for each line
	int i = 0, j; // This way we aren't restricted to certain number of lines

	while (getline(file, line)) {//get line from "file" and put into "line"
		istringstream line_stream(line);// use stringstream to put each "line" into "line_stream"
		line_stream >> names[i];// add to names[] array
		for (j = 0; j<8; j++) {//each line must be 8 numbers long
			line_stream >> data[i][j];// put into appropriate index
		}
		//increment to next line with no restrictions
		//(it can be 30 lines long if need be, just adjust array variable as needed)
		i++;
	}
	file.close();//close the file
}

//gets the average and puts into average[] array
void getAverage(double data[][8])
{
	double total;// yup :)
	for (int i = 0; i<5; i++)
	{
		total = 0;
		for (int j = 0; j<7; j++)
		{
			total += data[i][j];// add it up
		}
		average[i] = total / 7;//put avg in array
	}
}

//This displays our data in tabular format
void tabular(double data[][8], string names[], double avg[])
{
	cout << setfill('*') << setw(80) << "*";//looks better than dashes
	cout << setfill(' ');
	cout << endl;
	cout << "Name" << setw(7) << "";

	for (int i = 0; i < 7; i++) {// saving lines of code :)
		cout << setw(7) << "Day " << (i + 1);
	}
	
	cout << setw(12) << "Average" << endl;
	cout << setfill('*') << setw(80) << "*";
	cout << setfill(' ') << endl;
	// end top menu
	for (int i = 0; i<5; i++)// display data
	{
		int size = 10-names[i].length();// use to line up correctly
		cout << names[i] << setw(size) << " ";// cant use printf on array strings :(
		size = 0;//reset offset
		for (int j = 0; j<7; j++)
		{
			printf("%8.2f", data[i][j]);// the miles
		}
		printf("%12.3f", average[i]);// the average
		cout << endl;
	}
	cout << setfill('*') << setw(80) << "*";
	cout << endl;
}
