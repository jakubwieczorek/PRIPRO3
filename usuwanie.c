#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow

void usuwaniekatnap(unsigned long ktorykat)
{
    naprawy *temp;
    if(ktorykat==ilekatnap-1)//jesli usuwamy ostatni
    {
        if(katalognap[ktorykat].NAPRAWYPOCZ!=NULL)
        {
            for(temp=katalognap[ktorykat].NAPRAWYPOCZ->next; temp!=NULL; temp=temp->next)
            free(temp->pop);//wystarczy usunac wskaznik na pierwsza naprawe w katalogu i wyczyscic pamiec liczac od drugiego i
            //usuwajac poprzednie
            free(katalognap[ktorykat].NAPRAWYOST);//jesli usuwamy ostatni to nic nie kopiujemy tylko zwalniamy pamiec
            katalognap[ktorykat].NAPRAWYOST=NULL;
            katalognap[ktorykat].NAPRAWYPOCZ=NULL;
        }
    }else
    {
        strcpy(katalognap[ktorykat].nazwa, katalognap[ilekatnap-1].nazwa);

        if(katalognap[ktorykat].NAPRAWYPOCZ!=NULL)
        {
            for(temp=katalognap[ktorykat].NAPRAWYPOCZ->next; temp!=NULL; temp=temp->next)
            free(temp->pop);//zwalniam pamiec dla listy w wybranym katalogu

            free(katalognap[ktorykat].NAPRAWYOST);
            katalognap[ktorykat].NAPRAWYOST=NULL;//zwolnienie pamieci na wybranym..
            katalognap[ktorykat].NAPRAWYPOCZ=NULL;
        }

        katalognap[ktorykat].NAPRAWYPOCZ=katalognap[ilekatnap-1].NAPRAWYPOCZ;//..i przepisanie wskaznika na pierwszy elemnt z ostaatniego katalogu
        katalognap[ktorykat].NAPRAWYOST=katalognap[ilekatnap -1].NAPRAWYOST;
    }
    ilekatnap-=1;
}

void usuwaniekatsam(unsigned long ktorykat)
{
    samochod *temp;
    if(ktorykat==ilekatsam-1)//jesli usuwamy ostatni
    {
        if(katsamochodow[ktorykat].pocz!=NULL)
        {
            for(temp=katsamochodow[ktorykat].pocz->next; temp!=NULL; temp=temp->next)
            free(temp->pop);//wystarczy usunac wskaznik na pierwszy samochod w katalogu i wyczyscic pamiec liczac od drugiego i
            //usuwajac poprzednie
            free(katsamochodow[ktorykat].ost);
            katsamochodow[ktorykat].ost=NULL;
            katsamochodow[ktorykat].pocz=NULL;
        }
    }else
    {
        strcpy(katsamochodow[ktorykat].nazwa, katsamochodow[ilekatsam-1].nazwa);

        if(katsamochodow[ktorykat].pocz!=NULL)
        {
            for(temp=katsamochodow[ktorykat].pocz->next; temp!=NULL; temp=temp->next)
            free(temp->pop);//zwalniam pamiec dla listy w wybranym katalogu

            free(katsamochodow[ktorykat].ost);
            katsamochodow[ktorykat].ost=NULL;
            katsamochodow[ktorykat].pocz=NULL;
        }

        katsamochodow[ktorykat].pocz=katsamochodow[ilekatsam-1].pocz;
        katsamochodow[ktorykat].ost=katsamochodow[ilekatsam-1].ost;
        //przepisanie samochodow
        //to przepisanie wskaznikow na pierwsze elementy
    }
    ilekatsam-=1;
}

void usuwaniesamwkat(samochod *samo, unsigned long ktory)
{
    unsigned long licznik=1L;
    if(samo==katsamochodow[ktory].pocz && samo->next!=katsamochodow[ktory].ost)//jesli usuwamy pierwszy i nie jedyny
    {
        katsamochodow[ktory].pocz=samo->next;//nowy poczatek
        samo->next->pop=NULL;
        free(samo);
    }else
    if(samo==katsamochodow[ktory].pocz && samo->next==katsamochodow[ktory].ost)//jesli usuwamy jedyny
    {
        free(katsamochodow[ktory].ost);
        free(katsamochodow[ktory].pocz);
        katsamochodow[ktory].ost=NULL;
        katsamochodow[ktory].pocz=NULL;
        return;
    }else//gdy jakis w srodku
    {
        samo->next->pop=samo->pop;
        samo->pop->next=samo->next;
        free(samo);
    }
    for(samo=katsamochodow[ktory].pocz; samo!=katsamochodow[ktory].ost; samo=samo->next, licznik+=1L)//zachowanie numeracji
    {//tutaj zachowanie dobrej numeracji
        samo->LP=licznik;
    }
}

void usuwanienapwsam(samochod *samo, naprawy *napra)
{
    unsigned long licznik=1L;
    if(napra==samo->NAPRAWYPOCZ && napra->next!=samo->NAPRAWYOST)//jesli usuwamy pierwszy i nie jedyny
    {
        samo->NAPRAWYPOCZ=napra->next;//nowy poczatek
        napra->next->pop=NULL;
        free(napra);
    }else
    if(napra==samo->NAPRAWYPOCZ && napra->next==samo->NAPRAWYOST)//jesli usuwamy jedyny
    {
        free(samo->NAPRAWYOST);
        free(samo->NAPRAWYPOCZ);
        samo->NAPRAWYOST=NULL;
        samo->NAPRAWYPOCZ=NULL;
        return;
    }else//gdy jakis w srodku
    {
        napra->next->pop=napra->pop;
        napra->pop->next=napra->next;
        free(napra);
    }
    for(napra=samo->NAPRAWYPOCZ; napra!=samo->NAPRAWYOST; napra=napra->next, licznik+=1L)//zachowanie numeracji
    {//tutaj zachowanie dobrej numeracji
        napra->LP=licznik;
    }
}

void usuwanienapwkat(naprawy *napra, unsigned long ktory)
{
    unsigned long licznik=1L;
    if(napra==katalognap[ktory].NAPRAWYPOCZ && napra->next!=katalognap[ktory].NAPRAWYOST)//jesli usuwamy pierwsza i nie jedyna
    {
        katalognap[ktory].NAPRAWYPOCZ=napra->next;//nowy poczatek
        napra->next->pop=NULL;
        free(napra);
    }else
    if(napra==katalognap[ktory].NAPRAWYPOCZ && napra->next==katalognap[ktory].NAPRAWYOST)//jesli usuwamy jedyny
    {
        free(katalognap[ktory].NAPRAWYOST);
        free(katalognap[ktory].NAPRAWYPOCZ);
        katalognap[ktory].NAPRAWYOST=NULL;
        katalognap[ktory].NAPRAWYPOCZ=NULL;
        return;
    }else//jesli ktorys w srodoku
    {
        napra->next->pop=napra->pop;
        napra->pop->next=napra->next;
        free(napra);
    }
    for(napra=katalognap[ktory].NAPRAWYPOCZ; napra!=katalognap[ktory].NAPRAWYOST; napra=napra->next, licznik+=1L)
    {//tutaj zachowanie dobrej numeracji
        napra->LP=licznik;
    }
}
