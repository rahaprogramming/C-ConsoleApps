/*****************************************************************************
@author Ralph Harris

CSC 101 Lab - Mr Rishel

Programming Lab 3

The program mimics the Number Guessing Game. the user has no more than five tries to guess the correct number.  The program prints “You win!”
or “You lose!” depending on the outcome.  Furthermore, if the guessed number is not correct, the program outputs a message
indicating whether the guess is low or high. the variables num and guess are as declared and diff is an int variable.
diff = the absolute value of (num – guess). If diff is not 0.  Then the program outputs the message as follows:

If diff is greater than or equal to 50, the program outputs the message indicating that the guess is very high (if guess is greater than num)
or very low (if guess is less than num).
If diff is greater than or equal to 30 and less than 50, the program outputs the message indicating that the guess is high (if guess is greater
than num) or low (if guess is less than num).
If diff is greater than or equal to 15 and less than 30, the program outputs the message indicating that the guess is moderately high
(if guess is greater than num) or moderately low (if guess is less than num).
If diff is greater than or equal to 0 and less than 15, the program outputs the message indicating that the guess is slightly high
(if guess is greater than num) or slightly low (if guess is less than num).
the user has no more than five tries to guess the number.



*****************************************************************************/

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;
int main(void)
{

	int num = 0; // The random number
	int guess = 0; // the guessed number
	int counter = 1; // number of tries
	int diff = 0; // distance from correct guess
	const char* message; // distance from number message

	srand(time(0));
	num = rand() % 100; // generate a random number 

	cout << "Guess my number! Between 0 and 100. You have 5 tries. Go! ";


	while (1 && counter <= 5) // saves me a bool (isGuessed)
	{
		cin >> guess;
		counter++;

		diff = abs(num - guess); // gives a distance but whether its to hogh or lowis a mystery!

		//Generates a different message depending on the difference. if diff = 0; your a winner!
		if (diff != 0)
		{
			if (diff >= 50)
			{
				message = "very high... or very low!";
			}
			else if (diff >= 30 && diff < 50)
			{
				message = "high... or low!";
			}
			else if (diff >= 15 && diff < 30)
			{
				message = "moderately high... or moderately low! ";
			}
			else { message = "slightly high... or slightly low!"; }
		}
		else
		{
			cout << "You guessed correctly in " << counter << " tries! Congratulations!" << endl;
			break; // end while
		}

		// if guess isnt right & you've guessed less than 5 times (or 5) display "guess again" message
		if (guess != num && counter <= 5 )
		{
			cout << "Your guess is " << message << " Guess again. " << endl;
		}
	
	}

	// too many guesses. you lose :(
	if (counter >= 5) 
	{
		cout << "Sorry, you ran out of tries. It's pretty tough :) The number was " << num << endl; // loser message
	}

	system("pause");
	return 0;
}