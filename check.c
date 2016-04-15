#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stdmoj.h"
#include <stdarg.h>

katnapraw *katalognap;//katalogi napraw
katsam *katsamochodow;//katalogi samochodow

size_t ilekatnap;//zlicze katalogi napraw
size_t ilekatsam;//zlicza katalogi samochodow

void check_int(int *to_check, const char *str, int n, ...)//n ilosc dodatkowych argumentow, pierwszy dod min drugi max.
{
        va_list ap;//tworzy zmienna ap typu va_list 
        va_start(ap, n);//udostępnia parametry znajdujące się po parametrze n

        int min, max; //zmienne potrzebne do tego, że va_arg po każdym wywołaniu przesówa wskaźnik o jeden więc w przypadku pomyłki jest 
        //problem

        min=va_arg(ap, int);
        if(--n) max=va_arg(ap, int);// gdy chcemy ograniczyc z gory

        while(true)
        {
                printf("%s", str);//wyswietla wiadomosc z parametru

                if(fscanf(stdin, "%d", to_check)!=1)//jesli blad wprowadzenia
                        while(fgetc(stdin)!='\n');//czyszczenie bufora

                if(*to_check<=min)
                {continue;}//gdy jest mniejsze od minimum

                if(n)
                if(*to_check>=max)
                {continue;}//gdy jest wieksze od max

                break;
        }
        va_end(ap);
        while(fgetc(stdin)!='\n');//czyszczenie bufora
}

void check_str(const char* msg, char *str, int amount)
{
		
	printf("%s", msg);
	if(amount==15)
	while(fscanf(stdin, "%14s", str)!=1)
		{
			while(fgetc(stdin)!='\n');
			printf("%s", msg);
		}
	else if(amount==10)
	while(fscanf(stdin, "%9s", str)!=1)
		{
			while(fgetc(stdin)!='\n');
			printf("%s", msg);
		}

		while(fgetc(stdin)!='\n');	
}



