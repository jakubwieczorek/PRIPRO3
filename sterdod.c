#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow
extern size_t issam;//ile samochodow
extern size_t isnap;//ile napraw

void menu1()
{//gdy 1 to katalogi gdy 2 to samochod, gdy 3 to naprawe	
	
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("& 1) katalog \"1\".\n");	
	if(ilekatsam)//gdy jest katalog samochodow to mozna dodac samochod
	{
		printf("& 2) samochod \"2\"\n"); 
	}
	if(ilekatnap>0 || issam>0)
	{
		printf("& 3) naprawe \"3\"\n");
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

void menunap()//gdy 1 do samochodu gdy 2 do katalogu
{	
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	if(issam>0 && isnap>0) 
	{
		printf("& 1) do samochodu \"1\".\n");
	}
	if(ilekatnap) 
	{
		printf("& 2) do katalogu \"2\"\n");		
	}	
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
}

bool nap()//gdy pobralo to true gdy nie to false
{
	int wybor;
	menunap();
	check_int(&wybor, "Co teraz ?:=>", 2, 0, 3);
	if(wybor==1)
	{		
		if(dodnapdosam(0, stdin, 0, 0, 0)) fprintf(stderr, "error: segmentation fault");
		return true;
	}
	if(wybor==2) 
	{
		if(dodnap(0, stdin)) fprintf(stderr, "error: segmentation fault");
		return true;
	}
	return false;
}

void sterdod()
{
    int wybor; // tablica przechowujaca rozkazy uzytkownika

    while(1)
    {
	menu1();
        check_int(&wybor, "Co teraz ?:=>", 2, -1, 4);
	
        if(wybor==1)//katalog
        {	
	    menucat();
            check_int(&wybor, "Co teraz ?:=>", 2, 0, 3);
	    if(wybor==1) //samochod do katalogu
	    {
		if(dodkatnap(stdin))fprintf(stderr, "error: segmentation fault");
	    }
	    else 	//naprawe do katalogu    
	    {
		if(dodkatsam(stdin)) fprintf(stderr, "error: segmentation fault"); 
            }
	}else
        if(wybor==2)//samochod
        {
		if(ilekatsam==0)continue;
            	if(dodsam(0, stdin))fprintf(stderr, "error: segmentation fault");
	    	else issam++;
        }else
        if(wybor==3)//naprawe
        {
	    if(ilekatnap==0 && issam==0) continue;
	    nap();
        }else break;
    }
}
