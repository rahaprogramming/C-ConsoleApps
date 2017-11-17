/*************************************************************************
@Author Ralp Harris
11/16/2017 for Mr. Rishels class

Practice programming assignment for CSC 101 lab finalWrite a program that
will determine the winner of an election based on names and votes stored in
a file. Your program should display on the screen the candidates’ names, the 
number of votes each received, and the winner of the election. Your code must
include at least one user-defined function. Be sure to format and comment your
code appropriately.You may use any resources available (book, notes, Google) 
to assist you. You may not receive assistance from other people either in class
or via any other form of communication. You may assume that each name will consist
of exactly two words separated by a space. You may further assume that the number
of votes will be a positive integer and will follow the last name separated by a 
single space. Your output must be properly formatted. You do not know how many
candidates are in the election but there will never be more than 20. You may NOT 
ask the user how many candidates are in the election. This program should have no
user input required except to close the program after the results are displayed.
The data file is of the following format:

Fred Flintstone 197
George Jetson 285
Scooby Doo 452
Elmer Fudd 38

Sample output for this data would be:
Name                  Number of Votes
*************************************
Fred Flintstone                   197
George Jetson                     285
Scooby Doo                        452
Elmer Fudd                         38
Scooby Doo is the winner.
**************************************************************************/
#include "stdafx.h"


#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void getData(string data[][3], string const& path);
string getWinner(string A[][3]);
string results(string A[][3]);
double totalVotes(string A[][3]);
void candidatesByPercentage(string A[][3]);


int main()
{
	string data[4][3];//declare array
	getData(data, "election.txt");

	cout << results(data);
	cout << getWinner(data) << " is the winner" << endl;
	system("pause");
    return 0;
}

void getData(string data[][3], string const& path)
{
	ifstream file(path);// open file as variable "file"
	string line;// variable for each line
	int i = 0, j; // This way we aren't restricted to certain number of lines

	while (getline(file, line)) {//get line from "file" and put into "line"
		istringstream line_stream(line);// use stringstream to put each "line" into "line_stream"
		for (j = 0; j<3; j++) {
			line_stream >> data[i][j];// put into appropriate index 
		}
		//increment to next line with no restrictions
		//(it can be 30 lines long if need be, just adjust array variable as needed)
		i++;
	}
	file.close();//close the file
}
//output
string results(string A[][3]) {
	string result = "";
	result += "Candidate  name            number of votes \n";
	result += "******************************************* \n";
	result += A[0][0] + "   " + A[0][1] + "                       " + A[0][2] + "\n";
	result += A[1][0] + " " + A[1][1] + "                           " + A[1][2] + "\n";
	result += A[2][0] + " " + A[2][1] + "                              " + A[2][2] + "\n";
	result += A[3][0] + "  " + A[3][1] + "                              " + A[3][2] + "\n";
	return result;
}

//function get winner
string getWinner(string A[][3]){
	int highest = stoi(A[0][2]);
	int winner = 0;

	for (int i = 1; i < 4; i++){
								//if next number is highest, it is the highest
		if (stoi(A[i][2]) > highest)
		{
			highest = stoi(A[i][2]);// store highest number
			winner = i;
		}
	}
	return A[winner][0] + " " + A[winner][1];// return winner
}
//total votes
double totalVotes(string A[][3]){
	double sum = 0;//variable for sum

	for (int i = 0; i < 4; i++)
		sum += stoi(A[i][2]);//add numbers together and put into "sum" 
	return (sum);// get and return 
}

void candidatesByPercentage(string A[][3]) {
	double sum = 0;//variable for sum

	for (int i = 0; i < 4; i++)
		sum += stoi(A[i][2]);//add numbers together and put into "sum" 
	cout << A[0][0] << " " << A[0][1] << " has " << stoi(A[0][2]) / sum << " percentage of the votes" << endl;
	cout << A[1][0] << " " << A[1][1] << " has " << stoi(A[1][2]) / sum << " percentage of the votes" << endl;
	cout << A[2][0] << " " << A[2][1] << " has " << stoi(A[2][2]) / sum << " percentage of the votes" << endl;
	cout << A[3][0] << " " << A[3][1] << " has " << stoi(A[3][2]) / sum << " percentage of the votes" << endl;
}

