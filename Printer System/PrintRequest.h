#ifndef _PRINTREQUEST_H
#define _PRINTREQUEST_H
#include <iostream>
using namespace std;
/*
* Title: PrintRequest.h
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: Header file of the print request class
*/
class PrintRequest
{
	private:
		int id;
		int priority;
		int requestTime;
		int processTime;
		int startTime;
		bool printed;
		bool sent;
	public:
		//constructor & destructor
		PrintRequest();
		PrintRequest(string line);
		//setFunctions
		void setId(int id);
		void setPriority(int priority);
		void setRequestTime(int requestTime);
		void setProcessTime(int procesTime);
		void setPrinted(bool printed);
		void setSent(bool sent);
		void setStartTime(int time);
		//get Functions
		int getId() const;
		int getPriority() const;
		int getRequestTime() const;
		int getProcessTime() const;
		bool getPrinted() const;
		bool getSent() const;
		int getWaitingTime() const;
		int getStartTime() const;
};
#endif
