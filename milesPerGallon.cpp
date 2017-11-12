//@author Ralph Harris
// CSC 101 - Mr. Rishel
// This program  prompts the capacity, in gallons, of an automobile fuel 
// tank and the miles per gallon the automobile can be driven. The program 
// outputs the number of miles the automobile can be driven without refueling.

#include <iostream>

using namespace std;

int main()
{
	// Declare variables gallons (Capacity of vehicle),
	// milesPerGallon (fuel efficiency of the vehicle),
	// and milesAvailable (The overall distance the vehicle can drive on a full tank)
	double gallons, milesAvailable, milesPerGallon;

	// This Requests the gallons variable
	cout << "Enter the capacity, in gallons, of your automobile fuel tank: ";
		cin >> gallons;

	//This requests the miles per gallon os the vehicle
	cout << "Enter the miles per gallon the automobile can be driven: ";
		cin >> milesPerGallon;

	// This does the math required for the distance the vehicle can run on a full tank.
	milesAvailable = gallons * milesPerGallon;

	// This ouputs the result
	cout << "Miles available on a full tank without refueling: " << milesAvailable << endl;

	// This pauses so the user can view the result.
	system("pause");
	
		return 0;
}