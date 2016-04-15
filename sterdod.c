#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow

bool iskatsam;
bool iskatnap;
bool issam;

void menu1()
{//gdy 1 to katalogi gdy 2 to samochod, gdy 3 to naprawe	
	
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("& 1) katalog \"1\".\n");	
	if(iskatsam)//gdy jest katalog samochodow to mozna dodac samochod
	{
		printf("& 2) samochod \"2\"\n"); 
	}
	if(iskatnap==1 || issam==1)
	{
		if(iskatsam==0)//gdy nie ma katalogow samochodow to wyswiatlamy naprawe jako druga a jesli nie to trzecia 
		printf("& 2) naprawe \"2\"\n");
		else printf("& 3) naprawe \"3\"\n");
	}
	printf("& 0) wyjsc \"0\"\n");
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");

}

void menucat()
{
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("& 1) napraw \"1\".\n");	
	printf("& 2) samochodow\"2\"\n");		
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");

}

void menunap()
{	
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	if(issam) 
	{
		printf("& 1) do samochodu \"1\".\n");
	}
	if(iskatnap) 
	{
		if(issam) printf("& 2) do katalogu \"2\"\n");		
		else printf("& 1) do katalogu \"1\"\n");
	}	
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
}

void nap()
{
	int wybor;
	menunap();
	check_int(&wybor, "Co teraz ?:=>", 2, 0, iskatnap+issam+1);
	if(wybor==1 && issam==1)
	{	
		if(dodnapdosam()) fprintf(stderr, "error: segmentation fault");
	}
	else 
	{
		if(dodnap()) fprintf(stderr, "error: segmentation fault");
	}
}

void sterdod()
{
    int wybor; // tablica przechowujaca rozkazy uzytkownika

    while(1)
    {
	menu1();
        check_int(&wybor, "Co teraz ?:=>", 2, -1, iskatsam+issam+iskatnap+2);
	
        if(wybor==1)
        {	
	    menucat();
            check_int(&wybor, "Co teraz ?:=>", 2, 0, 3);
	    if(wybor==1) 
	    {
		if(dodkatnap())fprintf(stderr, "error: segmentation fault");
		else iskatnap=1;
	    }
	    else 	    
	    {
		if(dodkatsam()) fprintf(stderr, "error: segmentation fault"); 
		else iskatsam=1;
            }
	}else
        if(wybor==2)
        {
	    if(iskatsam==1)
	    {
            	if(dodsam())fprintf(stderr, "error: segmentation fault");
	    	else issam=1;
	    }
            else 
	    {
		nap();
	    }	
        }else
        if(wybor==3)
        {
	    if(iskatnap==0 && issam==0) continue;
	    nap();
        }else break;
    }
}
