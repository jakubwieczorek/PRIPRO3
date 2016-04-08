#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"


katnapraw *katalognap;//katalogi napraw
katsam *katsamochodow;//katalogi samochodow

size_t ilekatnap;//zlicze katalogi napraw
size_t ilekatsam;//zlicza katalogi samochodow

void komenda(char *wybor)
{
    fgets(wybor, 3, stdin);
    if(wybor[1]!='\n') while(fgetc(stdin)!='\n');
}

void komenda2(unsigned long *wybor)
{
    while(fscanf(stdin, "%ld", wybor)!=1)while(fgetc(stdin)!='\n');
    while(fgetc(stdin)!='\n');
}

int main()
{
        char wybor[3]; // tablica przechowujaca rozkazy uzytkownika

        puts("Instrukcja: Jesli chcesz:");

        while(1)
        {
            puts("1) dodac \"1\".\n2) wyswietlic \"2\"\n3) zmodyfikowac\"3\"\n4) usunac \"4\"");
            puts("5) posortowac \"5\" 6) exportowac \"6\"\n7) zakonczyc \"0\".");
            komenda(wybor);
            if(strcmp(wybor,"1\n")==0)
            {
                sterdod();
            } else
            if(strcmp(wybor,"2\n")==0)
            {
                sterwyp();
            }else
            if(strcmp(wybor,"3\n")==0)
            {
                stermod();
            }else
            if(strcmp(wybor,"4\n")==0)
            {
                sterusu();
            }else
            if(strcmp(wybor,"5\n")==0)
            {
                stersort();
            }else
	    if(strcmp(wybor,"6\n")==0)
            {
                expdobin();
            }else
            if(strcmp(wybor,"0\n")==0)
            {
                fprintf(stdout, "Czy na pewno chcesz zakonczyc \"T\" - Tak, \"N\" - Nie ?");
                while(1)
                {
                    komenda(wybor);
                    if(strcmp(wybor,"T\n")==0) return 0; else
                    if(strcmp(wybor,"N\n")==0) break; else
                    {
                        puts("Nie ma takiej komendy2");
                    }
                }
            }else
            fprintf(stderr,"error: ZLA KOMENDA\n");
        }

    return EXIT_SUCCESS;
}
