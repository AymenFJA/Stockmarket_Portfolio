
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Account.h"
#include"Globales.h"
#include <time.h> 

Account::Account()	//constructor
{

}

int Account::PriceUpdate()	//(put the values from the file in the vecotr) updatting vectors from stock price file 
{
	string symbol;
	double price;
	string data;
	string str;
	
	ifstream file1;
	
	int  prand = 0;
	srand(time(NULL));
	prand = rand() % 2 + 1;

	//Reading from 2 Files Randomly  Results.txt or Results2.txt
	if (prand <= 1)

	{
		file1.open("Results.txt");
		cout<<(L"Result1 ");
	}
	else

		if(prand==2)
	{

		file1.open("Results2.txt");
	cout<< (L"Result2 ");
	
	}
	

	
		

	//file1.open()

	if (!file1)
	{
		pOUTPUT->MessageBox( L"\n Error in opening Results file "); //check if the file not found or can not open it 
		return 0;
	}

	while (!file1.eof())  //while not the End of the File 
	{
		symbol.clear(); //to clear any previous data inside it to be ready to put new one 
		str.clear();   //to clear any previous data inside it to be ready to put new one 

		int space[2] = { 0 };	//record the space of one line
		int j = 0;	//loop counter

		getline(file1, data); //to read from a line from the *FILE1*

		for (int i = 0; i<data.length(); i++)	//record the position of space in the string
			if (isspace(data[i]))     //    isspace (cctype) Check if character is a white-space move to next (function )  (FROM C PLUS PLUS WEBSITE)

			{
				space[j] = i;
				j++;
			}

		for (int i = 0; i<space[0]; i++)	//read out the symbol   //move no of spaces and read the symbol
			symbol += data[i];

		sym1.push_back(symbol);

		for (int i = space[0] + 1; i<space[1]; i++)	//read out the price  //move no of spaces (move also the symbol chars) and read the price
			str += data[i];


		//change price variable  from string to double
		stringstream s(str);
		s >> price;

		pri1.push_back(price);  //std::vector::push_back()  (ready vector function to add new element to the End of vector)
	}
	file1.close();

	return 0;
}

double Account::findPrice(string str)	//find the price by symbol
{
	int i;
	double price = 0;
	int si = sym1.size();

	for (i = 0; i<si; i++) //the loop will move till i less than the symbol size (vector) size
		if (sym1[i] == str) //if the symbol==string 
		{
			price = pri1[i];  //save the price value of that string in the vector
			return price;
		}


	if (i >= si)	//not found
		return 0;
}
