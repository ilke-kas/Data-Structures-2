#include "PrintRequest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
/*
* Title: PrintRequest.cpp
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: Implementation of the printrequest class
*/
//Default constructor
PrintRequest::PrintRequest():
	id(0), priority(0), requestTime(0),processTime(0),startTime(0),printed(false),sent(false){
	}
//Constructor
PrintRequest::PrintRequest(string line)
{
	stringstream lineS(line);
	string idStr;
	string priorityStr;
	string processTimeStr;
	string requestTimeStr;	
	//read id 
	getline(lineS,idStr,' ');
	getline(lineS,priorityStr,' ');
	getline(lineS,requestTimeStr, ' ');
	getline(lineS,processTimeStr,'\n');
	//converts string to integers
	stringstream ss1;
	stringstream ss2;
	stringstream ss3;
	stringstream ss4;
	ss1<<idStr;
	ss1>>id;
	ss2<<priorityStr;
	ss2>>priority;
	ss3<<processTimeStr;
	ss3>>processTime;
	ss4<<requestTimeStr;
	ss4>>requestTime;
	//set other attributes
	setPrinted(false);
	setSent(false);
	setStartTime(0);
}
//Set Functions
void PrintRequest::setId(int Id)
{
	id = Id;
}
void PrintRequest::setPriority(int Priority)
{
	priority = Priority;
}
void PrintRequest::setProcessTime(int ProcessTime)
{
	processTime = ProcessTime;
}
void PrintRequest::setRequestTime(int RequestTime)
{
	requestTime = RequestTime;
}
void PrintRequest::setSent(bool Sent)
{
	sent = Sent;
}
void PrintRequest::setPrinted(bool Printed)
{
	printed = Printed;
}
void PrintRequest::setStartTime(int time)
{
	startTime = time;
}
//Get Functions
int PrintRequest::getId() const{
	return id;
}
int PrintRequest::getPriority() const{
	return priority;
}
int PrintRequest::getProcessTime() const{
	return processTime;
}
int PrintRequest::getWaitingTime() const{
	return startTime-requestTime;
}
int PrintRequest::getRequestTime() const{
	return requestTime;
}
bool PrintRequest::getPrinted() const{
	return printed;
}
bool PrintRequest::getSent() const{
	return sent;
}
int PrintRequest::getStartTime() const{
	return startTime;
}

