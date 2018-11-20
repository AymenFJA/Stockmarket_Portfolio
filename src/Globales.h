#pragma once
#ifndef GLOBALES_H
#define GLOBALES_H


#include"afxwin.h"
#include <string>
#include <windows.h>
#include <strstream>
#include <mmsystem.h>
#include <fstream>
#include"resource.h"


CString static TEMP;
CString static symbb;
CString static numbb;
CString static amtt;


double static pri;



//StockAccount saa;
//TEXT BOX

CListBox static *m_ListBox; //listbox pointer 
CEdit static *pOUTPUT; //OUT PUT WINDOW

CEdit static *pINPUT_SYM;//SYMBOL
CEdit static *pINPUT_NOS;//NUMBER OF SHARES
CEdit static *pINPUT_PPS;//PRICE PER SHAARE
CEdit static *pINPUT_MAX;//MAX AMOUNT OF BUY STOCK
CEdit static *pINPUT_AMT;//ANOUNT OF MONEY FOR DEPOSITE OR WITHDRAWl

//BUTTONS

CButton static * pBUTTON_DSP; //Display Stock price
CButton static * pBUTTON_DCP; //Display Current Portfolio
CButton static * pBUTTON_BUY; //BUY SHARE
CButton static * pBUTTON_SELL; //SELL SHARE
CButton static * pBUTTON_VG; //VIEW GRAPH
CButton static * pBUTTON_VTH;//VIEW TRANS HISTORY
CButton static * pBUTTON_VAB;//VIEW ACCOUNT BALANCE
CButton static * pBUTTON_DEPOSITE;//DEPOSITE
CButton static * pBUTTON_WITHDRAWL;//WITHDARWAL
CButton static * pBUTTON_VAH;//VIEW ACCOUNT HISTORY

#endif // !GLOBALES_H