#include <iostream>
#include "Printer.h"
using namespace std;
/*
* Title: Print request implementation
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: description of your code
*/
/*
*DEFAULT CONSTRUCTOR
*/
Printer::Printer() : time(0),id(-1), requests(NULL),requestNum(0),available(true){
}
/*
*DESTRUCTOR
*/
Printer::~Printer(){
	if(requests)
		delete[] requests;
}
/*
*CONSTRUCTOR with id number
*@param id as the id number of the printer
*/
Printer::Printer(int Id) : time(0), id(Id), requests(NULL),requestNum(0),available(true){
}
/*
*COPY CONSTRUCTOR for the printer
*@param printer as the copied printer object
*/
Printer::Printer(const Printer& printer)
		:  time(printer.time),id(printer.id), requestNum(printer.requestNum),available(printer.available)
{
	if(requestNum >0)
	{
		requests = new PrintRequest[requestNum];
		for(int i = 0; i < requestNum; i++)
		{
			requests[i] = printer.requests[i];
		}
	}
	else
		requests = NULL;
}
/*
*Get function for id of the printer
*@return id of the printer
*/
int Printer::getId() const{
	return id;
}
/*
*Set Function fot the id of the printer
*@param Id as the id of the printer
*/
void Printer::setId(int Id){
	id = Id;
}
/*
*Get function for the requests of this printer
*@return PrintRequest* that points the dynamic array of the printer's requests
*/
PrintRequest* Printer::getRequests() const{
	return requests;
}
/*
*Get Function for the number of the elements in requests array
*@return requestNum as int
*/
int Printer::getRequestNum() const{
	return requestNum;
}
/*
* Set function for the requests array of the printer
*@param req as the requests arraythat is wanted to be set
*/
void Printer::setRequests(PrintRequest* req)
{
	requests = req;
}
/*
*Set function for the request number of the printer
*@param num as the request number 
*/
void Printer::setRequestNum(int num)
{
	requestNum = num;
}
/*
*Set function for the availability of the printer
*@param ava as the availability of the printer
*/
void Printer::setAvailability(bool ava)
{
	available = ava;
}
/*
*Get function for the availability of the printer
*@return available as bool 
*/
bool Printer::getAvailability() const{
	return available;
}
/*
*Get Function for the current time of the printer(for simulation)
*@param time 
*/
int Printer::getTime() const{
	return time;
}
/*
*Set function for the current time of the printer(for simulation)
*@param t as the time
*/
void Printer::setTime(int t){
	time = t;
}
/*
*Function that updates the availability of the printer according to the time of the simulator 
*/
void Printer::updateAvailability(){
	if(requestNum != 0)//if there is request that make printer work
	{
		//if the time of the simulator equals to the time that printer's last works starttime+ process time(if the last work is done)
		if(requests[requestNum-1].getStartTime() + requests[requestNum-1].getProcessTime() == time ) 
		{
			requests[requestNum - 1].setPrinted(true); //make request printed
			available = true; //make printer available
		}
		else
			available = false; //else make printer notavailable
	}
}
/*
*Function that add request to the printer's requests list
* @param newRequest as the wanted request to add the list
*/
void Printer::addRequest(const PrintRequest& newRequest)
{
	if(requestNum == 0) //if there is no request previously
	{
		requests = new PrintRequest[1]; //create requests array as dynamic with 1 element
		requests[0] = newRequest; // add new request to the array
		requestNum++; //increase the request number
	}
	else
	{
		PrintRequest* temp = new PrintRequest[requestNum +1]; // else create temp array with size + 1
		//copy the old array
		for(int i = 0; i <requestNum;i++)
		{
			temp[i] = requests[i];
		}
		temp[requestNum] = newRequest; //add request to the array
		delete[] requests; //delete old array for memleak
		requests = temp;
		requestNum++; //increase the list size by 1
	}
}
/*
*This function will get the total waiting time of the requests in this printer's requests list
*@return total as the int to find total waiting time of requests
*/
int Printer::getTotalWaitingTime()
{
	int total = 0;
	for(int i = 0; i<requestNum; i++)//traverse requests array
	{
		total = total + requests[i].getWaitingTime(); //summation of all requests waiting time 
	}
	return total;
}

