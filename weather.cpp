/*************************************************************************
@Author - Ralph Harris
CSC 101 - for Mr. Rishel's class 11/16/2017

This program takes as input a file named Homework8_data.txt containing 
the highest and lowest temperatures from the year. It uses the function getData()
to put the temperatures into an aray called temps[][]. It contains the following 
functions  described below:

getData(double temps[2][12], string const& path) - This gets the data from the 
file and inserts into an array. It requires as parameters, the array name and filename.

The functions below all require the array name as input parameters:
averageHigh(double A[2][12]) - gets the average high temperature from the year
averageLow(double A[2][12])  - gets the average low temperature from the year
indexHighTemp(double A[2][12]) - gets the highest temperature from the year
indexLowTemp(double A[2][12]) - gets the lowest temperature from the year

I tried to make the functions as reusable as possible. For example, the getData() 
function is not restricted by file size as long as there are 12 numbers on each line.

*************************************************************************/

#include "stdafx.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void getData(double temps[2][12], string const& path);
double averageHigh(double A[2][12]);
double averageLow(double A[2][12]);
int indexHighTemp(double A[2][12]);
int indexLowTemp(double A[2][12]);


int main()
{
	double temps[2][12];//declare array to hold temperatures

	// call function which inserts a file into our array - temps[0] = High and temps[1] = low
	// To use this function simply give it an array as the first variable and the file name as the second.
	// It requires 12 numbers per line, but is not restricted by number of lines in the file.
	getData(temps,"Homework8_data.txt");

	// Here we use the averageHigh() function to get the average high from our array - temps[0]
	cout << endl<<"The average high temperature for the year is "
		<< averageHigh(temps) << " degrees";

	// Here we use the averageLow() function to get the average low from our array - temps[1]
	cout << endl<<"The average low temperature for the year is "
		<< averageLow(temps) << " degrees";

	// get the highest value from array temps[0]
	cout << endl<<"The highest temperature for the year is "
		<< indexHighTemp(temps) << " degrees";

	// get the lowest value from array temps[1]
	cout << endl<<"The lowest temperature for the year is "
		<< indexLowTemp(temps) <<" degrees"<<endl;
	
	system("pause");// pause to view output
	return 0;
}

//Below is our function to get data from our file ("string const& path") 
//and insert into any array as ("double temps[2][12]")
void getData(double temps[2][12], string const& path)
{
	ifstream file(path);// open file as variable "file"
	string line;// variable for each line
	int i = 0, j; // This way we aren't restricted to certain number of lines

	while (getline(file, line)) {//get line from "file" and put into "line"
		istringstream line_stream(line);// use stringstream to put each "line" into "line_stream"
		for (j = 0; j<12; j++) {//each line must be 12 numbers long
			line_stream >> temps[i][j];// put into appropriate index - 0=high - 1=low
		}
		//increment to next line with no restrictions
		//(it can be 30 lines long if need be, just adjust array variable as needed)
		i++;
	}
	file.close();//close the file
}
	
//Function gets the average of an array of 12 numbers - array[0][]
double averageHigh(double A[2][12])
{
	double sum = 0;//variable for sum

	for (int i = 0; i < 12; i++)
		sum += A[0][i];//add numbers together and put into "sum" for first row (array[0])
	return (sum / 12);// get and return average
}

//Function gets the average of an array of 12 numbers - array[1][]
double averageLow(double A[2][12])
{
	double sum = 0;//variable for sum

	for (int i = 0; i < 12; i++)
		sum += A[1][i];//add numbers together and put into "sum" for second row (array[1])
	return (sum / 12);// get and return average
}

// function for highest temperature
int indexHighTemp(double A[2][12])
{
	double highest = A[0][0];//put first value into "highest" variable

	for (int i = 1; i < 12; i++)// designed for 12 numbers
		//if next number is highest, it is the highest
		if (A[0][i] > highest)
		{
			highest = A[0][i];// store highest number
		}
	return highest;// return highest number
}

// function for lowest temperature
int indexLowTemp(double A[2][12])
{
	double lowest = A[1][0];//put first value into "lowest" variable

	for (int i = 0; i < 12; i++)// designed for 12 numbers
		//if next number is lowest, it is the lowest
		if (A[i][1] < lowest)
		{
			lowest = A[1][i];// store lowest number
		}
	return lowest;// return lowest number
}

