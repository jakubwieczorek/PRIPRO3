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
    int actel;//aktualny element w itym modelu lub marce
    bool end=false;

    if(wskplik==stdin)
    {
        while(1)
        {
            actel=0;
            fputs("Marka: ", stdout);
            fgets(ktorysam->marka, 10, stdin);
            //pobiera lancuch maksymalnie 9 znakow i wpisuje go do marki kolejnego samochodu (rozmiar)
            if(ktorysam->marka[0]=='\n')
            {// jesli najpierw urzytkownik wcisnal enter to musi wpisac marke ponownie
                fputs("Marka samochodu musi miec chociaz jeden znak", stdout);
            }else
            {
                do//ta petla robi 2 rzeczy
                {
                    if(ktorysam->marka[actel]=='\n')
                    {//tutaj powoduje ze przedostatnim elemntem nie jest enter
                        ktorysam->marka[actel]='\0';
                        end = true;//zmieniamy end co pozwoli wyjsc z petli
                        break;
                    }else
                    if(ktorysam->marka[actel]=='\0')
                    {// a tutaj czysci bufor wejscia gdy ktos wpisal lancuch dluzszy niz przewiduje ta tablica
                        while(fgetc(stdin)!='\n');
                        end = true;//zmieniamy end co pozwoli wyjsc z petli
                        break;
                    }
                    actel+=1;
                }while(1);
            }
            if(end)break; // end == true wiec wychodzimy z petli
        }
        end=false;//uzywam tej samej zmiennej

        while(1)//tutaj wszystko analogicznie
        {
            fputs("Model: ", stdout);
            actel=0;
            fgets(ktorysam->model, 10, stdin);
            if(ktorysam->model[0]=='\n')
            {
                fputs("Model samochodu musi miec chociaz jeden znak", stdout);
            }else
            {
                do
                {
                    if(ktorysam->model[actel]=='\n')
                    {
                        ktorysam->model[actel]='\0';
                        end = true;
                        break;
                    }else
                    if(ktorysam->model[actel]=='\0')
                    {
                        while(fgetc(stdin)!='\n');
                        end = true;
                        break;
                    }
                    actel+=1;
                }while(1);
            }
            if(end)break; // end == true wiec wychodzimy
        }
        fputs("Rok: ", stdout);
        while(scanf("%ld", &ktorysam->rok)!=1 || ktorysam->rok<=0 || ktorysam->rok>3000)
        {
            puts("Blad danych rok musi byc naturalna liczba dodatnia i musi byc mniejszy od 3000.");
            while(getchar()!=('\n'));
            fputs("Rok: ", stdout);
        }
        fgetc(stdin);
        fputs("Przebieg: ", stdout);
        while(scanf("%ld", &ktorysam->przebieg)!=1 || ktorysam->przebieg<=0 || ktorysam->przebieg>2E8)
        {
            puts("Blad danych przebieg musi byc naturalna liczba dodatnia.");
            while(fgetc(stdin)!='\n');
            fputs("Przebieg: ", stdout);
        }
        fgetc(stdin);
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
    bool end=false;
    unsigned short actel=0;

    if(wskplik==stdin)
    {
        while(1)
        {
            end=false;
            actel=0;
            fprintf(stdout, "nazwa: ");
            fgets(katalognap[ktorykat].nazwa, 15, stdin);
            if(katalognap[ktorykat].nazwa[0]=='\n')continue;else
                do//ta petla robi 2 rzeczy
                {
                    if(katalognap[ktorykat].nazwa[actel]=='\n')//tutaj powoduje ze przedostatnim elementem nie jest enter
                    {
                        katalognap[ktorykat].nazwa[actel]='\0';
                        end = true;
                        break;
                    }else
                    if(katalognap[ktorykat].nazwa[actel]=='\0')// a tutaj czysci bufor wejscia gdy ktos wpisal lancuch dluzszy
                    {//niz przewiduje ta tablica
                        while(fgetc(stdin)!='\n');
                        end = true;
                        break;
                    }
                    actel+=1;
                }while(1);
            if(end)break; // end == true wiec wychodzimy z petli
        }
    }else
    {

    }
}

void modyfikowanienapwkat(naprawy *ktoranap, FILE*wskplik)
{
    int actel;
    bool end;
    while(1)
    {
        actel=0;
        end=false;
        fputs("Nazwa: ", stdout);
        fgets(ktoranap->nazwa, 10, stdin);
        //pobiera lancuch maksymalnie 9 znakow i wpisuje go do marki kolejnego samochodu (rozmiar)
        if(ktoranap->nazwa[0]=='\n')
        {// jesli najpierw urzytkownik wcisnal enter to musi wpisac marke ponownie
            fputs("Nazwa naprawy musi miec chociaz jeden znak", stdout);
        }else
        {
            do//ta petla robi 2 rzeczy
            {
                if(ktoranap->nazwa[actel]=='\n')
                {//tutaj powoduje ze przedostatnim elemntem nie jest enter
                    ktoranap->nazwa[actel]='\0';
                    end = true;//zmieniamy end co pozwoli wyjsc z petli
                    break;
                }else
                if(ktoranap->nazwa[actel]=='\0')
                {// a tutaj czysci bufor wejscia gdy ktos wpisal lancuch dluzszy niz przewiduje ta tablica
                    while(fgetc(stdin)!='\n');
                    end = true;//zmieniamy end co pozwoli wyjsc z petli
                    break;
                }
                actel+=1;
            }while(1);
        }
        if(end)break; // end == true wiec wychodzimy z petli
    }
    fputs("ile godzin: ", stdout);
    while(scanf("%hd", &ktoranap->iloscgodz)!=1 || ktoranap->iloscgodz<=0 || ktoranap->iloscgodz>30)
    {
        puts("Blad danych ilosc godzin musi byc naturalna liczba dodatnia i musi byc mniejsza od 30.");
        while(getchar()!=('\n'));
        fputs("Ilosc godzin: ", stdout);
    }
    fgetc(stdin);
}
