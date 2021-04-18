#ifndef _SIMULATOR_H
#define _SIMULATOR_H
#include <iostream>
#include "Printer.h"
#include "PrintRequest.h"
using namespace std;
/*
* Title: Simulator.h
* Author: Ilke Kas
* ID: 21803184
* Section: 3
* Assignment: 3
* Description: Header file of Simulator class
*/
class Simulator{
	private:
	    double averTime;
	    int printerNum;
		int requestNum;
		int time;
		PriorityQueue pq;
		PrintRequest* requestList;
		Printer* printerList;
	public:
		Simulator(); //Default constructor
		Simulator(string logFileName,  int printerNum ,bool print ); //Constructor that both simulate and print the resultsthe file by given printer number
		Simulator(const Simulator& simulator); //Copy construtor since include dynamic structures
		~Simulator();//Destructors
		
		int getTime() const;
		void setTime(int time);
		
		int getRequestNum() const;
		void setRequestNum(int num);
		
		int getPrinterNum() const;
		void setPrinterNum(int num);
		
		Printer* getPrinterList() const;
		void setPrinterList(Printer* list);
		
		PrintRequest* getRequestList() const;
		void setRequestList(PrintRequest* list);
		
		void setAverTime(double aver);
		double getAverTime() const;
		//other functions
		int getMaxProcessTime();
		bool isThereAvailablePrinter(int& index);
};
#endif
