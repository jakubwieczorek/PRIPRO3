#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow

void sterdod()
{
    char wybor[3]; // tablica przechowujaca rozkazy uzytkownika

    while(1)
    {
        puts("samochod(1), katalog samochodu(2), naprawe do katalogu(3), katalog napraw(4)");
        puts("naprawe do samochodu(5), wrocic(6)");
        komenda(wybor);
        if(strcmp(wybor,"1\n")==0)
        {
            if(dodsam())fprintf(stderr, "error: segmentation fault");
        }else
        if(strcmp(wybor,"2\n")==0)
        {
            if(dodkatsam())fprintf(stderr, "error: segmentation fault");
        }else
        if(strcmp(wybor,"3\n")==0)
        {
            if(dodnap())fprintf(stderr, "error: segmentation fault");
        }else
        if(strcmp(wybor,"4\n")==0)
        {
            if(dodkatnap())fprintf(stderr, "error: segmentation fault");
        }else
        if(strcmp(wybor,"5\n")==0)
        {
            dodnapdosam();
        }else
        if(strcmp(wybor,"6\n")==0)
        {
            break;
        }else
        fprintf(stderr,"error: ZLA KOMENDA\n");
    }
}
