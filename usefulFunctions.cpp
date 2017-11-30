/*****************************************************************************************
@Author Ralph Harris

also includes code from runners.cpp
*****************************************************************************************/

#include "stdafx.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void getData(double data[][8], string names[], string const& path);// gets data an puts into our arrays
void getAverage(double data[][8]);// puts average into average[] array
void tabular(double data[][8], string names[], double avg[]);// displays everything
double average[5];// array to store averages

void swap(int& a, int& b);//swaps two ints
Matrix matrix_sum(const Matrix& a, const Matrix& b);// sum 2 matices
void Transpose(Matrix& m);// transpose a matrix
void search(const Matrix& m, int x, int& i, int& j);// search matrix
bool is_symmetric(const Matrix& m);// is matrix symmetric?

vector<int> v(10);
typedef vector< vector<int> > Matrix;

int main()
{
	// Create
	vector<vector<int>> vec(10, vector<int>(10));
	// Write
	vec[2][3] = 10;
	// Read
	int a = vec[2][3];

	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 10; i++) {
			vec[j][i] = i;
			cout << vec[i][j] << endl;
		}
	}


	/*
	double milesRan[5][8];// array for miles ran
	string names[5];//array for names

	getData(milesRan, names, "Lab9_data.txt");// run getData() and put file into arrays
	getAverage(milesRan);// get averages and put into average[] array
	tabular(milesRan, names, average);// display everything in tabular format
	*/
	system("pause");
	return 0;
}

void getData(double data[][8], string names[], string const& path)
{
	ifstream file(path);// open file as variable "file"
	string line;// variable for each line
	int i = 0, j; // This way we aren't restricted to certain number of lines

	while (getline(file, line)) {//get line from "file" and put into "line"
		istringstream line_stream(line);// use stringstream to put each "line" into "line_stream"
		line_stream >> names[i];// add to names[] array
		for (j = 0; j<8; j++) {//each line must be 7 numbers long
			line_stream >> data[i][j];// put into appropriate index
		}
		//increment to next line with no restrictions
		//(it can be 30 lines long if need be, just adjust array variable as needed)
		i++;
	}
	file.close();//close the file
}

//gets the average and puts into average[] array
void getAverage(double data[][8])
{
	double total;// yup :)
	for (int i = 0; i<5; i++)
	{
		total = 0;
		for (int j = 0; j<7; j++)
		{
			total += data[i][j];// add it up
		}
		average[i] = total / 7;//put avg in array
	}
}

//This displays our data in tabular format
void tabular(double data[][8], string names[], double avg[])
{
	cout << setfill('*') << setw(80) << "*";//looks better than dashes
	cout << setfill(' ');
	cout << endl;
	cout << "Name" << setw(7) << "";

	for (int i = 0; i < 7; i++) {// saving lines of code :)
		cout << setw(7) << "Day " << (i + 1);
	}

	cout << setw(12) << "Average" << endl;
	cout << setfill('*') << setw(80) << "*";
	cout << setfill(' ') << endl;
	// end top menu
	for (int i = 0; i<5; i++)// display data
	{
		int size = 10 - names[i].length();// use to line up correctly
		cout << names[i] << setw(size) << " ";// cant use printf on array strings :(
		size = 0;//reset offset
		for (int j = 0; j<7; j++)
		{
			printf("%8.2f", data[i][j]);// the miles
		}
		printf("%12.3f", average[i]);// the average
		cout << endl;
	}
	cout << setfill('*') << setw(80) << "*";
	cout << endl;
}
// sums two vector matrix
Matrix matrix_sum(const Matrix& a, const Matrix& b) {
	int nrows = a.size();
	int ncols = a[0].size();
	Matrix c(nrows, vector<int>(ncols));
	for (int i = 0; i < nrows; ++i) {
		for (int j = 0; j < ncols; ++j) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return c;
}

// Interchanges two values
void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
// Pre: m is a square matrix
// Post: m contains the transpose of the input matrix
void Transpose(Matrix& m) {
	int n = m.size();
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			swap(m[i][j], m[j][i]);
		}
	}
}
// Pre: m is a square matrix
// Returns true if m is symmetric, and false otherwise
bool is_symmetric(const Matrix& m) {
	int n = m.size();
	for (int i = 0; i < n-1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (m[i][j] != m[j][i]) return false;
		}
	}
	return true;
}
// Pre: m is a non-empty matrix
// Post: i and j define the location of a cell
// that contains the value x in M.
// In case x is not in m, then i = j = -1
void search(const Matrix& m, int x, int& i, int& j) {
	int nrows = m.size();
	int ncols = m[0].size();
	for (i = 0; i < nrows; ++i) {
		for (j = 0; j < ncols; ++j) {
			if (m[i][j] == x) return;
		}
	}
	i = -1;
	j = -1;
}

