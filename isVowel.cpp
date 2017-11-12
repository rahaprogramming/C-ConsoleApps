/*****************************************************************************
@author Ralph Harris 
CSC 101 - Mr. Rishel

Lab Assignment 5

This program uses a value-returning function, isVowel, that returns the value true if 
a given character is a vowel and otherwise returns false. This program 
prompts the user to input a sequence of characters, and the function
checks each character and, when all input is completed, it outputs the sequence entered, 
the number of vowels, and the vowels themselves.
*****************************************************************************/

#include "stdafx.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isVowel(char letter);// initialize our boolean

int main()
{
	string UserLetters = ""; // This variable holds the string entered by the user
	string saveOnlyVowels = ""; // This saves the vowels only

	// Below is the introductory message
	cout << "Hello! Would you like to type visciusly on a keyboard" << endl << "and see how many vowels you randomly get? "
		" if so, this" <<endl <<"is the program for you! type out a string of sentences " << endl <<
		"or characters or whatever and i'll parse " << " it into only" << endl << "vowels for you." <<
		endl << endl << "Go ahead, my friend. type away...: " << endl;

	getline(cin, UserLetters); // This puts the user's input into the string variable (UserLetters)
	
	// The below for loop will loop through the input string (UserLetters) and put all the vowels into the saveOnlyVowels variable
	for (int i = 0; i < UserLetters.length(); i++) {

		char c = UserLetters[i]; // iterate through each string position

		if (isVowel(c))// makes use of the function isVowel and saves 'true' values to variable (saveOnlyVowels)
		{
			saveOnlyVowels += c;
		}// end if
	}// end for

	/*************************************************************************
	This is the output that puts all the pieces together. it outputs the 
	sequence entered, the number of vowels, and the vowels themselves in the 
	following format:

	Of the letters that you entered: Hello Joe
	Their are 4 vowels which are: eloe

	*************************************************************************/
	cout << endl << "Of the letters that you entered: " << UserLetters << endl;
	cout << "Their are " << saveOnlyVowels.length() << " vowels, which are: " << saveOnlyVowels << endl;

	// Below is the thank you message :)
	cout << endl << "Thank you for using this vowel finder!"<<endl << "Brought to you by Mr.Rishel incorporated, Student # 1460: " << endl << endl;

	system("pause");
	return 0;
}

// This fuction uses a switch statement to return true or false as previously noted
bool isVowel(char letter) {
	switch (letter) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}