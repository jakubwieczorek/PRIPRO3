#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow

void modyfikowaniesamwkat(samochod *ktorysam, unsigned long ktorykat, FILE *wskplik)
{

    if(wskplik==stdin)
    {
	check_str("Marka: ", ktorysam->marka, 10);

        check_str("Model: ", ktorysam->model, 10);
        
	check_int((int*)&ktorysam->rok, "Rok(1700,2100): ", 2, 1699, 2101);
        
	check_int((int*)&ktorysam->przebieg, "Przebieg(1,10e8): ", 2, 0, 10e8);
    }else
    {

    }
}

void modyfikowaniekatsam(unsigned long ktorykat, FILE *wskplik)
{
    if(wskplik==stdin)
    {
	    check_str("nazwa: ", katsamochodow[ktorykat].nazwa, 15);
    }
}

void modyfikowaniekatnap(unsigned long ktorykat, FILE *wskplik)
{
    if(wskplik==stdin)
    {
	    check_str("nazwa: ", katalognap[ktorykat].nazwa, 15);
    }else
    {

    }
}

void modyfikowanienapwkat(naprawy *ktoranap, FILE*wskplik)
{
    		
    if(wskplik==stdin)
    {
	check_str("nazwa: ", ktoranap->nazwa, 10);
 	check_int((int*)&ktoranap->iloscgodz, "ilosc godzin(0, 30): ", 2, -1, 31);
    }else
    {

    }
}
