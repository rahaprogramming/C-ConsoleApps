//@author Ralph Harris
// CSC 101 - Mr. Rishel
// This program prompts the user to input three numbers.
// The program then output the numbers in ascending order.

#include<iostream>

using namespace std;

int main()
{
	// declare the variables for our numbers
	int a, b, c;

	// This lets the user enter the numbers
	cout << "Enter three numbers separated by a single space: ";
	cin >> a >> b >> c;

	// This is the logic that outputs scenario 1
	if (a < b && b < c)
	{
		cout << a << b << c << endl;
	}

	// This is the logic that outputs scenario 2
	else if (a > b && b > c)
	{
		cout << c << b << a << endl;
	}

	// This is the logic that outputs scenario 3
	else if (a < b && b > c)
	{
		cout << a << c << b << endl;
	}

	// This is the logic that outputs scenario 4
	else if (a == b || a == c || c == b)
	{
		cout << "Hey! No duplicating numbers ya whacko!" << endl;
	}

	// This is the logic that outputs scenario 5
	else
	{
		cout << "You entered invalid numbers or a letter. Possibly improperly spaced?" << endl;
	}
	
	// This pauses the screen to allow viewing.
	system("pause");
	return 0;
	
}
	