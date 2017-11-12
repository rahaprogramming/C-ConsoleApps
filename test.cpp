// test.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std;
int main()
{
	int sum, num, j;
	sum = 0;
	cin >> num;
	for (int j = 1; j <= 4; j++)
	{
		sum = sum + num;
		cin >> num;
	}
	cout << sum << endl;

	system("pause");
    return 0;
}

