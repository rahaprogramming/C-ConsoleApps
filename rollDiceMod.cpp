/**************************************************************
@Author - Ralph Harris - CSC-101 - for Mr. Rishel on 10/12/2017

Modify the roll dice program, Example 6-4, so that it allows the
user to enter the desired sum of the numbers to be rolled.  Also allow
the user to call the rollDice function as many times as the user desires.
Instructor’s Notes: For this assignment you will need to write the rollDice
function and call it from your main function.  In the main function, prompt 
the user to enter a number of dice rolls and the value that they are trying to roll.
Call the function that many times and keep track of how many times the dice roll resulted
in the value that the user was trying to roll.

So, for example, your output may look something like this:

What number do you want to roll?

7

How many times do you want to roll the dice?

10

Out of 10 rolls you rolled 7 on 3 rolls.

****************************************************************/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Declare variable
int rollDice(int num); // Roll dice function. Takes userNumber variable as num variable
int userNumber; // store the users choice for the goal roll
int userRolls;// The number of times the user would like to roll dice
int winner; // The number of times the user gets a winning roll

int main()
{
	//Below is the introductory message which explains the rules of the game and asks for the fist variable (userNumer)
	//which is used as the users "winning" number
	cout << "Welcome to the digital dice roller! " << endl 
		<< "We're playing with two six sided dice and The rules are simple..." << endl
		<< "Simply pick a winning numer(2-12) and the number of times you'd like" << endl
		<< "to roll the dice(unlimited) to play." << endl << endl
		<< "What number do you want to roll? " << endl;
	cin >> userNumber; // Store the users "winning" number

	cout << "How many times do you want to roll the dice? " << endl; // request userRolls variable
	cin >> userRolls;// stores the rolls the user would like to make

	rollDice(userNumber); // here we run the function "rollDice" and insert "userNumber" as the "num" parameter
	cout << endl << "Out of " << userRolls << ", rolls you rolled " << userNumber << " on " << winner << " rolls" << endl;// Displays Results summary of rollDice

	system("pause");// pause to view output

    return 0;
}

// I tried to modify the original function as little as possible, however, I really didn't like not having
// the results of the losing rolls displayed. I felt like it took some of the fun out of the game so I 
// included the output of each roll in the function which can easily be commented out if prefered.
// Because the function no longer stops after it hits the correct number, I modified the while statement to run
// until it hits the "userRolls" variable and it now outputs "winner" which is the total successful rolls.
// Besides, the two cout's that is the only change.
int rollDice(int num)
{
	//Declare variables
	int die1;//Dice 1
	int die2;//Dice 2
	int sum;//Sum of dices
	int rollCount = 0;// number of rolls

	srand(time(0));// random number

	do
	{
		die1 = rand() % 6 + 1;// First dice number
		die2 = rand() % 6 + 1;// Second dice number
		sum = die1 + die2;// Total for this roll
		rollCount++;//Add 1 to the number of rolls

		cout << endl << "on roll " << rollCount << " you rolled " << sum << endl << "Dice 1: " << die1 << endl << "Dice 2: " << die2 << endl;// comment out? - Displays each roll

		if (sum == userNumber) // If the roll is the number guessed, record the win and display a message
		{
			winner++;// add a win
			cout << "Thats Your Number!!" << endl;//Comment out? - Displays a success roll
		}
		
	} while (rollCount != userRolls);// run until the number of rolls equals the chosen number of rolls

	return winner; // Return the winning number of rolls
}

