#ifndef _STDMOJ_
#define _STDMOJ_

typedef struct NAPRAWY
{
        unsigned long LP;
        char nazwa[10];
        unsigned short iloscgodz;
        struct NAPRAWY *next;
        struct NAPRAWY *pop;
}naprawy;

typedef struct SAMOCHOD
{
        char marka[10], model[10];
        unsigned long rok, przebieg, LP;
        struct SAMOCHOD *next;
        struct SAMOCHOD *pop;
        naprawy *NAPRAWYPOCZ;//LISTA DWUKIERUNKOWA napraw
        naprawy *NAPRAWYOST;
}samochod;

typedef struct
{
    unsigned long numer;
    char nazwa[15];
    naprawy *NAPRAWYPOCZ;
    naprawy *NAPRAWYOST;//w kazdym katalogu jest lista dwukierunkowa napraw
}katnapraw;

typedef struct
{
    unsigned long numer;
    char nazwa[15];
    samochod *pocz;//w kazdym katalogu jest lista dwukierunkowa samochodow
    samochod *ost;
}katsam;

void wypisznapikatnap();//wypisuje katalogi napraw i naprawy

void wypiszsamikatsam();//wypisuje katalogi samochodow i samochody

void wypiszkatnap();//wypisuje katalogi napraw

void wypisznapzkat(unsigned long ktory);//wypisuje naprawy z danego katalogu podanego jako argument funkcji

int dodnap();//dodaje naprawy do katalogownapraw

int dodnapdosam();//dodaje naprawy do samochodow zwraca 0 gdy powodzenie 1 i 2 gdy blad alokacji odpowiednio katalogu samochodow i katalogu napraw

bool dodkatnap();//dodaje katalogi napraw

void wypisznapzsam(unsigned long ktorykat, samochod *aktualny);

void wypiszsamzkat(unsigned long ktory);//wypisuje samochody z danego katalogu podanego jako argument funkcji

void komenda(char *wybor);//pobiera rozkazy uzytkownika

bool dodkatsam();//tworzy katalogi dla samochodow

void wypiszkatsam();//wypisuje katalogi samochodow

int dodsam();//dodaje samochody do katalogowC:\Users\Jakub Wieczorek\Desktop\C\ListaJednokierunkowa\Zadanie3\stdmoj.h

void wypiszbaze();//wypisuje cala baze

void wypiszsamikatsaminap();//wypisuje samochody wraz z naprawami

void sterwyp();//steruje wypisywaniem w main

void sterdod();//steruje dodawaniem w main

void stermod();//steruje modyfikowaniem w main

void sterusu();//steruje usuwaniem w main

void stersort();//steruje wypisywaniem w main

void modyfikowaniesamwkat(samochod *ktorysam, unsigned long ktorykat, FILE *wskplik);//modyfikowanie samochodu w katalogu

void modyfikowaniekatsam(unsigned long ktorykat, FILE *wskplik);//modyfikowanie katalogu samochodow

void modyfikowaniekatnap(unsigned long ktorykat, FILE *wskplik);//modyfikowanie katalogu napraw

void modyfikowanienapwkat(naprawy *ktoranap, FILE *wskplik);//modyfikuje naprawy w katalogu gdy wybiera 1 to przekazujemy 1

void komenda2(unsigned long *wybor);//pobiera liczbowe rozkazy urzytkownika (fscanf) oraz liczbowe dane urztkownika do wprowadzenia
// np. do przebiegu czy tez roku
void usuwaniekatsam(unsigned long ktorykat);

void usuwaniesamwkat(samochod *samo, unsigned long ktory);

void usuwanienapwsam(samochod *samo, naprawy *napra);

void usuwaniekatnap(unsigned long ktorykatnap);

void usuwanienapwkat(naprawy *napra, unsigned long ktory);

void sortowaniekatnap(unsigned long jak);//sortuje katalogi napraw

void sortowaniekatsam(unsigned long jak);

void sortowanienapwsam(unsigned long ktorykat, unsigned long ktorysam, unsigned long jak);

void sortowaniesamwkat(unsigned long ktorykat, unsigned long wgczego, unsigned long jak);

void sortowanienapwkat(unsigned long ktorykat, unsigned long jak);

#endif
