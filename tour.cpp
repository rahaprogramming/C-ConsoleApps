/*
@Author - Ralph Harris
CSC 102 - Mr. Rishel's class
Assignment 1 - The knight's Tour
2/3/2018

The following program attempts to solve the chess challenge
known as the knight tour! :) Instructions below:

Follow the guidance in the PDF and write a program that will
perform the following functions:

Create a chess board as a 2D array
Initialize the board to zeroes (note that you can do this at
the time of declaration, but later in the assignment you will
need to re-initialize the board after it has been populated
with values, so you should consider writing a function to do
this now)
Move a "knight" around the board using only moves that are
legal for a knight. Ensure that the knight does not move off
of the board or move to a square that has already been visited
Mark each square visited with the number of the corresponding
move (the starting square will be marked

1) Display the values of the squares on the board such that the
user can track the knight's movements. For example, a 3x3
board might look like
1     6     3
4     0     8
7     2     5
For this part of the assignment you are not expected to
complete a tour At this point your program only needs to:

start from any square (my program starts at the top left)
move until there are no more legal moves left
display the board with the path of the moves noted as above
It is helpful to mark the final move some how to make it
easier to see where the tour finished. My program adds an
asterisk on each side of the final move number.

*/

#include "stdafx.h"
#include <iostream>
#include <random>
using namespace std;

//The following variables are suggested in the text, so let's start there :)
int currentRow, currentColumn;// indicates current position
int moveNumber;// indicates current move
int moveHorizontal[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int moveVertical[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
int counter = 1;//can be 1-64

				//below is our chessboard
int const chessBoardLength = 8;
int chessBoard[chessBoardLength][chessBoardLength];

// I think we'll need an array to store all of the moves
int alreadyThereOnce[8][8];

// to make sure he doesn't go to the same square twice
int nextHorizontalMove;
int nextVerticalMove;
int currentLocationHorizontal = 0;
int currentLocationVertical = 0;

//This seems to be the most reliable way to get a random number without a bias
random_device rd;
mt19937 generator(rd());
uniform_int_distribution<> random(0, 7);

//this function is used to determin how far the program got
int howFarThroughTheSwamp(int chessBoard[][chessBoardLength]) {
	int howFarThroughTheSwamp = 0;
	for (int i = 0; i < chessBoardLength; i++) {
		for (int j = 0; j < chessBoardLength; j++) {
			if (chessBoard[i][j] >= howFarThroughTheSwamp) {
				howFarThroughTheSwamp = chessBoard[i][j];
			}
		}
	}
	return howFarThroughTheSwamp;
}

//The function below prints the finished game
void showMoves(int chessBoard[chessBoardLength][chessBoardLength])
{
	printf("**********-WELCOME TO THE-********\n");
	printf("**********-KNIGHT'S TOUR!-********\n");
	printf("**********************************\n");
	for (int i = 0; i < chessBoardLength; i++) {
		for (int j = 0; j < chessBoardLength; j++) {
			if (j == 0) { cout << "*"; }// add a star at the begginning of the int line
			if (j == 7 && chessBoard[i][j] != howFarThroughTheSwamp(chessBoard))// if the eighth square, start a new line
			{
				printf("%3d *\n", chessBoard[i][j]);//add star and start new int line - not longest but w/ star and last
			}
			else if (j != 7 && chessBoard[i][j] != howFarThroughTheSwamp(chessBoard))
			{
				printf("%3d ", chessBoard[i][j]);//not longest - not last 
			}
			else if (j == 7 && chessBoard[i][j] == howFarThroughTheSwamp(chessBoard)) {
				printf("*%2d *\n", chessBoard[i][j]);// longest and last
			}
			else if (j != 7 && chessBoard[i][j] == howFarThroughTheSwamp(chessBoard)) {
				printf("*%2d ", chessBoard[i][j]);//not last but longest
			}
		}
	}
	printf("**********************************\n\n");
	printf("Thank you for using this program!\n");
	printf("Note: a star denotes the last move (example: *64)\n");
}

// The following program keeps the knight from going to vegas (going offBoard)
bool isOnBoard(int nextHorizontalMove, int nextVerticalMove, int tour[chessBoardLength][chessBoardLength],
	int currentLocationHorizontal, int currentLocationVertical)
{
	if (nextHorizontalMove >= 0 && nextHorizontalMove <= chessBoardLength - 1) {
		if (nextVerticalMove >= 0 && nextVerticalMove <= chessBoardLength - 1) {
			return true;
		}
	}
	return false;
	
}

//What squares has this knight conquered?
bool placesBeen(int placesBeen[][8], int nextHorizontalMove, int nextVerticalMove) {
	bool ret = false;
	for (int i = 0; i < 8;i++) {
		for (int j = 0; j < 8;j++) {
			if (placesBeen[i][j] == 1) {
				if (nextHorizontalMove == j && nextVerticalMove == i) {
					ret = true;
					//cout << "\n\nplacesBeen debug:\n\ni, j: " << i << ", " << j << "\n\n (for j) nextHorizontalMove: " << nextHorizontalMove << " (for i) nextVerticalMove: " << nextVerticalMove << endl << endl;
				}
			}
		}
	}
	return ret;
}

int accessibility(int bestMove[1], nextHorizontalMove, nextVerticalMove) {
	int board[8][8] = 
	{ 
		2,3,4,4,4,4,3,2,
		3,4,6,6,6,6,4,3,
		4,6,8,8,8,8,6,4,
		4,6,8,8,8,8,6,4,
		4,6,8,8,8,8,6,4,
		4,6,8,8,8,8,6,4,
		3,4,6,6,6,6,4,3,
		2,3,4,4,4,4,3,2, 
	}
		/*
		run each possible move through here and return the most accessible
		*/
}
// The main function which sends the knight to his doom!! mwahahaha!!
bool theKnightsDirtyFrightfulTourOfDuty(int ourChessBoard[][8]) {//its a dirty job, but someones gotta do it!

	//mark locations visited with 1
	alreadyThereOnce[0][0] = 1;

	int i = 0;// the index

	//hold current locations
	int currentLocationHorizontal = 0;
	int currentLocationVertical = 0;

	int counter = 0;// how many moves? counter

	//If the knight can no longer move, this stops the program
	int stuckKnightStopper = 0;

	//I liked this better than the nested for loop
	do {
		//get a random number between 0 and 7 for our indices
		i = random(generator);

		stuckKnightStopper++; // increment stuckKnightStopper every time we get to the last of our moves
		if (stuckKnightStopper > 10000)return false;// ten thousand not enough?? nah. that'll work...

		//initialize next move
		nextHorizontalMove = currentLocationHorizontal + moveHorizontal[i];
		nextVerticalMove = currentLocationVertical + moveVertical[i];

		//is he running to vegas?
		bool onBoard = isOnBoard(nextHorizontalMove, nextVerticalMove, ourChessBoard, currentLocationHorizontal, currentLocationVertical);
		bool alreadyBeenThere = placesBeen(alreadyThereOnce, nextHorizontalMove, nextVerticalMove);

		/* // debug stuff
		cout << "\nBelow are the variables for the current iteration: \n\n" << endl;
		cout << "move number (ourChessBoard[nextHorizontalMove][nextVerticalMove]): " << ourChessBoard[nextVerticalMove][nextHorizontalMove] << endl;
		cout << "counter (plus 1): " << counter << endl;
		cout << "onBoard: " << onBoard << endl;
		cout << "alreadyBeenThere: " << alreadyBeenThere << endl;
		cout << "currentLocationHorizontal, currentLocationVertical: " << currentLocationHorizontal << ", " << currentLocationVertical << endl << endl;
		cout << "moveHorizontal[i], moveVertical[i]: " << moveHorizontal[i] << ", " << moveVertical[i] << endl << endl;
		cout << "(currentLocation + moveHorizontal) nextHorizontalMove, nextVerticalMove: " << nextHorizontalMove << ", " << nextVerticalMove << endl;
		cout << "our index is at: " << i << endl << endl;
		cout << "placesBeen(): " << placesBeen(alreadyThereOnce, nextHorizontalMove, nextVerticalMove) << endl << endl;
		*/

		if (onBoard == true && alreadyBeenThere == false) {// he's on the board :) He hasn't been to this square :)

			//set move - start at 1st move 
			ourChessBoard[nextVerticalMove][nextHorizontalMove] = counter + 1;

			//at this point, he's at this new location so lets set that
			currentLocationHorizontal = nextHorizontalMove;
			currentLocationVertical = nextVerticalMove;

			//set this location as visited
			alreadyThereOnce[nextVerticalMove][nextHorizontalMove] = 1;

			/* //debug stuff
			cout << "\nBelow are the variables for the current move: \n\n" << endl;
			cout << "move number (ourChessBoard[nextHorizontalMove][nextVerticalMove]): " << ourChessBoard[nextVerticalMove][nextHorizontalMove] << endl;
			cout << "counter (plus 1): " << counter << endl;
			cout << "nextHorizontalMove, nextVerticalMove: " << nextHorizontalMove << ", " << nextVerticalMove << endl;
			cout << "currentLocationHorizontal, currentLocationVertical: " << currentLocationHorizontal << ", " << currentLocationVertical << endl;
			cout << "our index is at: " << i << endl << endl;
			*/

			//this point forward starts the new iteration- increment move numbers(counter) and go to top of do..while
			counter++;
		}
		else {
			//invalid move - go to the next move (auto)
		}
	} while (counter != 64);

	return true;
}

int main()
{
	if (theKnightsDirtyFrightfulTourOfDuty(chessBoard) == true) {
		cout << "Ladies and gentlement, we have a winner!!\n\n";
		showMoves(chessBoard);
	}
	else {
		cout << "The knight has failed. Off with his head!!!\n\n";
		showMoves(chessBoard);
		cout << "\n\nThe knight tried valiantly!!\n\nHe made it "<<howFarThroughTheSwamp(chessBoard)
			<<" moves through this swamp of a chess board!!\n\n";
	}

	// yeah, THIS is the program I try to save resources on! lol
	do {
		cout << '\n' << "Press the Enter key to exit.";
	} while (cin.get() != '\n');


	return 0;
}
