#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw

extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw

extern size_t ilekatsam;//zlicza katalogi samochodow

int expdobin()//1 gdy blad otwarcia, 2 gdy blad zamkniecia
{

    int licznikkatsam;

    samochod *liczniksam;

    naprawy *liczniknap;

    int licznikkatnap;

    FILE *wskplik;

    if(wskplik=fopen("baza.ula", "wb+")==NULL)
    {
        perror("error: ");
        return 1;//1 gdy blad otwarcia
    }

    for(licznikkatsam=0; licznikkatsam<ilekatsam; licznikkatsam+=1)
    {

        fwrite(katsamochodow[licznikkatsam].numer, sizeof(unsigned long), 1, wskplik);//zaezpieczenie przy zlym zapisie

        fwrite(katsamochodow[licznikkatsam].nazwa, sizeof(char)*5, 3, wskplik);

        for(liczniksam = katsamochodow[licznikkatsam].pocz; liczniksam!=NULL && liczniksam!=katsamochodow[licznikkatsam].ost; liczniksam=liczniksam->next)

        {

            fwrite(liczniksam->LP, sizeof(unsigned long), 1, wskplik);

            fwrite(liczniksam->marka, sizeof(char)*5, 2, wskplik);

            fwrite(liczniksam->model, sizeof(char)*5, 2, wskplik);

            fwrite(liczniksam->przebieg, sizeof(unsigned long), 1, wskplik);

            fwrite(liczniksam->rok, sizeof(unsigned long), 1, wskplik);

            for(liczniknap=liczniksam->NAPRAWYPOCZ; liczniknap!=NULL && liczniknap!=liczniksam->NAPRAWYOST; liczniknap=liczniknap->next)

            {

                fwrite(liczniknap->LP, sizeof(unsigned long), 1, wskplik);

                fwrite(liczniknap->nazwa, sizeof(char)*5, 2, wskplik);

            }

        }

    }



    for(licznikkatnap=0; licznikkatnap<ilekatnap; licznikkatnap+=1)

    {

        fwrite(katalognap[licznikkatnap].numer, sizeof(unsigned long), 1, wskplik);//zaezpieczenie przy zlym zapisie

        fwrite(katalognap[licznikkatnap].nazwa, sizeof(char)*5, 3, wskplik);



        for(liczniknap=katalognap[licznikkatnap].NAPRAWYPOCZ; liczniknap!=NULL && liczniknap!=katalognap[licznikkatnap].NAPRAWYOST; liczniknap=liczniknap->next)

        {

            fwrite(liczniknap->LP, sizeof(unsigned long), 1, wskplik);

            fwrite(liczniknap->nazwa, sizeof(char)*5, 2, wskplik);

        }



    }



    if(wskplik=fclose(wskplik)==NULL)

    {

        perror("error: ");

        return 2;//1 gdy blad zamkniecia

    }

}



void impodbin()

{

    int licznikkatsam;

    samochod *liczniksam;

    naprawy *liczniknap;

    int licznikkatnap;



    FILE *wskplik;

    if(wskplik=fopen("baza.ula", "wp+")==NULL)

    {

        perror("error: ");

        return 1;//1 gdy blad otwarcia

    }



    for(licznikkatnap=0; feo(wskplik)==0; licznikkatnap+=1)

    {

        katalognap[ilekatnap].NAPRAWYPOCZ=NULL;//dla listy przypisuje NULL na koncu i poczatku

        katalognap[ilekatnap].NAPRAWYOST=NULL;



        ilekatnap+=1L;//zwiekszamy liczbe katalogow samochodow



        fread(katalognap[licznikkatnap].numer, sizeof(unsigned long), 1, wskplik);//zaezpieczenie przy zlym zapisie

        fread(katalognap[licznikkatnap].nazwa, sizeof(char)*5, 3, wskplik);



        for(liczniknap=katalognap[licznikkatnap].NAPRAWYPOCZ; liczniknap!=NULL && liczniknap!=katalognap[licznikkatnap].NAPRAWYOST; liczniknap=liczniknap->next)

        {

            if(katalognap[licznikkatnap].NAPRAWYPOCZ==NULL)//gdy w katalogu nie ma zadnego samochodu

            {

                if((katalognap[wybor-1].NAPRAWYPOCZ=malloc(sizeof(naprawy)))==NULL) return 2;//alokacja o rozmiarze zmiennej

                //samochod, a nie samochod* - to wskaznik a wskaznik ma duzo mniejszy rozmiar

                if((katalognap[wybor-1].NAPRAWYOST=malloc(sizeof(naprawy)))==NULL) return 2;

                //utworzenie listy

                katalognap[wybor-1].NAPRAWYPOCZ->next=katalognap[wybor-1].NAPRAWYOST;

                katalognap[wybor-1].NAPRAWYOST->pop=katalognap[wybor-1].NAPRAWYPOCZ;

                katalognap[wybor-1].NAPRAWYPOCZ->pop=NULL;

                katalognap[wybor-1].NAPRAWYOST->next=NULL;



                aktualny=katalognap[wybor-1].NAPRAWYPOCZ;//operujemy na aktualnym

                aktualny->LP=1L;//zerujemy numer samochodu tak aby po dodaniu wynosil 1 potem 2 itd.

            }else

                {// gdy juz lista jest utworzona dodajemy na jeden przed ostatnim nowy

                    if((aktualny=malloc(sizeof(naprawy)))==NULL) return 2;//tu jest blad

                    aktualny->next=katalognap[wybor-1].NAPRAWYOST;

                    aktualny->pop=katalognap[wybor-1].NAPRAWYOST->pop;

                    aktualny->pop->next=aktualny;

                    aktualny->next->pop=aktualny;

                }

            fread(liczniknap->LP, sizeof(unsigned long), 1, wskplik);

            fread(liczniknap->nazwa, sizeof(char)*5, 2, wskplik);

        }



    }

    if(wskplik=fclose(wskplik)==NULL)

    {

        perror("error: ");

        return 2;//1 gdy blad zamkniecia

    }

}
