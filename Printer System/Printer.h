#ifndef _PRINTER_H
#define _PRINTER_H
#include "PriorityQueue.h"
#include <iostream>
using namespace std;
/*
* Title: Printer.h
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: Header file of the printer class
*/
class Printer{
	private:
		int time;
		int id;
		PrintRequest* requests;
		int requestNum;
		bool available;
		
	public:
		Printer();
		Printer(int id);
		Printer(const Printer& printer);
		~Printer();
		
		PrintRequest* getRequests() const;
		void setRequests(PrintRequest* request);
		
		int getId() const;
		void setId(int Id);
		
		bool getAvailability() const;
		void setAvailability(bool available);
		
		int getTime() const;
		void setTime(int t);
		
		int getRequestNum() const;
		void setRequestNum(int num);
		
		void updateAvailability();
		int getTotalWaitingTime();
		void addRequest(const PrintRequest& newRequest);
};
#endif
