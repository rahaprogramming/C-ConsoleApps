/*****************************************************************************
@author Ralph Harris

CSC 101 - Mr Rishel

Programming Homework 2

This is a program that mimics a calculator. The program takes as input
two integers and the operation to be performed. It then outputs the
numbers, the operator, and the result. (For division, if the denominator is
zero, and an appropriate message is output.)


*****************************************************************************/

#include "stdafx.h"
#include <iostream>

using namespace std;
int main()
{
	//Below our variables are defined. number A, number B, and numberC is the result
	double numberA, numberB, numberC;

	// the operation to be performed 
	char op;


	cout << "Welcome to my little calculator program" << endl;
	cout << "You'll be asked to enter two numbers followed" << endl << "by the operation you'd like to perform" << endl;

	cout << "enter your first number: ";
	cin >> numberA; // set variable
	cout << "enter your second number: ";
	cin >> numberB; // set variable
	cout << "enter either addition, subtraction, multiplication or division as: [ + - * / ]: " << endl;
	cin >> op; // set variable 
	switch (op) {
	case '+':
		// if user is using addition
		numberC = numberA + numberB; // the math - also set numberC as result
		break;
	case '-':
		// if user is using subtraction
		numberC = numberA - numberB; // the math - also set numberC as result
		break;
	case '*':
		// if user is using multiplication
		numberC = numberA*numberB; // the math - also set numberC as result
		break;
	case '/':
		// if user is using division
		if (numberB == 0) {
			// error message for division by zero
			cout << "error: division by zero causes this program to explode. stand back!" << endl;
			system("pause");
			return 0;
		}
		numberC = numberA / numberB;
		break;
	default:
		// error message for unknown operator
		cout << "error: unknown operator - stick to the rules, fella!" << endl;
		system("pause");
		return 0;
	
	}
	//display result
	cout << numberA << ' ' << op << ' ' << numberB << " = " << numberC << endl;

	system("pause");
	return 0;
	
	
}