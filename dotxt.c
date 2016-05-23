#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw

extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw

extern size_t ilekatsam;//zlicza katalogi samochodow

int expdotxt()//1 gdy blad otwarcia, 2 gdy blad zamkniecia
{
    FILE *wskplik;
    unsigned long ktory;//licznik do katalogow
    samochod *aktualny;
    naprawy *aktualnynap;
/*
* katalog samochodow
$ ignoruje
+ samochody
@ naprawy w samochodach
# katalogi napraw
^ naprawy w katalogach
*/

    if((wskplik=fopen("baza.txt", "w+"))==NULL)
    {
        perror("error: ");
        return 1;//1 gdy blad otwarcia
    }
    
    for(ktory=0L; ktory<ilekatsam; ktory+=1L)
    {	
	fputs("$ KatalogSamochodow$\n", wskplik);
        fprintf(wskplik, "* %2ld %17s\n", katsamochodow[ktory].numer, katsamochodow[ktory].nazwa);
	//pomiedzy $ nie importuje w kolejnej funkcji
        if(katsamochodow[ktory].pocz!=NULL)fprintf(wskplik, "$ samochody:$\n");
        
	for(aktualny=katsamochodow[ktory].pocz; aktualny!=katsamochodow[ktory].ost && aktualny!=NULL; aktualny=aktualny->next)
        {
	//+ samochod  		
            fprintf(wskplik, "+ %4lu %12s%12s", aktualny->LP, aktualny->marka, aktualny->model);
            fprintf(wskplik, "%5ld%12ld\n", aktualny->rok, aktualny->przebieg);

            if(aktualny->NAPRAWYPOCZ!=NULL)fprintf(wskplik, "$ NaprawyWSamochodzie$\n");
            for(aktualnynap=aktualny->NAPRAWYPOCZ; aktualnynap!=aktualny->NAPRAWYOST && aktualnynap!=NULL; aktualnynap=aktualnynap->next)
            {//% naprawa w samochodzie
                fprintf(wskplik, "@ %7lu %12s%14d \n", aktualnynap->LP, aktualnynap->nazwa, aktualnynap->iloscgodz);
            }
        }
    }
    
    for(ktory=0L; ktory<ilekatnap; ktory+=1L)
    {//# katalog napraw
	fputs("$ KatalogNapraw$\n", wskplik);
        fprintf(wskplik, "#  %2ld %17s\n", katalognap[ktory].numer, katalognap[ktory].nazwa);
        if(katalognap[ktory].NAPRAWYPOCZ!=NULL) fprintf(wskplik, "$  NaprawyWKatalogu$\n");
        
	for(aktualnynap=katalognap[ktory].NAPRAWYPOCZ; aktualnynap!=katalognap[ktory].NAPRAWYOST && aktualnynap!=NULL; 
	aktualnynap=aktualnynap->next)//^ naprawy w katalogu
            fprintf(wskplik, "^ %7lu %12s%14d\n", aktualnynap->LP, aktualnynap->nazwa, aktualnynap->iloscgodz);
    }

    if(fclose(wskplik)!=0)
    {
        perror("error: ");

        return 2;//1 gdy blad zamkniecia
    }
    return 0;
}


/*
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

}*/
