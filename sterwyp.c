#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow

void sterwyp()
{
    char wybor[3]; // tablica przechowujaca rozkazy uzytkownika
    unsigned long ktory;//zmienna przechowujaca wybory uzytkownika
    unsigned long ktorysam;
    samochod *samo;

    while(1)
    {
        fputs("samochody z katalogu(1), katalogi samochodow(2), naprawy z katalogu(3), ", stdout);
        fputs("katalogi napraw(4),\nnaprawy z samochodu(5), cala baze(6), wrocic(7)", stdout);
        komenda(wybor);
        if(strcmp(wybor,"1\n")==0)
        {
            puts("Z ktorego ?wyswietl liste katalogow(0)");
            if(fscanf(stdin, "%ld", &ktory)!=1)while(fgetc(stdin)!='\n');
            fgetc(stdin);
            if(ktory==0)
            {
                    wypiszkatsam();
                    if(ilekatsam==0L)break;
                    if(fscanf(stdin, "%ld", &ktory)!=1)while(fgetc(stdin)!='\n');
                    fgetc(stdin);
            }

            if(ktory<=ilekatsam && ktory>0L)
            wypiszsamzkat(ktory-1);
        }else
        if(strcmp(wybor,"2\n")==0)
        {
            wypiszkatsam();
        }else
        if(strcmp(wybor,"3\n")==0)
        {
            puts("Z ktorego ?wyswietl liste katalogow(0)");
            if(fscanf(stdin, "%ld", &ktory)!=1)while(fgetc(stdin)!='\n');
            fgetc(stdin);
            if(ktory==0)
            {
                    wypiszkatnap();
                    if(ilekatnap==0L)break;
                    if(fscanf(stdin, "%ld", &ktory)!=1)while(fgetc(stdin)!='\n');
                    fgetc(stdin);
            }

            if(ktory<=ilekatnap && ktory>0L)
            wypisznapzkat(ktory-1);
        }else
        if(strcmp(wybor,"4\n")==0)
        {
            wypiszkatnap();
        }else
        if(strcmp(wybor,"5\n")==0)
        {
            puts("Z ktorego ?wyswietl liste katalogow i samochodow(0)");
            if(fscanf(stdin, "%ld", &ktory)!=1)while(fgetc(stdin)!='\n');
            fgetc(stdin);
            if(ktory==0)
            {
                    wypiszsamikatsam();
                    if(ilekatsam==0L)break;
                    if(fscanf(stdin, "%ld", &ktory)!=1)while(fgetc(stdin)!='\n');
                    fgetc(stdin);
            }

            if(ktory<=ilekatsam && ktory>0L)//tutaj jesli uzytkownik wpisze numer istniejacego katalogu samochodow
            {
                komenda2(&ktorysam);

                if(katsamochodow[ktory-1L].pocz!=NULL && katsamochodow[ktory-1L].ost->pop->LP>=ktorysam && ktorysam>0L)//tutaj jesli istnieje samochod
                {
                    for(samo=katsamochodow[ktory-1].pocz; samo!=katsamochodow[ktory-1].ost; samo=samo->next)
                    if(samo->LP==ktorysam)break;//szukamy elemnetu o podanym numerze
                    wypisznapzsam(ktory-1, samo);
                }
            }
        }else
        if(strcmp(wybor,"6\n")==0)
        {
            wypiszbaze();
        }else
        if(strcmp(wybor,"7\n")==0)
        {
            break;
        }else
        fprintf(stdout,"error: ZLA KOMENDA\n");
    }
}
