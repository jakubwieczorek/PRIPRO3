#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"


extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow

void wypiszsamzkat(unsigned long ktory)
{
    samochod *aktualny;
    fprintf(stdout, "%5s%12s%12s%5s%12s\n", "LP.", "Marka", "Model", "Rok", "Przebieg");
    for(aktualny=katsamochodow[ktory].pocz; aktualny!=katsamochodow[ktory].ost && aktualny!=NULL; aktualny=aktualny->next)
    {
        fprintf(stdout, "%4lu.%12s%12s", aktualny->LP, aktualny->marka, aktualny->model);
        fprintf(stdout, "%5ld%12ld\n", aktualny->rok, aktualny->przebieg);
    }
}

void wypisznapzkat(unsigned long ktory)
{
    naprawy *aktualny;

    fprintf(stdout, "%8s%12s%14s\n", "LP.", "Nazwa", "Ilosc godzin");
    for(aktualny=katalognap[ktory].NAPRAWYPOCZ; aktualny!=katalognap[ktory].NAPRAWYOST && aktualny!=NULL; aktualny=aktualny->next)
    {
        fprintf(stdout, "%7lu.%12s%14d\n", aktualny->LP, aktualny->nazwa, aktualny->iloscgodz);
    }
}

void wypiszkatsam()
{
    unsigned long licznik;
    fprintf(stdout, "Katalogi Samochodow:\n");
    for(licznik=0L; licznik<ilekatsam; licznik+=1L)
        fprintf(stdout, "%2ld.%17s\n", katsamochodow[licznik].numer, katsamochodow[licznik].nazwa);

}

void wypiszbaze()
{
    unsigned long ktory;//licznik do katalogow
    samochod *aktualny;
    naprawy *aktualnynap;

    fputs("Baza:\n\n", stdout);

    wypiszkatsam();
    putc('\n', stdout);
    wypiszkatnap();
    putc('\n', stdout);

    for(ktory=0L; ktory<ilekatsam; ktory+=1L)
    {
        fprintf(stdout, "%2ld.%17s\n", katsamochodow[ktory].numer, katsamochodow[ktory].nazwa);
        if(katsamochodow[ktory].pocz!=NULL)fprintf(stdout, "%5s%12s%12s%5s%12s\n", "LP.", "Marka", "Model", "Rok", "Przebieg");
        for(aktualny=katsamochodow[ktory].pocz; aktualny!=katsamochodow[ktory].ost && aktualny!=NULL; aktualny=aktualny->next)
        {
            fprintf(stdout, "%4lu.%12s%12s", aktualny->LP, aktualny->marka, aktualny->model);
            fprintf(stdout, "%5ld%12ld\n", aktualny->rok, aktualny->przebieg);
        }
    }

    for(ktory=0L; ktory<ilekatnap; ktory+=1L)
    {
        fprintf(stdout, "%2ld.%17s\n", katalognap[ktory].numer, katalognap[ktory].nazwa);
        if(katalognap[ktory].NAPRAWYPOCZ!=NULL) fprintf(stdout, "%8s%12s%14s\n", "LP.", "Nazwa", "Ilosc godzin");
        for(aktualnynap=katalognap[ktory].NAPRAWYPOCZ; aktualnynap!=katalognap[ktory].NAPRAWYOST && aktualnynap!=NULL; aktualnynap=aktualnynap->next)
            fprintf(stdout, "%7lu.%12s%14d\n", aktualnynap->LP, aktualnynap->nazwa, aktualnynap->iloscgodz);
    }

    wypiszsamikatsaminap();
}

void wypiszsamikatsaminap()
{
    unsigned long ktory;//licznik do katalogow
    samochod *aktualny;
    naprawy *aktualnynap;

    for(ktory=0L; ktory<ilekatsam; ktory+=1L)
    {
        fprintf(stdout, "%2ld.%17s\n", katsamochodow[ktory].numer, katsamochodow[ktory].nazwa);
        if(katsamochodow[ktory].pocz!=NULL)fprintf(stdout, "%5s%12s%12s%5s%12s\n", "LP.", "Marka", "Model", "Rok", "Przebieg");
        for(aktualny=katsamochodow[ktory].pocz; aktualny!=katsamochodow[ktory].ost && aktualny!=NULL; aktualny=aktualny->next)
        {
            fprintf(stdout, "%4lu.%12s%12s", aktualny->LP, aktualny->marka, aktualny->model);
            fprintf(stdout, "%5ld%12ld\n", aktualny->rok, aktualny->przebieg);

            if(aktualny->NAPRAWYPOCZ!=NULL)fprintf(stdout, "%8s%12s%14s\n", "LP.", "Nazwa", "Ilosc godzin");
            for(aktualnynap=aktualny->NAPRAWYPOCZ; aktualnynap!=aktualny->NAPRAWYOST && aktualnynap!=NULL; aktualnynap=aktualnynap->next)
            {
                fprintf(stdout, "%7lu.%12s%14d\n", aktualnynap->LP, aktualnynap->nazwa, aktualnynap->iloscgodz);
            }
        }
    }
}

void wypisznapzsam(unsigned long ktorykat, samochod *aktualny)
{
    naprawy *aktualnynap;
    fprintf(stdout, "%8s%12s%14s\n", "LP.", "Nazwa", "Ilosc godzin");
    for(aktualnynap=aktualny->NAPRAWYPOCZ; aktualnynap!=aktualny->NAPRAWYOST && aktualnynap!=NULL; aktualnynap=aktualnynap->next)
    {
        fprintf(stdout, "%7lu.%12s%14d\n", aktualnynap->LP, aktualnynap->nazwa, aktualnynap->iloscgodz);
    }
}

void wypiszkatnap()
{
    unsigned long licznik;
    fprintf(stdout, "Katalogi Napraw:\n");
    for(licznik=0L; licznik<ilekatnap; licznik+=1L)
        fprintf(stdout, "%2ld.%17s\n", katalognap[licznik].numer, katalognap[licznik].nazwa);

}

void wypisznapikatnap()
{
    unsigned long ktory;
    naprawy *aktualnynap;
    for(ktory=0L; ktory<ilekatnap; ktory+=1L)
    {
        fprintf(stdout, "%2ld.%17s\n", katalognap[ktory].numer, katalognap[ktory].nazwa);
        if(katalognap[ktory].NAPRAWYPOCZ!=NULL) fprintf(stdout, "%8s%12s%14s\n", "LP.", "Nazwa", "Ilosc godzin");
        for(aktualnynap=katalognap[ktory].NAPRAWYPOCZ; aktualnynap!=katalognap[ktory].NAPRAWYOST && aktualnynap!=NULL; aktualnynap=aktualnynap->next)
            fprintf(stdout, "%7lu.%12s%14d\n", aktualnynap->LP, aktualnynap->nazwa, aktualnynap->iloscgodz);
    }
}

void wypiszsamikatsam()
{
    unsigned long ktory;//licznik do katalogow
    samochod *aktualny;

    for(ktory=0L; ktory<ilekatsam; ktory+=1L)
    {
        fprintf(stdout, "%2ld.%17s\n", katsamochodow[ktory].numer, katsamochodow[ktory].nazwa);
        if(katsamochodow[ktory].pocz!=NULL)fprintf(stdout, "%5s%12s%12s%5s%12s\n", "LP.", "Marka", "Model", "Rok", "Przebieg");
        for(aktualny=katsamochodow[ktory].pocz; aktualny!=katsamochodow[ktory].ost && aktualny!=NULL; aktualny=aktualny->next)
        {
            fprintf(stdout, "%4lu.%12s%12s", aktualny->LP, aktualny->marka, aktualny->model);
            fprintf(stdout, "%5ld%12ld\n", aktualny->rok, aktualny->przebieg);
        }
    }
}

