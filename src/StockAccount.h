#pragma once
#pragma once


#ifndef STOCKACCOUNT_H
#define STOCKACCOUNT_H

#include <vector>
#include"Globales.h"
#include "Account.h"
#include "LinkedList.h"

class StockAccount :public Account
{
public:
	StockAccount();	//constructor

	int PortUpdate(LinkedList &);	//update the portfolio by reading file
	int TranUpdate(LinkedList &);	//update the transaction history by reading file
	void PortOut(LinkedList);	//print out the portfolio
	void TranOut(LinkedList);	//print out the transaction history


	

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	bool StockAccount::BuyShare(LinkedList &Port, LinkedList &Tran, double bal, string sym, int num, double pps)	//buy share
	{
		
		double found = findPrice(sym);
		
		
		if (!found)
		{
			
			pOUTPUT->MessageBox(L"This stock doesn't exit!");
			return 0;
		}

		else
		{
			if (pps<found)
			{
			
				pOUTPUT->MessageBox(L"Your Price Is Low!");
				return 0;
			}

			else
			{
				if (bal<(num*found))
				{
					pOUTPUT->MessageBox(L"You don't have enough money! ");
				
					return 0;
				}

				else
				{
					Tran.addTran(sym, num, found, 1);
					Port.addPort(sym, num, found, 1);
					Port.bubble();
					pOUTPUT->MessageBox(L" Succefully Bought The Share");
					
					return 1;
				}
			}
		}
	}

	bool StockAccount::SellShare(LinkedList &Port, LinkedList &Tran, string sym, int num, double pps)	//sell
	{
		double found = findPrice(sym);
		if (!found)
		{
			
			pOUTPUT->MessageBox(L"This stock doesn't exit!");
			return 0;
		}

		else
		{
			if (Port.getnum(sym)<num)
		
			pOUTPUT->MessageBox(L"You don't have enough stock!");
			
			else
			{
				if (pps>found)
				{
				
					pOUTPUT->MessageBox(L"Your Price Is Too High For The Market");
				
					return 0;
				}

				else
				{
					Port.addPort(sym, num, found, 0);
					Tran.addTran(sym, num, found, 0);
					Port.bubble();
				
					pOUTPUT->MessageBox(L"Succefully Sold The Share");
					return 1;
				}
			}

		}
	}



	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int MatlabUpdate();	//update the vectors used by Matlab by reading file
	void MatlabOut(LinkedList, double);	//print out the vectors to file
	double getport(LinkedList, double);	//get total portfolio in the linkedlist
	int getday();	//get day from system
	int getdy(int);	//get day value from vector
	double getpor(int);	//get portfolio value from vector
	int getsize();	//get size

private:
	vector<int> dy;	//record the days each time the program ends
	vector<double> por;	//record the total portfolios each time the program ends
};

#endif
