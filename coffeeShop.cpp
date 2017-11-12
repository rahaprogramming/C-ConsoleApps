/***********************************************************************************
@Author Ralph Harris
CSC 101 - for Mr. Rishel 
10/22/2017

Programming Exercise 26 on page 462

Jason opened a coffee shop at the beach and sells coffee in three sizes: 
small (9 oz), medium (12 oz), and large (15 oz). The cost of one small cup is $1.75,
one medium cup is $1.90, and one large cup is $2.00. This is a menu-driven program that
will make the coffee shop operational. This program allows the user to do the following:

Sell coffee in any size and in any number of cups.

At any time, the user can enter "9" to view all of the following:

At any time show the total number of cups of each size sold. - 9 or 2 to view by itself
At any time show the total amount of coffee sold (in ounces). - 9 or 3 to view by itself
At any time show the total money made (gross income). - 9 or 4 to view by itself

This program consists of the following functions: a function to sell
coffee - coffeeMenu(), a function to show the number of cups of each size sold - coffeeByCupSize(), a function to show
to total amount of coffee sold (in ounces) - coffeeByAmount(), and a function to show the total money made - coffeeByDollars(). 
This program does not use any global variables other than named constants. Special values 
such as coffee cup sizes and cost of a coffee cup are declared as named constants.
***********************************************************************************/

#include "stdafx.h"

#include <iostream>
#include <iomanip>
using namespace std;

//global constants for coffee prices and ounces
const double smallCoffeePrice = 1.75;
const double mediumCoffeePrice = 1.90;
const double largeCoffeePrice = 2.00;
const int smallCoffeeSize = 9;
const int mediumCoffeeSize = 12;
const int largeCoffeeSize = 15;

//functions
int storeMenu();
void coffeeSales(int&, int&, int&);
int coffeeMenu();
int getCups();
double totalSales(int, int, int);
void coffeeByCupSize(int, int, int);
void coffeeByAmount(int, int, int);
void coffeeByDollars(int, int, int);

int main()
{

	bool storeOpen = true;// boolean to indicate when to cash out
	int storeOptions = 0;// variable for storeMenu() options

	// the variables below are pretty self explanatory - holds various sizes sold for the day
	int todaySalesSmallCups = 0;
	int todaySalesMediumCups = 0;
	int todaySalesLargeCups = 0;

	//Below are the actions for the main menu - storeMenu() 
	do
	{
		storeOptions = storeMenu(); // the number chosen by the user at the storeMenu()
		switch (storeOptions)
		{
		case 1: 	
			//run coffeeSales() - runs coffeeSales() function for each sale
			coffeeSales(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			break;
		case 2:		
			//run coffeeByCupSize() - shows cups sold
			coffeeByCupSize(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			break;
		case 3:		
			//run coffeeByAmount() - shows ounces sold
			coffeeByAmount(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			break;
		case 4:		
			//run coffeeByDollars() - shows total sales
			coffeeByDollars(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			break;
		case 5:		
			// close program (storeOpen = false) with a summary of sales
			cout << "*****Today's Sales*****" << endl;
			coffeeByCupSize(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			coffeeByAmount(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			coffeeByDollars(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			storeOpen = false;
			break;
		default:	
			// view summary of cups, ounces sold, and total sales - option "9"
			cout << "*****Today's Sales*****" << endl;
			coffeeByCupSize(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			coffeeByAmount(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			coffeeByDollars(todaySalesSmallCups, todaySalesMediumCups, todaySalesLargeCups);
			cout << "*****End Summary*****" << endl;
			break;
		}

	} while (storeOpen != false);
	//run above for any option other than "5". in which case, display goodbye message and exit
	cout << "Have a nice day!" << endl;
	system("pause");
	return 0;
}

// This is the main menu. 
int storeMenu()
{
	int choice;
	cout << endl << "Welcome to the Coffee Shop" << endl;
	cout << "**************************" << endl;
	cout << "1. Sell Coffee" << endl;
	cout << "2. Coffee Sold Today - By Cup Size" << endl;
	cout << "3. Coffee Sold Today - By Ounces" << endl;
	cout << "4. Coffee Sold Today - By Dollars" << endl;
	cout << "5. Close for the day." << endl;
	cout << "\nEnter selection (1-5 or 9 for daily summary): " << endl;
	cin >> choice;
	while (!(choice >= 1 && choice <= 5 || choice == 9))
	{
		// any choice other than those offered will display the following message and ask for a correct choice
		cout << "Invalid Selection - Please re-enter: ";
		cin >> choice;
	}
	return choice;
}

//This function manages each individual sale of coffee
void coffeeSales(int& todaySmall, int& todayMedium, int& todayLarge)
{
	int cups = 0;// variable for number of cups sold of whatever size
	int currentSaleSmallCups = 0;// small cups for this sale
	int currentSaleMediumCups = 0;// medium cups for this sale
	int currentSaleLargeCups = 0;//large cups for this sale
	double currentSaleTotal = 0.0;// total sale ammount (only this one sale)
	int coffeeChoice = 0;// variable for the users selection

	//Below we open the menu to order a coffee and use the getCups() function to manage the 
	//number of each size and display an appropriate message
	do
	{
		coffeeChoice = coffeeMenu();// run the coffee sale menu. put choice in coffeeChoice variable

		switch (coffeeChoice)
		{
		case 1:	
			//order small coffee
			cups = getCups();// run getCups() function to determine amount
			currentSaleSmallCups += cups;// variable for this size
			break;
		case 2: 
			//order medium coffee
			cups = getCups();// run getCups() function to determine amount
			currentSaleMediumCups += cups;// variable for this size
			break;
		case 3: 
			//order large coffee
			cups = getCups();// run getCups() function to determine amount
			currentSaleLargeCups += cups;// variable for this size
			break;
		case 4:
			//Here we give an option to view a summary of the order before it's completed (so the customer knows his total)
			cout << endl << "*****ORDER SUMMARY*****" <<  endl;

			currentSaleTotal = totalSales(currentSaleSmallCups, currentSaleMediumCups, currentSaleLargeCups);
			
			cout << "\nTotal price is $" << setprecision(2) << currentSaleTotal << endl << endl;

			cout << endl << "*****SUMMARY COMPLETE*****" << endl;
			break;
		case 5:
			// This is checkout. We get the current total and display the appropriate message. Then, return to the main menu
			currentSaleTotal = totalSales(currentSaleSmallCups, currentSaleMediumCups, currentSaleLargeCups);
			cout << "\nTotal price is $" << setprecision(2) << currentSaleTotal << endl << endl;
			//add daily totals to the current sale
			todaySmall += currentSaleSmallCups;
			todayMedium += currentSaleMediumCups;
			todayLarge += currentSaleLargeCups;
			cout << "\nThank you for your purchase!" <<  endl << endl;
			break;
		default:
			// view summary of cups, ounces sold, and total sales (at any time)- option "9"
			cout << "*****Today's Sales*****" << endl;
			coffeeByCupSize(todaySmall, todayMedium, todayLarge);
			coffeeByAmount(todaySmall, todayMedium, todayLarge);
			coffeeByDollars(todaySmall, todayMedium, todayLarge);
			cout << "*****End Summary*****" << endl;
			break;
		}

	} while (coffeeChoice != 5);// continue until checkout(option 5)

}

//Here is our menu used in the previous function. It displays the various options to our user
int coffeeMenu()
{
	int choice = 0;
	cout << endl << "Coffee Menu" << endl;
	cout << "***********" << endl;
	cout << "1. Order Small coffee" << endl;
	cout << "2. Order Medium coffee" << endl;
	cout << "3. Order Large coffee" << endl;
	cout << "4. Order Summary" << endl;
	cout << "5. Complete Order" << endl;
	cout << "Enter Selection (1-5 or 9 for daily summary):";
	cin >> choice;
	while (!(choice >= 1 && choice <= 5 || choice == 9))// ask for an appropriate choice if a wrong number is entered
	{
		cout << "Invalid Selection - Please re-enter: ";
		cin >> choice;
	}
	return choice;
}

// below is the function that displays and manages the number of cups for any size coffee
int getCups()
{
	int cups = 0;
	cout << "\nHow many cups?: ";
	cin >> cups;
	cout << endl;
	return cups;
}

//Below if the function that displays the sales for an individual purchase
double totalSales(int small, int medium, int large)
{
	if (small>0)
	{
		
		cout << endl << "\nSmall Cups: " << small << " at $" << fixed << setprecision(2) << smallCoffeePrice << " each: $" << setprecision(2) << small*smallCoffeePrice << endl;
	}
	if (medium>0)
	{
		cout << endl << "Medium Cups: " << medium << " at $" << setprecision(2) << mediumCoffeePrice << " each: $" << setprecision(2) << fixed <<   medium*mediumCoffeePrice << endl;
	}
	if (large>0)
	{
		cout << endl << "Large Cups: " << large << " at $" << setprecision(2) << fixed <<   largeCoffeePrice << " each: $" << setprecision(2) << fixed <<   large*largeCoffeePrice << endl;
	}
	return (small*smallCoffeePrice) + (medium*mediumCoffeePrice) + (large*largeCoffeePrice);
}

//Below is the function that displays the cups sold
void coffeeByCupSize(int small, int medium, int large)
{
	cout << endl << "Coffee Cups Summary" << endl << "*******************" << endl;
	cout << endl << "Coffee Sold Today - Small Cups: " << small << endl;
	cout << endl << "Coffee Sold Today - Medium Cups: " << medium << endl;
	cout << endl << "Coffee Sold Today - Large Cups: " << large << endl;
}

//Below is the function that displays the ounces sold
void coffeeByAmount(int small, int medium, int large)
{
	cout << endl << "Coffee amount Summary" << endl << "*********************" << endl;
	cout << endl << "Coffee Sold Today - Total Ounces: " << (small*smallCoffeeSize) + (medium*mediumCoffeeSize) + (large*largeCoffeeSize) << " ounces" << endl;
}

//Below is the function that displays the total sales
void coffeeByDollars(int small, int medium, int large)
{
	cout << endl << "Coffee sales Summary" << endl << "********************" << endl;
	cout << endl << "Coffee Sold Today - Total Dollars: $" << setprecision (2) << fixed <<   (small*smallCoffeePrice) + (medium*mediumCoffeePrice) + (large*largeCoffeePrice) << endl << endl;
}

