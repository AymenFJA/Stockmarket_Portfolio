#pragma once
#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h" 
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "engine.h"
#include <windows.h>
#include <ctime>
//-----------------------------------------------------------------------------------------
#include <afxwin.h>      //MFC core and standard components
#include"Globales.h"
#include "resource.h"    //main symbols
#include"LinkedList.h"
#include"StockAccount.h"
#include"Account.h"
#include"BankAccount.h"
#include"Node.h"

#pragma comment(lib,"libmx.lib")  
#pragma comment(lib,"libmex.lib")
#pragma comment(lib,"libeng.lib")

void disp_pri(StockAccount sa)	//display the price of one stock
{
	
	//update price information in each account
	

	pINPUT_SYM->GetWindowText(TEMP);
	std::string sym(CW2A(TEMP.GetString(), CP_UTF8)); //convert from CString to STD::STRING

	pri = sa.findPrice(sym);
	if (pri == 0)
	{
		
		m_ListBox->AddString(L"\n\nThe symbol you are looking for isn't in the list!");
		
	}
	else
	{
		CString symb;
		std::string str = sym;
		symb.Format(_T("%S"), str.c_str()); //convert from STD::String to CString

	
		CString Pric;
		double fNum = pri;
		Pric.Format(_T("%g"), fNum); //convert from Double to CString

		TEMP = "Symbol: "+ symb+"   \r\n" +"Price: "+Pric;
		
		m_ListBox->AddString(TEMP);
		

	}
}



void disp_por(LinkedList Port, double bal)	//display portfolio list
{
	
	
	Port.printPort(bal);
	
	
}


void tran_hist(LinkedList Tran) 	//view transaction history
{
	
	Tran.printTran();
}


void prt_hist(LinkedList Bank)	//print bank account information
{
	
	Bank.printAcct();
}


void buy(double &bal, LinkedList &Port, LinkedList &Tran, LinkedList &Bank, StockAccount &sa, BankAccount &ba)	//buy share
{
	
	int num;
	double pps;

	
	pINPUT_SYM->GetWindowText(symbb);//get user entery from the text box symbol 
	
	pINPUT_NOS->GetWindowText(numbb);//get user entery from the text box number of hsares
	
	pINPUT_PPS->GetWindowText(amtt);//get user entery from the text box Pricepershare

	std::string sym(CW2A(symbb.GetString(), CP_UTF8));

	num = _ttoi(numbb); //convert Number of shares from CString to integer
	pps = _tstof(amtt);

	int status = sa.BuyShare(Port, Tran, bal, sym, num, pps);
	if (status == 1)
		ba.BuyShare(Bank, bal, sym, num);

	else
	m_ListBox->AddString(L"\n\nUnsuccessful purchase!");
	Tran.printTran();
	Bank.printAcct();


}


void sell(double &bal, LinkedList &Port, LinkedList &Tran, LinkedList &Bank, StockAccount &sa, BankAccount &ba)	//sell share
{
	
	
	int num;
	double pps;

	
	pINPUT_SYM->GetWindowText(symbb); //get user entery from the text box symbol
	
	pINPUT_NOS->GetWindowText(numbb);//get user entery from the text box  number of hsares
	
	pINPUT_PPS->GetWindowText(amtt);//get user entery from the text box Pricepershare

	std::string sym(CW2A(symbb.GetString(), CP_UTF8)); //convert SYMBOL from CString to STD::STRING
	num = _ttoi(numbb); //convert Number of shares from CString to integer
	pps = _tstof(amtt);
	


	int status = sa.SellShare(Port, Tran, sym, num, pps);
	if (status == 1)
	{
		ba.SellShare(Bank, bal, sym, num);

		Tran.printTran();
		Bank.printAcct();
	}
	else
	m_ListBox->AddString(L"\n\nUnsuccessful Sell!");
	Tran.printTran();
	Bank.printAcct();

}


void depo(LinkedList &Bank, BankAccount &ba, double &bal)	//deposit
{
	
	double amt;
	

	pINPUT_AMT->GetWindowText(TEMP);
	amt= _tstof(TEMP);
	ba.Depo_With(Bank, bal, amt, 0);
	Bank.printAcct();



	

}


void withdraw(LinkedList &Bank, BankAccount &ba, double &bal)	//withdraw
{
	
	double amt;
	
	pINPUT_AMT->GetWindowText(TEMP);
	amt = _tstof(TEMP);
	ba.Depo_With(Bank, bal, amt, 1);
	
	Bank.printAcct();

	
}




int matlab(StockAccount sa)	//matlab operation
{
	//value from C++ program
	double portfolio[100] = { 0 };
	int day[100] = { 0 };

	//interface value
	int day_matlab[100];
	double por_matlab[100];

	for (int i = 0; i<sa.getsize(); i++)
	{
		portfolio[i] = sa.getpor(i);
		day[i] = sa.getdy(i);
	}

	int k = 0;
	for (int i = 0, j = 1; i<sa.getsize(); i++, j++)
	{
		if (day[j] != day[i])
		{
			day_matlab[k] = day[i];
			por_matlab[k] = portfolio[i];
			k++;
		}
	}

	//start the Matlab engine
	Engine *ep;
	int status = 0;	//engine status

	if (!(ep = engOpen(NULL)))
	{
		pOUTPUT->MessageBox(L"Unsuccessful opening engine!");
		return -1;
	}

	//Writing x to Matlab
	mxArray *T1;
	T1 = mxCreateDoubleMatrix(k, 1, mxREAL);
	memcpy((void *)mxGetPr(T1), (void *)por_matlab, sizeof(double)*k);
	engPutVariable(ep, "por_matlab", T1);



	//Writing y to Matlab
	mxArray *T2;
	T2 = mxCreateNumericMatrix(k, 1, mxINT32_CLASS, mxREAL);
	memcpy((void *)mxGetPr(T2), (void *)day_matlab, sizeof(int)*k);
	engPutVariable(ep, "day_matlab", T2);



	//plot the two group of dots
	status = engEvalString(ep, "plot(day_matlab,por_matlab);");
	status = engEvalString(ep, "xlabel('Date, day');");
	status = engEvalString(ep, "ylabel('Portfolio, dollar');");
	status = engEvalString(ep, "grid on;");
	if (status != 0)
	pOUTPUT->MessageBox(L"There is a failure in Matlab engine while plotting!");

	return 0;


}