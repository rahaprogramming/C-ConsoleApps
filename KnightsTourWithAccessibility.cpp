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
#include <time.h>

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

int startHorizontal;//default is 0 (Top left)
int startVertical;
// I think we'll need an array to store all of the moves
int alreadyThereOnce[8][8];

// to make sure he doesn't go to the same square twice
int nextHorizontalMove;
int nextVerticalMove;
int currentLocationHorizontal = 0;
int currentLocationVertical = 0;
int highestMoves = 0;

/***********************WORKS*****************************/
std::random_device rd;  //Will be used to obtain a seed for the random number engine 
std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
std::uniform_int_distribution<> dis(0, 1);

/********************DOESN'T WORK************************/
//random number function
int random(int a, int b)
{
	srand(time(0));

	double c = rand() % 2;

	if (c < .5)
		return a;
	else
		return b;
} 

//this function is used to determine how far the program got
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
bool isOnBoard(int nextHorizontalMove, int nextVerticalMove,
	int currentLocationHorizontal, int currentLocationVertical)
{
	bool ret = true;
	if (alreadyThereOnce[nextVerticalMove][nextHorizontalMove] == 1) ret = false;// don't go where you've already been, dummy!!

	//for some reason i'm having this return true for negative moves so lets add the following at the top:
		if (nextHorizontalMove < 0) { ret = false; }
		if (nextVerticalMove < 0) { ret = false; }
		//and.... im rewriting this to not nest anything and do tests independent of prerequisite
		if (nextHorizontalMove > 7) { ret = false; }
		if (nextVerticalMove > 7) { ret = false; }

		//this will prevent board jumping - compacted for neatness
		if (currentLocationVertical == 7) { if (nextVerticalMove == 0 || nextVerticalMove == 1) { ret = false; } }
		if (currentLocationVertical == 0) { if (nextVerticalMove == 7 || nextVerticalMove == 6) { ret = false; } }
		if (currentLocationVertical == 6) { if (nextVerticalMove == 0) { ret = false; } }
		if (currentLocationVertical == 1) { if (nextVerticalMove == 7) { ret = false; } }
		if (currentLocationHorizontal == 7) { if (nextHorizontalMove == 0 || nextHorizontalMove == 1) { ret = false; } }
		if (currentLocationHorizontal == 0) { if (nextHorizontalMove == 7 || nextHorizontalMove == 6) { ret = false; } }
		if (currentLocationHorizontal == 6) { if (nextHorizontalMove == 0) { ret = false; } }
		if (currentLocationHorizontal == 1) { if (nextHorizontalMove == 7) { ret = false; } }

		//DEBUG
		//cout << "location: " << currentLocationVertical << ", " << currentLocationHorizontal << "next move: " << nextVerticalMove << ", " << nextHorizontalMove;
		//cout << "\n pass?: " << ret << "\n\n\n\n";
		//if (ret == false)showMoves(alreadyThereOnce);

		//I've learned that too much nesting is BAD!! it does unpredictable things... very wierd stuff.
	return ret;
}

//utility to upgrade aceess for visited squares
void accessibillityUtil(int accessibility[8][8], int currentLocationHorizontal, int currentLocationVertical) {

	//used to set accessibillity values
	int accessibilityValue = 9;
	int counter = 0;

	accessibility[currentLocationVertical][currentLocationHorizontal] = 9;

	int moveHorizontal[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int moveVertical[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

	for (int i = 0;i < 8;i++) {

		//initialize next move
		nextHorizontalMove = currentLocationHorizontal + moveHorizontal[i];
		nextVerticalMove = currentLocationVertical + moveVertical[i];

		//get valid of the 8 moves
		bool onBoard = isOnBoard(nextHorizontalMove, nextVerticalMove, currentLocationHorizontal, currentLocationVertical);


		if (onBoard == true) {

			int currentAccessibillity = accessibility[nextVerticalMove][nextHorizontalMove];

			for (int i = 0; i < chessBoardLength; i++) {
				for (int j = 0; j < chessBoardLength; j++) {
					if (alreadyThereOnce[i][j] == 1) {
						accessibility[i][j] = 9;
					}
				}
			}
		}

	}
}
//need a function to go through all moves and see if there's a move not yet taken
bool stuckKnight(int currentLocationHorizontal, int currentLocationVertical) {
	int moveHorizontal[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int moveVertical[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
	int possibleMoves = 0;
	for (int i = 0; i < chessBoardLength; i++) {
		int hor = currentLocationHorizontal + moveHorizontal[i];
		int vert = currentLocationVertical + moveVertical[i];
		if (alreadyThereOnce[vert][hor] == 0)possibleMoves++;
	}
	if (possibleMoves > 0)return false;
	return true;
}
//self explanatory
bool accessibility(int HorizontalMove, int VerticalMove, int currentLocationHorizontal, int currentLocationVertical) {
	//if he can make a move
	bool ret = true;

	//set this here for the reset
	int accessibility[8][8] =
	{
		1,3,4,4,4,4,3,1,
		3,4,2,6,6,2,4,3,
		4,2,8,8,8,8,2,4,
		4,6,8,8,8,8,6,4,
		4,6,8,8,8,8,6,4,
		4,2,8,8,8,8,2,4,
		3,4,2,6,6,2,4,3,
		1,3,4,4,4,4,3,1,
	};

	//update accessibility values here for correct values on reset
	accessibillityUtil(accessibility, currentLocationHorizontal, currentLocationVertical);

	//hold lowest values
	int lowestVert;
	int lowestHor;
	int lowest = 100;

	int moveHorizontal[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
	int moveVertical[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

	//save index for debugging
	int wasRandomSelection = 0;

	//used to detect when there are no moves left to make
	bool onBoard = false;
	bool beenThere = true;
	bool isStuck = stuckKnight(currentLocationHorizontal, currentLocationVertical);
	if (isStuck == true) { return false; }// onBoard value not found

	int index = 0; //for debugging

	//go through the moves one at a time
	int possibleMoves = 0;
	for (int i = 0;i < 8;i++) {
		beenThere = true;//reset to true

		//initialize next move
		nextHorizontalMove = currentLocationHorizontal + moveHorizontal[i];
		nextVerticalMove = currentLocationVertical + moveVertical[i];

		if (alreadyThereOnce[nextVerticalMove][nextHorizontalMove] == 0) beenThere = false;

		if (beenThere == false) {// if we haven't been there before
			onBoard = false;//reset to false

			possibleMoves++;

			//get valid of the 8 moves
			onBoard = isOnBoard(nextHorizontalMove, nextVerticalMove, currentLocationHorizontal, currentLocationVertical);

			if (onBoard == true) {

				//get lowest move of the valid 8
				if (accessibility[nextVerticalMove][nextHorizontalMove] < lowest) {
					lowest = accessibility[nextVerticalMove][nextHorizontalMove];
					lowestVert = nextVerticalMove;
					lowestHor = nextHorizontalMove;
					index = i;
					wasRandomSelection = 0;
				}
				else if (accessibility[nextVerticalMove][nextHorizontalMove] == lowest) {//choose between previous value and current value randomly if same rating
					if (i > 0) {
						//initialize next move
						int altHorizontalMove = currentLocationHorizontal + moveHorizontal[i - 1];
						int altVerticalMove = currentLocationVertical + moveVertical[i - 1];

						int randomChoice = dis(gen);// make a random decision
						
						if (randomChoice == 0) {
							lowestVert = altVerticalMove;
							lowestHor = altHorizontalMove;
							index = i - 1;
						}
						else {
							lowestVert = nextVerticalMove;
							lowestHor = nextHorizontalMove;
							index = i;
						}

					}
					else {
						continue;//try next move
					}


				}
				//at this point the lowest accessibility should be set - so if it isn't then there's a problem
				if (lowest > 50 || lowest < 0) {
					//DEBUG
					//cout << "\n\n**FLAG: lowest > 50 || lowest < 0 \n" << endl;
					return false;
				}
			
			}//end on board check
			else continue;
			bool stuck = stuckKnight(currentLocationHorizontal, currentLocationVertical);
			if (stuck) { return false; }
		}//end possible moves check
		else {
			continue;//check next move
		}
	}//end moves iteration (we've gone through all possible moves) 
	if (possibleMoves == 0) {
		//DEBUG
		//cout << "**FLAG: possibleMoves=" << possibleMoves << endl;
		return false;
	}
	nextHorizontalMove = lowestHor;
	nextVerticalMove = lowestVert;
	
	//DEBUG
	//cout << "\n\ncurrent possition: " <<currentLocationVertical<<", "<<currentLocationHorizontal << " next move: " << nextVerticalMove << ", " << nextHorizontalMove;
	//cout << "\nindex: " << index << " the actual move: " << moveVertical[index] << ", " << moveHorizontal[index]<<"\n\n";
	//cout << "alreadybeenthere: " << alreadyThereOnce[nextVerticalMove][nextHorizontalMove] << "\n\n";
	//cout << "onBoard: " << onBoard<< "\n\n";

	//also if this happens, he's got no squaresToConquer
	if (nextHorizontalMove < -1000) {
		//DEBUG
		//cout << "\n**FLAG: next move out of range (possible memory leak?):" << nextVerticalMove << ", " << nextHorizontalMove << endl;
		ret = false;
	}
	else {
		ret = true;
	}

	return ret;
}
// The main function which sends the knight to his doom!! mwahahaha!!
bool theKnightsDirtyFrightfulTourOfDuty(int chessBoard[][8]) {//its a dirty job, but someones gotta do it!
	// how many moves? counter
	int counter = 1;

	//used to determine if there's a feasable move
	bool squaresToConquer = true;

	// mark locations visited with 1
	alreadyThereOnce[startVertical][startHorizontal] = 1;// set been there variable

	chessBoard[startVertical][startHorizontal] = counter;// set start chess board

    //set current locations
	int currentLocationHorizontal = startHorizontal;
	int currentLocationVertical = startVertical;

	//I liked this better than the nested for loop
	do {
		//initialize next move
		accessibility(nextHorizontalMove, nextVerticalMove, currentLocationHorizontal, currentLocationVertical);

		//yeah, wierdly paranoid at this point. run the damn thang twice. i care not!
		if (accessibility(nextHorizontalMove, nextVerticalMove, currentLocationHorizontal, currentLocationVertical) == false) {
			return false;
		}


		bool onBoard;
		bool beenThere;
		if (alreadyThereOnce[nextVerticalMove][nextHorizontalMove] == 0) beenThere = false;
		onBoard = isOnBoard(nextHorizontalMove, nextVerticalMove, currentLocationHorizontal, currentLocationVertical);

		if (onBoard == true && beenThere == false) {
			//end if there are no moves to take
			bool stuck = stuckKnight(currentLocationHorizontal, currentLocationVertical);
			if (stuck)return false;

			//set move 
			chessBoard[nextVerticalMove][nextHorizontalMove] = counter + 1;
			alreadyThereOnce[nextVerticalMove][nextHorizontalMove] = 1;

			//DEBUG
			//showMoves(chessBoard);
			//system("pause");

			//at this point, he's at this new location so lets set that
			currentLocationHorizontal = nextHorizontalMove;
			currentLocationVertical = nextVerticalMove;

			//this point forward starts the new iteration - increment move numbers(counter) and go to top of do..while
			counter++;
		}
		else {
			//DEBUG - This ones happens a LOT - why??
			//cout << "ATTEMPTED PLACE WRONG MOVE!!!!!!!!!!!!!!!!!!!!";
		}

	} while (counter != 64);

	return true;
}

//This resets everything to start another tour
void reset(int chessboard[8][8], int alreadyThereOnce[8][8]) {
	for (int i = 0; i < chessBoardLength; i++) {
		for (int j = 0; j < chessBoardLength; j++) {
			chessboard[i][j] = 0;
			alreadyThereOnce[i][j] = 0;
		}
	}
}

int main()
{
	int x, y;
	cout << "Enter your knights starting position (vertical, horizontal)\nMust be 0 through 7... example ( 5 2 ): ";
	cin >> x >> y;

	//make sure this is a valid value. if it's not valid, the default is used (0, 0)
	if (x >= 0 && x < 8 && y >= 0 && y < 8) {
		startVertical = x;
		startHorizontal = y;
	}
	else {//use default
		startVertical = 0;
		startHorizontal = 0;
	}

	bool success = false;
	int attempts = 1;
	int toursCounter = 1;
	int highestMoveAttemptNumber = 0;
	do {
		attempts++;// we stop every so many attempts
		toursCounter++;// total tries
		theKnightsDirtyFrightfulTourOfDuty(chessBoard);
		showMoves(chessBoard);

		//need a way to tell if he made it or not
		int howFar = howFarThroughTheSwamp(chessBoard);
		if (howFar == 64) {
			success = true;
		}
		//keep track of how far he got and the number of moves
		if (howFar >= highestMoves) {
			highestMoves = howFar;
			highestMoveAttemptNumber = toursCounter;
		}
		if (success == false) {
			cout << "\n\non attempt " << toursCounter << " the knight failed!\nHe made it to " << howFar << " moves so the king will allow him another chance at redemption!!\n\n";

			//show his attempts every 200 tries
			if (attempts == 200) {
				cout << "\n\nThis knight has made " << toursCounter << " attempts. His highest move count was on attempt \n" << highestMoveAttemptNumber
					<< " with " << highestMoves << " moves" << endl;
				system("pause");
				attempts = 0;
			}
			//reset 
			reset(chessBoard, alreadyThereOnce);
		}
		
	} while (success == false);

	// on success, show success message!! yayy i'm soooo happy it works finally!!
	cout << "\n\nSUCCESS!! \n" << endl;
	cout << "on attempt " << toursCounter << " the knight finally succeeded!! He has grown strong in his journeys \nand conquered the land!!\n\nCONGRATULATIONS!! You're a Badazzz :) yayyy!\n\n";
	system("pause");

	return 0;
}
