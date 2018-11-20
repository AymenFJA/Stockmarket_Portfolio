#pragma once
#pragma once

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <vector>

#include "Account.h"
#include "LinkedList.h"

class BankAccount :public Account
{
public:
	BankAccount();	//constructor

	int BankUpdate(LinkedList &);	//update bank account information by reading from file
	void BankOutput(LinkedList);	//update file by bank account information
	void BuyShare(LinkedList&, double&, string, int);	//buy
	void SellShare(LinkedList&, double&, string, int);	//sell
	void Depo_With(LinkedList&, double&, double, bool);	//deposit or withdraw
	double getbalance(LinkedList);	//get balance

private:

};

#endif
