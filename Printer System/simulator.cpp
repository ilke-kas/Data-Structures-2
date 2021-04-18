#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "simulator.h"
/*
* Title: Simulator.cpp
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: implementation file of Simulator class
*/
/*
*DEFAULT CONSTRUCTOR
*/
Simulator::Simulator(): averTime(0), printerNum(0), requestNum(0), time(0),requestList(NULL), printerList(NULL){
}
/*
* COPY CONSTRUCTOR
*/
Simulator::Simulator(const Simulator& simulator)
		:averTime(simulator.averTime), printerNum(simulator.printerNum), requestNum(simulator.requestNum), time(simulator.time),pq(simulator.pq)
{
	if(requestNum > 0)
	{
		requestList = new PrintRequest[requestNum];
		for(int i = 0 ; i < requestNum; i ++)
		{
			requestList[i] = simulator.requestList[i];
		}
	}
	else
	{
		requestList = NULL;
	}
	if(printerNum > 0)
	{
		printerList = new Printer[printerNum];
		for(int i = 0 ; i < printerNum; i ++)
		{
			printerList[i] = simulator.printerList[i];
		}
	}
	else
	{
		printerList = NULL;
	}
	
}
/*
*CONSTRUCTOR that both simulate and prints the result of the simulation 
*@param logFileName as the name of the log file given 
*@param printNum as the printer number that is wanted to simulation simulate with
*@param print to print the texts
*/
Simulator::Simulator(string logFileName, int printNum ,bool print)
{
	//first read logs from the file 
	ifstream logFile;
	logFile.open(logFileName.c_str(),ios_base::in);
	//read the first line which includes the rquest numbers 
	string requestNumStr;
	getline(logFile,requestNumStr,'\n');
	stringstream ss1;
	ss1<<requestNumStr;
	ss1>>requestNum;
	//create requestList
	requestList = new PrintRequest[requestNum];
	for(int i = 0; i <requestNum;i++)
	{
		string line;
		//read the line from the file
		getline(logFile,line,'\n');
		requestList[i] = PrintRequest(line);
	}
	//create printer list
	printerNum = printNum;
	printerList = new Printer[printerNum];
	for(int i = 0; i <printerNum;i++)
	{
		printerList[i].setId(i); //set their Ids
	}
	//get the max process time
	int maxTime = getMaxProcessTime();
	time = 0;
	//start simulation
	for(; time < maxTime; time++)
	{
		//update all of the printers' availability
		for(int i = 0; i <printerNum; i++)
		{
			printerList[i].setTime(time);
			printerList[i].updateAvailability();
		}
	   // add requests to the priorityqueue whose time is matched with current time
	   for(int i = 0; i < requestNum; i ++)
	   {
	   	 if(requestList[i].getRequestTime() == time)
	   	 {
	   	 	pq.pqInsert(requestList[i]);
		 }
	   }
	   //then assign these requests to the available printers
	 	int index = -1;
	 	PrintRequest tempRequest;
	 	while(!pq.isEmpty() && isThereAvailablePrinter(index)) 
	 	{
	 		pq.pqDelete(tempRequest); //delete assigned requests from the priority queue
	 		tempRequest.setStartTime(time); //set their start time for calculating waiting time later
	 		tempRequest.setSent(true); //make their status sent
	 		printerList[index].addRequest(tempRequest); //add the request to the printer's requests list
	 		if(print) // print results if wanted
	 			cout<<" Printer "<<index<<" prints print request "<<tempRequest.getId()<<" at minute "<<time<<"(wait: "<<tempRequest.getWaitingTime()<<" )"<<endl;
		}
	}
	//calculate average waiting time
	int total = 0;
	//traverse printers
	for(int i = 0; i < printerNum; i++)
	{
		total = total + printerList[i].getTotalWaitingTime();
	}
	if(requestNum != 0 ) //avoid division by zero
		averTime = static_cast<double>(total) / requestNum;	//avoid integer division by casting
	else
		averTime = 0;
	if(print)
		cout<<"Average waiting time: "<<averTime<<" minutes"<<endl;
	logFile.close();//close the file 
}
/*
*DESTRUCTOR
*/
Simulator::~Simulator(){
	if(requestList)
		delete[] requestList;
	if(printerList)
		delete[] printerList;
}

//set functions
void Simulator::setAverTime(double aver){
	averTime = aver;
}
void Simulator::setPrinterNum(int num){
	printerNum = num;
}
void Simulator::setRequestList(PrintRequest* list){
	requestList = list;
}
void Simulator::setPrinterList(Printer* list){
	printerList = list;
}
void Simulator::setRequestNum(int num){
	requestNum = num;
}
void Simulator::setTime(int t){
	time = t;
}
//get functions
double Simulator::getAverTime() const{
	return averTime;
}
int Simulator::getPrinterNum() const{
	return printerNum;
}
int Simulator::getRequestNum() const{
	return requestNum;
}
Printer* Simulator::getPrinterList() const{
	return printerList;
}
PrintRequest* Simulator::getRequestList()const{
	return requestList;
}
int Simulator::getTime() const{
	return time;
}
//other functions
/*
* Functions that will find the total process time for request for worst case simulation
*@return int
*/
int Simulator::getMaxProcessTime()
{
	int total = 0;
	//traverse request file
	for(int i = 0; i <requestNum; i++)
	{
		total = total + requestList[i].getProcessTime();//sum all of the process times
	}
	return total;
}
/*
*Function that find is there any available printer to print new request
*@return bool
*@param index as the index of the available printer
*/
bool Simulator::isThereAvailablePrinter(int& index)
{
	for(int i = 0; i < printerNum; i++) //traverse the printer list
	{
		printerList[i].updateAvailability();//update the availability of all printers
		if(printerList[i].getAvailability()) //if there is an aavialble printer, get the index and return true
		{
			index = i;
			return true;
		}
	}
	index = -1;//else make index -1 and return false
	return false;
}

