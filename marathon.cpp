
#include <iostream>

#include <string>

#include <fstream>

#include <iomanip>

using namespace std;

//declare the gobal array of type double

double average[5];

//declare the function prototypes

void getData(ifstream& inf, string n[], double runData[][8],int count);

void calculateAverage(double runData[][8], int count);

void print(string n[], double runData[][8], int count);

int main()

{

    string names[5];

    double runningData[5][8];

    ifstream inputfile("runs.txt");

    if(inputfile)

    {

         //call themethod getData

        getData(inputfile, names, runningData, 5);

    }

    else

    {

         //errormessage

        cout<<"Sorry! Unable to open the file."<<endl;

        system("pause");

         return 0;

    }

    //close the file

    inputfile.close();

    //call the method calculateAverage to computethe

    //average miliage of each runner

    calculateAverage(runningData, 5);

    //call display the names and their weekly runrate and their averages

    print(names, runningData, 5);

    system("pause");

    return 0;

}

//definition of method getData that reads the data from the fileand

//stores the names into array n and run data into runDataarray

//simultaneously.

void getData(ifstream& inf, string n[], double runData[][8],int count)

{

    while(!inf.eof())

    {

         for(inti=0;i<count; i++)

         {

            inf>>n[i];

            for(int j=0;j<7;j++)

            {

                inf>>runData[i][j];

            }

         }

    }

}

//definition of method calculateAverage that comptes the totalfirst

//then stores the value of average into the average array

void calculateAverage(double runData[][8], int count)

{

    double total;

    for(int i=0;i<count;i++)

    {

         total=0;

         for(intj=0;j<7;j++)

         {

            total+=runData[i][j];

        }     

        average[i]=total/7;    

    }

}

//definition of method print that prints the output

//in a tabular format

void print(string n[], double runData[][8], int count)

{

   cout<<setfill('=')<<setw(80)<<"=";

    cout<<setfill(' ');

    cout<<endl;

   cout<<"Name"<<setw(6)<<"";

    for(int i=0;i<7;i++)

        cout<<setw(7)<<"Day "<<(i+1);

   cout<<setw(12)<<"Average"<<endl;

   cout<<setfill('=')<<setw(80)<<"=";

    cout<<setfill(' ')<<endl;

    for(int i=0;i<count;i++)

    {

        cout<<n[i]<<setw(8)<<fixed<<"";

         for(intj=0;j<7; j++)

         {

            cout<<setprecision(2)<<fixed<<runData[i][j]<<setw(3)<<"";

         }

        cout<<setw(8)<<average[i];

        cout<<endl;

    }

   cout<<setfill('=')<<setw(80)<<"=";

    cout<<endl;

}
