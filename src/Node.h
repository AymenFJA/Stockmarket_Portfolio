#pragma once
#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node
{
	//friend class list
	friend class LinkedList;
	friend class StockAccount;
	friend class BankAccount;

public:  //Symbol,Number,PPS,Event ,Amount,  Time,   Date,  Balance)
	Node(string, int, double, bool, double, string, string, double);   //constructor


																	   //get functions																   
	string getSym() const;    //get the symbol
	int getNum() const;      //get the Number of Stocks
	double getPPS() const;  //get the Price for each share
	double getBal() const; //get the balance 

						   //set functions
	void setSym(string);  //set the symbol
	void setNum(int);    //set Number of Stocks
	void setPPS(double);//set the Price Per Shares


private:
	string Symbol;	//company symbol
	int Number;    //number of stocks
	double PricePerShare;	//price per share
	bool Event;	//(for stock account its buy and sell) ; for(BankAccount its withdrawal or deposit)
	double Amount;	//the amount user withdraw from bank or deposit to bank
	string Time;	//time
	string Date;	//date
	double Balance;	//current cash balance
	Node *next;	//next
	Node *prev; //previous /*****************************************************************************/
};

#endif
