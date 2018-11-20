#pragma once
#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"afxwin.h"
#include <windows.h>
#include <string>
#include "Node.h"
#include"Globales.h"
#include <iomanip>
#include <time.h>

class LinkedList
{
	//friend class list
	friend class StockAccount;
	friend class BankAccount;

public:
	LinkedList(int);   //constructor
	void addTran(string, int, double, bool); //add an transaction
	void addAcct(bool, double, double&);	//add a bank account transaction
	void addPort(string, int, double, bool);	//add a portfolio transaction
	bool isEmpty() const;   //empty list or not

	void bubble();	//*1-This is Strategy Design  Pattern 
	               //using buuble sort allow to sort the portfolio linkedlist with out copy it to another data structure*/
	void sort_DescendingPPS();//2-This is Strategy DesignPattern sort the list Descending order(Price per share)
	void sort_AscendingNumber();//3-This is Strategy DesignPattern sort the list Descending order(Number of share)
	
	
	string viewtime();	//get the current time
	string viewdate();	//get the current date
	Node* getMyHead()   const;	//get head pointer
	Node* getMyTail()   const;	//get tail pointer

	void portud(string, int, double);	//update the portfolio
	void tranud(bool, string, int, double, string);	//update the transaction history
	void bankud(bool, double, string, double);	//update the bank account history


	int getnum(string);	//get number of stock owned
	void destructor();	//destruct all the nodes
	////////////////////////////////////////////////////////////////////////////////

	void LinkedList::printPort(double bal) const	//print the portfolio
	{
		double total = bal;	//cash balance

		if (isEmpty())	//the list is empty or not
		{
			m_ListBox->AddString(L"The list is empty");
		}

		else
		{
			CString balan;
			double fNum = bal;
			balan.Format(_T("%g"), fNum); //convert from Double to CString

			m_ListBox->AddString("Cash Balance = " + balan + " $");
			

			Node *currentPtr = firstptr;
			stringstream s;



			while (currentPtr != 0)
			{

				CString symb;
				std::string str = currentPtr->Symbol;
				symb.Format(_T("%S"), str.c_str()); //convert THE SYMBOL  from STD::String to CString

				int Numb = currentPtr->Number;
				CString SNumb;
				std::string s = std::to_string(Numb);//convert the Nmber of shares from Integer to string 
				SNumb.Format(_T("%S"), s.c_str()); //convert the Nmber of shares from string to CS string 
				


				CString PPSh;

				double fNum2 = currentPtr->PricePerShare;
				PPSh.Format(_T("%g"), fNum2);//convert Price Per share from Double to CString

				double tootal=1;
				tootal = Numb*fNum2;
				CString toottal;
				double fNum22 = tootal;
				toottal.Format(_T("%g"), fNum22); //convert from Double to CString

				TEMP = "SYMBOL --> " + symb + " " + "     NUMBER OF SHARES :" + SNumb + "     PREICE PER SHARE " + PPSh+"       TotalValue:"+toottal+"  $";
			
				m_ListBox->AddString(TEMP);

				total += currentPtr->PricePerShare*currentPtr->Number;
				currentPtr = currentPtr->next;

			}


			CString totalval;
			
			double fNum3 = total;
			totalval.Format(_T("%g"), fNum3); //convert TOTAL VALUE from Double to CString

			
				TEMP = "Total portfolio value : $" + totalval;
				
				m_ListBox->AddString(TEMP);

		}

	}

	

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void LinkedList::printTran() const	//print the transaction history(Portfolio StockAccount History)
	{
		
		if (isEmpty())
		{

			pOUTPUT->MessageBox(L"The list is empty");

			return;

		}

		
		Node *currentPtr = firstptr;
		
	
		while (currentPtr != 0)
		{
			
			if (currentPtr->Event == 1)
			{



			/*1*/CString symb;
				std::string str = currentPtr->Symbol;
				symb.Format(_T("%S"), str.c_str()); //convert THE SYMBOL  from STD::String to CString




				
			/*2*/int Numb = currentPtr->Number;
				CString SNumb;
				std::string s = std::to_string(Numb);//convert the Nmber of shares from Integer to string 
				SNumb.Format(_T("%S"), s.c_str()); //convert the Nmber of shares from string to CS string 


			/*3*/CString PPSh;
				
				double fNum2 = currentPtr->PricePerShare;
				PPSh.Format(_T("%g"), fNum2);//convert Price Per share from Double to CString
				


				
		   /*4*/double totalV = currentPtr->PricePerShare*currentPtr->Number;
				CString totalval;
				double fNum3 = totalV;
				totalval.Format(_T("%g"), fNum3); //convert TOTAL VALUE from Double to CString


				
		   /*5*/std::string str2;   //time converting from string to char 
				str2 = currentPtr->Time;
				const char * c = str2.c_str();
				CString  tim(c); //rom char to Cstring
				

				
				CString Spac = "   ";
			
				TEMP = "BUY" + Spac + " " + symb + "       " + "    " + SNumb + "       " + "   " + PPSh + "      " + totalval + "              " + tim;
				

				m_ListBox->AddString(TEMP);



			}
			else
			{


				/*1*/CString symb;
				std::string str = currentPtr->Symbol;
				symb.Format(_T("%S"), str.c_str()); //convert THE SYMBOL  from STD::String to CString





				/*2*/int Numb = currentPtr->Number;
				CString SNumb;
				std::string s = std::to_string(Numb);//convert the Nmber of shares from Integer to string 
				SNumb.Format(_T("%S"), s.c_str()); //convert the Nmber of shares from string to CS string 


				/*3*/CString PPSh;

				double fNum2 = currentPtr->PricePerShare;
				PPSh.Format(_T("%g"), fNum2);//convert Price Per share from Double to CString




				/*4*/double totalV = currentPtr->PricePerShare*currentPtr->Number;
				CString totalval;
				double fNum3 = totalV;
				totalval.Format(_T("%g"), fNum3); //convert TOTAL VALUE from Double to CString



				/*5*/std::string str2;
				str2 = currentPtr->Time;
				const char * c = str2.c_str();//time converting from string to char 
				CString  tim(c);// from char to Cstring 



				CString Spac = "   ";

				TEMP = "SEll" + Spac + " " + symb + "       " + "    " + SNumb + "       " + "   " + PPSh + "      " + totalval + "              " + tim;

				m_ListBox->AddString(TEMP);

			}
			currentPtr = currentPtr->next;
		
		}
		
	}
	////////////////////////////////////////////////////////////////////////////////////////////////
	void LinkedList::printAcct() const	//print bank account history
	{
		cout << "\n\n";
		if (isEmpty())
		{
			pOUTPUT->MessageBox(L"The list is empty");

		} // end if

		Node *currentPtr = firstptr;

		

		while (currentPtr != 0)
		{
			if (currentPtr->Event == 1)//withdrawal Event(for Bank Account)
			{
				

				/*1*/CString Amot;
				double fNum1 = currentPtr->Amount;
				Amot.Format(_T("%g"), fNum1);//convert Amount from Double to CString

				/*2*/std::string str2;
				str2 = currentPtr->Date;
				const char * c = str2.c_str();//Date converting from string to char 
				CString  Dat(c);// from char to Cstring 

				/*1*/CString balan;
				double fNum2 = currentPtr->Balance;
				balan.Format(_T("%g"), fNum2);//convert Amount from Double to CString

				CString Spac = " ";
				TEMP = "WITHDRAWL" +Spac+ Amot + " $"  + "    " + Dat + "       " + "           " + balan + " $" ;

				m_ListBox->AddString(TEMP);




			}
			else
			{//deposite Event (for Bank Account)
				/*1*/CString Amot;
				double fNum1 = currentPtr->Amount;
				Amot.Format(_T("%g"), fNum1);//convert Amount from Double to CString

				/*2*/std::string str2;
				str2 = currentPtr->Date;
				const char * c = str2.c_str();//Date converting from string to char 
				CString  Dat(c);// from char to Cstring 

				/*1*/CString balan;
				double fNum2 = currentPtr->Balance;
				balan.Format(_T("%g"), fNum2);//convert Amount from Double to CString

				CString Spac = "   ";
				TEMP = "DEPOSIT   " + Spac + " " + Amot+" $" + "   " + "       " + Dat + "    " + "      " + balan + " $" ;

				m_ListBox->AddString(TEMP);
			}
			currentPtr = currentPtr->next;
		}
		
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
private:
	int size;   //record the size of the list
	Node *firstptr;   //head pointer
	Node *lastptr;   //tail pointer
	Node *getNewNode(string, int, double, bool, double, string, string, double);   //create a new node

};
	#endif