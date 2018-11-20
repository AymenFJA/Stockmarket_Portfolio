#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include <string>

using namespace std;

class Account
{
	//friend list
	friend class StockAccount;
	friend class BankAccount;

public:
	Account();	//constructor
	int PriceUpdate();	//stock price update
	double findPrice(string);	//find the price of a stock

private:
	vector<string> sym1;	//save the symbol from the stock price file.txt
	vector<double> pri1;	//save the price from the stock price file.txt
};
#endif
