# Stockmarket_Portfolio
Account Management System for Finance Programming

# classes

1. Account (Parent Class)

2. Bank Account (Child Class)

3. Stock Account (Child Class)

4. Linked List (Doubly Linked List) (Utility Class)

5. Node (Utility Class)

# Data Files

1.  BankHist.txt (store all the buy and sell operations)

2.	TranHist.txt (store all the deposit or withdrawal operations)

3.	Portfolio.txt (store all the stocks the user that the user bought)

4.	Results.txt (store the different kinds of stocks and its prices)

5.	Results2.txt (store the different kinds of stocks and its prices)

6.	Matlab.txt (store the x points and the y points for matlab graph)

7.	INTERFACE!.rc (this is a resource file contain the dialog file for the MFC GUI)

# Header Files 
1. Account.h 
2. Bank Account.h
3. Stock  Account.h
4. Linked List.h
5. Node.h
6. Globales.h
7. Functions.h
8. Resource.h

# CPP Files 
1. Account.cpp 
2. Bank Account.cpp
3. Stock Account.cpp
4. Linked List.cpp
5. Node.cpp
6. Globales.cpp
7. MAIN.cpp

## Account Header And Account CPP file contain the following functions:

**PriceUpdate**
This function will update and read the price of stocks from 2 text files the Results.txt and the Results2.txt(Randomly).

**Findprice** 
This function will find the price of the stock files that the user will search for it by searching the Results.

## BankAccount Header And BankAccount CPP file contain the following functions:

**BankUpdate** 
This function will update ( read and write from the file BankHist.txt) the Bankaccount History  and write withdrawal or deposit.

**BankOutput** 
This function will write any transactions that the user will do on the file BankHist.txt .

**Buyshare**
This function will buy a share or number of shares .

**Sellshare**
This function will sell a share or number of shares.

**Depo_With**
This function will make and deposit or withdrawal from or to the Bankaccount.

**Getbalance**
This function will initiate the first default amount of Money for BankAccount which is 10000$ or it will update it self every transaction that the user will do.

# GUI DESIGN: 

## For the Graphical User Interface, we used MFC libraries.

### The GUI contain the following
1.	“Eleven Button” and Each button complete specific operation.
2.	“Four Textboxes” which allow the user to enter the Symbol and price per share and number of share and the amount of withdraw or deposit.
3.	“Three Radio Buttons” for the Strategy Design Pattern (Three Sorting Methods to keep the List in order and also let the user to choose or change the method of sort) 
4.	“List box” will show all the results that the user will make.
5.	“Message Box” will show if the user make mistake or complete the operation.

### License

    Copyright 2016 Aymen Alsaadi

    The MIT License

``` Copyright (c) 2010-2018 Google, Inc.
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. 
```
