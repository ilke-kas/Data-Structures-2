#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "simulator.h"

using namespace std;
/*
* Title: Heaps
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: description of your code
*/
int main(int argc,char *argv[])
{
	//read request file
	int requestNum = 0;
	string logFileName = argv[1];
	ifstream logFile;
	logFile.open(logFileName.c_str(),ios_base::in);
	string requestNumStr;
	getline(logFile,requestNumStr,'\n'); //read the first line that shows the number of request
	stringstream ss1; //To convert read value to integer
	ss1<<requestNumStr;
	ss1>>requestNum;
	//read averTime
	 double maxWaitingTime = strtod(argv[2],NULL); //read maxWaitingTime from the command line
	
	int minNumOfPrinter = 0; //wanted min number of value, start it with 0
	for(int i = 1; i < requestNum; i++) //by staring with 1 , try simulations with i printers but do not print the results
	{
		Simulator s(logFileName,i,false);
		if(s.getAverTime()<maxWaitingTime) // is the averageTime of simulation is less thamn maxaverage time than this is the wanted value
		{
			minNumOfPrinter = i;
			break; //break the loop, no need to serach anymore, we want min number of printer
		}
	}
	
	cout<<"Minimum number of printers required: "<<minNumOfPrinter<<endl;
	cout<<endl;
	cout<<"Simulation with "<< minNumOfPrinter<<" printers: \n"<<endl;
	Simulator s(logFileName, minNumOfPrinter,true); //print the result 
	
	return 0;

}
