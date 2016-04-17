#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw

extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw

extern size_t ilekatsam;//zlicza katalogi samochodow

int ztxt()
{
	char charakter;
	FILE *wskplik;
	
	if((wskplik=fopen("baza.txt", 'r')))
	{
		perror("error: ");
		return 1;
	}
	while(1)
	{
		charakter=fgetc(wskplik);
		if(charakter=='*')
		{
			if((katsamochodow=realloc(katsamochodow, sizeof(*katsamochodow)*(ilekatsam+1L)))==NULL)
   			{
        			perror("error:");
        			return true;
    			}

    			modyfikowaniekatsam(ilekatsam, wskplik);

    			katsamochodow[ilekatsam].numer=ilekatsam+1L;

    			katsamochodow[ilekatsam].pocz=NULL;
 	   		katsamochodow[ilekatsam].ost=NULL;

    			ilekatsam+=1L;//zwiekszamy liczbe katalogow samochodow
		}else
		if(character=='+')
		{
			dodsam(ilekatsam, wskplik);//gdzie dodac, z czego czy z pliku czy ze strumienia stdin
			issam++;
		}
	}
	if(fclose(wskplik))
	{
		perror("error:");
		return 2;
	}
	
	return 0;
}
