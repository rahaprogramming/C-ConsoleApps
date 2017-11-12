/******************************************************
@Author Ralph Harris
CSC-101 Mr. Rishel

The population of a town A is less than the population of town B.
However, the population of town A is growing faster than the population 
of town B. This program prompts the user to enter the population 
and growth rate of each town. The program outputs after how many years the
population of town A will be greater than or equal to the population of town B 
and the population of both towns at that time. (A sample input is: Population of 
town A = 5,000, growth rate of town A = 4%, population of town B = 8,000, and growth rate of town B = 2%.)

*****************************************************************************/

#include "stdafx.h"
#include<iostream>

using namespace std;

int populationA;
int populationB;
double growthRateA;
double growthRateB;
int years = 0;

int main()
{
	/*******
	Below is the intro which explains the rules of this little program
	*******/
	cout << "The population of a town A is less than the population of town B." << endl;
	cout << "However, the population of town A is growing faster than" << endl << "the population of town B.";
	cout << " This program prompts you to" << endl << "enter the population and growth rate of each town." << endl;
	cout << "The program then will output after how many years the population of town A" << endl;
	cout << "will be greater than or equal to the population of town B and the" << endl << "population of both towns at that time." << endl << endl;

	// Prompts user for town A population
	cout << "enter the population of Town A (The one with the lower population): ";
	cin >> populationA;

	// Prompts user for town B population
	cout << "enter the population of Town B (The one with the higher population): ";
	cin >> populationB;

	// Prompts user for town A Growth
	cout << "enter the percentage growth of Town A in the form of (.06 - six percent growth): ";
	cin >> growthRateA;
	growthRateA = growthRateA + 1;

	// Prompts user for town B Growth
	cout << "enter the percentage growth of Town B in the form of (.05 - five percent growth): ";
	cin >> growthRateB;
	growthRateB = growthRateB + 1;

	// cheaters get no rewards - if town A population is larger;  program ends
	if (populationA > populationB || populationA == populationB) {
		cout << "It looks like you put those in backwards, halse. The rules are that town A must be less than town B and not equal" << endl;
		system("pause");
		return 0;
	}

	// cheaters get no rewards - if town B Growth rate is larger;  program ends
	if (growthRateA < growthRateB || growthRateB == growthRateA) {
		cout << "Did you read the paramater there, halse? The rules are that town A must have a faster growth rate than town B and not equal" << endl;
		system("pause");
		return 0;
	}


	// while loop to keep the years adding up until town A overruns town B
	while (1)
	{

		// outputs a message displayiing the year and number of people in each town
		cout << "In year " << years << " there are " << populationA << " people in town A and " << populationB << " people in town B" << endl;
		++years;
		populationB = populationB * growthRateB;
		populationA = populationA * growthRateA;
		// system("pause");

		// once town A is larger the population and year is displayed and program ends
		if (populationA >= populationB)
		{
			cout << endl << "Town A's population has exceeded town B in " << years << " years " << endl << "and has " << populationA - populationB << " more people in it." << endl;
			cout << "Town A's population is now " << populationA << endl;
			cout << "Town B's population is now " << populationB << endl;
			system("pause");
			return 0;
		}

	}
	
    
}

