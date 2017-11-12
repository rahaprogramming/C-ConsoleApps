// weather.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>


const int rows = 12;	 //make # of rows/cols a constant int
const int cols = 2;


using namespace std;

void getData(int listTemp[rows][cols]);
void averageHigh(int listTemp[rows][cols]);
void averageLow(int listTemp[rows][cols]);
void indexHighTemp(int listTemp[rows][cols]);
void indexLowTemp(int listTemp[cols][cols]);

ifstream infile;
ofstream outfile;

int main()
{


	//  ofstream outfile;
	double average;
	int listTemp[rows][cols];


	infile.open("Homework8_data"); //open infile
	outfile.open("Homework8_dataoutput.txt");

	outfile << fixed << showpoint;   //set showpoint so result will be able to show decimal points
	outfile << setprecision(2);



	getData(listTemp);						   //call functions
	averageHigh(listTemp);
	averageLow(listTemp);
	indexHighTemp(listTemp);
	indexLowTemp(listTemp);



	infile.close();
	outfile.close();

	system("pause");
	return 0;

}

void getData(int listTemp[rows][cols])
{													 //read data in both arrays

	int x;
	int j;
	// ifstream infile;
	//  ofstream outfile;


	for (x = 0; x < rows; x++)
	{
		for (j = 0; j<cols; j++)
		{

			infile >> listTemp[x][j] >> listTemp[x][j];

			//  outfile << listTemp[x][j] << " "<<listTemp[x][j]<< endl;


		}
	}
}
void averageHigh(int listTemp[rows][cols])
{
	int x = 1;
	int Sum = 0;								//read first column and find the average
	double Average;							//from the highs	   


	for (x = 0; x < rows; x++)
	{
		Sum = listTemp[x][0] + Sum;
		// Average = Sum/x;			 
	}
	// Average = Sum/12;

	Average = Sum / x;



	outfile << "Average high for the year: " << Average << endl << endl;


}

void averageLow(int listTemp[rows][cols])
{
	int Sum = 0;											//read the second column and find the
	double Average;
	//average of the lows	   

	for (int x = 0; x < rows; x++)
	{
		Sum = listTemp[x][1] + Sum;
	}
	//  Average = Sum/12;

	Average = Sum / 12;

	outfile << "Average low for the year: " << Average << endl << endl;
}



void indexHighTemp(int listTemp[rows][cols])
{
	int highestIndex = 0;

	//find highest in the "high" column					  
	for (int x = 0; x < rows; x++)
	{
		if (listTemp[0][x] > highestIndex)
			highestIndex = listTemp[0][x];

	}
	outfile << "The index high temperature is " << highestIndex << endl << endl;

}

void indexLowTemp(int listTemp[rows][cols])
{
	int lowestIndex = 0;
	//find the lowest in the low column

	for (int x = 0; x < rows; x++)

	{
		if (lowestIndex > listTemp[0][x])
			lowestIndex = listTemp[0][x];

	}
	outfile << "The index low temperature is " << lowestIndex << endl << endl;
}
