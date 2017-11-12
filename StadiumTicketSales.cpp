/*******************************************************************************
@author Ralph Harris
CSC 101-Lab Mr. Rishel's class

The manager of a football stadium wants you to write a program that
calculates the total ticket sales after each game. There are four types of
tickets—box, sideline, premium, and general admission. After each game,
data is stored in a file in the following form:
ticketPrice numberOfTicketsSold
...
Sample data are shown below:
250 5750
100 28000
50  35750
25  18750
The first line indicates that the ticket price is $250 and that 5750 tickets were
sold at that price. Output the number of tickets sold and the total sale
amount. Format your output with two decimal places.

******************************************************************************/
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Below All variables are declared
	ifstream stadiumSalesFile; //The Name for our file  

	double boxPrice, sidelinePrice, premiumPrice, generalAdmissionPrice; //Variables for the prices for the various ticket types

	long boxSold, sidelineSold, premiumSold,	generalAdmissionSold;//Variables for the number of tickets sold of each type

	double BoxTotalSales, sidelineTotalSales, premiumTotalSales, generalAdmissionTotalSales;// Variables for the total sales amounts for each ticket type

	long totalNumOfTicketsSold;// Variable for the total tickets sold (totalNumOfTicketsSold)
		
	double totalSaleAmount;// Variable for the total sales (totalSaleAmount)

	stadiumSalesFile.open("Lab4_data.txt"); //opens our file and puts data into this variable


	//Below We put the data in our stadiumSalesFile variable into the correct variable names
	stadiumSalesFile >> boxPrice >> boxSold >> sidelinePrice >> sidelineSold >> premiumPrice >> premiumSold >> generalAdmissionPrice >> generalAdmissionSold;
	
	//Below is the math to obtain our total numbers
	BoxTotalSales = boxPrice * boxSold;// Total Box seat Sales
	sidelineTotalSales = sidelinePrice * sidelineSold;// Total sideline seat Sales
	premiumTotalSales = premiumPrice * premiumSold;// Total premium seat Sales
	generalAdmissionTotalSales = generalAdmissionPrice * generalAdmissionSold;// Total General Admission seat Sales

	totalNumOfTicketsSold = boxSold + sidelineSold + premiumSold + generalAdmissionSold; // Total Tickets sold

	totalSaleAmount = BoxTotalSales + sidelineTotalSales + premiumTotalSales + generalAdmissionTotalSales; //Total Sales Amount
	
	/*************************************************************************
	Below is a nicely formatted summary of the data in the following form:

	The Box tickets sold was: 250 at $10.00 a piece.
	For a total box sales of: $2500.00

	The sideline tickets sold was: 250 at $10.00 a piece.
	For a total sideline sales of: $2500.00

	The premium tickets sold was: 250 at $10.00 a piece.
	For a total premium sales of: $2500.00

	The general admission tickets sold was: 250 at $10.00 a piece.
	For a total general admission sales of: $2500.00


	The total number of all Tickets sold is 1000 tickets
	The total ticket sales adds up to: $10000.00

	Thank you for using This program.

	Also, I used fixed and setprecision(2) to format the output to 2 decimal places
	*******************************************************************************/
	cout << "The Box tickets sold was: " << boxSold << " at $" << fixed << setprecision(2) << boxPrice << " a piece." << endl <<
		+"For a total box sales of: $" << setprecision(2) << BoxTotalSales << endl << endl;

	cout << "The sideline tickets sold was: " << sidelineSold << " at $" << fixed << setprecision(2) << sidelinePrice << " a piece." << endl <<
		+"For a total sideline sales of: $" << setprecision(2) << sidelineTotalSales << endl << endl;

	cout << "The premium tickets sold was: " << premiumSold << " at $" << fixed << setprecision(2) << premiumPrice << " a piece." << endl <<
		+"For a total premium sales of: $" << fixed << setprecision(2) << premiumTotalSales << endl << endl;

	cout << "The general admission tickets sold was: " << generalAdmissionSold << " at $" << fixed << setprecision(2) << generalAdmissionPrice << " a piece." << endl <<
		+"For a total general admission sales of: $" << fixed << setprecision(2) << generalAdmissionTotalSales << endl << endl;

	cout << "The total number of all tickets sold is " << totalNumOfTicketsSold << " tickets" << endl;
	cout << "The total ticket sales adds up to: $" << fixed << setprecision(2) << totalSaleAmount << endl << endl;

	cout << "Thank you for using This program." << endl;// God knows I wanted to be silly here, but kept it super professionale... for you mr. Rishel :)

	system("pause"); //pause to view output
	stadiumSalesFile.close();//close file
	return 0;//exit program
}