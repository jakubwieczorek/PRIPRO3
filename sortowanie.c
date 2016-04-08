#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow

void sortowaniekatsam(unsigned long jak)
{
    unsigned long licznik;
    unsigned long licznikwew;
    katsam tempkat;
    if(jak==0L)
    {
        for(licznik=0L; licznik<ilekatsam; licznik+=1L)
        {
            for(licznikwew=0L; licznikwew<ilekatsam-1-licznik; licznikwew+=1)
            {
                if(strcmp(katsamochodow[licznikwew].nazwa, katsamochodow[licznikwew+1].nazwa)>0)
                {
                    tempkat=katsamochodow[licznikwew];
                    katsamochodow[licznikwew]=katsamochodow[licznikwew+1];
                    katsamochodow[licznikwew+1]=tempkat;
                }
            }
        }
    }else
    if(jak==1L)
    {
        for(licznik=0L; licznik<ilekatsam; licznik+=1L)
        {
            for(licznikwew=0L; licznikwew<ilekatsam-1-licznik; licznikwew+=1)
            {
                if(strcmp(katsamochodow[licznikwew].nazwa, katsamochodow[licznikwew+1].nazwa)<0)
                {
                    tempkat=katsamochodow[licznikwew];
                    katsamochodow[licznikwew]=katsamochodow[licznikwew+1];
                    katsamochodow[licznikwew+1]=tempkat;
                }
            }
        }
    }
    for(licznik=1L; licznik<=ilekatnap; licznik+=1L)
        katsamochodow[licznik-1].numer=licznik;
}

void sortowaniekatnap(unsigned long jak)
{
    unsigned long licznik;
    unsigned long licznikwew;
    katnapraw tempkat;
    if(jak==0L)
    {
        for(licznik=0L; licznik<ilekatnap; licznik+=1L)
        {
            for(licznikwew=0L; licznikwew<ilekatnap-1-licznik; licznikwew+=1)
            {
                if(strcmp(katalognap[licznikwew].nazwa, katalognap[licznikwew+1].nazwa)>0)
                {
                    tempkat=katalognap[licznikwew];
                    katalognap[licznikwew]=katalognap[licznikwew+1];
                    katalognap[licznikwew+1]=tempkat;
                }
            }
        }
    }else
    if(jak==1L)
    {
        for(licznik=0L; licznik<ilekatnap; licznik+=1L)
        {
            for(licznikwew=0L; licznikwew<ilekatnap-1-licznik; licznikwew+=1)
            {
                if(strcmp(katalognap[licznikwew].nazwa, katalognap[licznikwew+1].nazwa)<0)
                {
                    tempkat=katalognap[licznikwew];
                    katalognap[licznikwew]=katalognap[licznikwew+1];
                    katalognap[licznikwew+1]=tempkat;
                }
            }
        }
    }

    for(licznik=1L; licznik<=ilekatnap; licznik+=1L)
        katalognap[licznik-1].numer=licznik;
}

void sortowaniesamwkat(unsigned long ktorykat, unsigned long wgczego, unsigned long jak)
{
    unsigned long licznik;
    unsigned long licznikwew;
    int rozmiar, rozmiar2;

    if(katsamochodow[ktorykat].pocz==NULL)return;//jesli nie ma samochodow to konczymy

    samochod **tab, *temp;//tablica wskaznikow na samochody w niej przechowujemy elementow list
    //*temp zmienna pomocnicza do kopiowania i do tworzeni nowej listy

    tab=malloc(sizeof(*tab)*katsamochodow[ktorykat].ost->pop->LP);
    for(licznik=0, temp=katsamochodow[ktorykat].pocz; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1, temp=temp->next)
        tab[licznik]=temp;//zapisanie listy w tablicy

    if(wgczego==0L)//wg marki
    {
        if(jak==0L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(strcmp(tab[licznikwew]->marka, tab[licznikwew+1]->marka)>0L)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }else
        if(jak==1L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(strcmp(tab[licznikwew]->marka, tab[licznikwew+1]->marka)<0L)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }
    }else
    if(wgczego==1L)//wg modelu
    {
        if(jak==0L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(strcmp(tab[licznikwew]->model, tab[licznikwew+1]->model)>0L)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }else
        if(jak==1L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(strcmp(tab[licznikwew]->model, tab[licznikwew+1]->model)<0L)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }
    }else
    if(wgczego==2L)//wg roku
    {
        if(jak==0L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(tab[licznikwew]->rok>tab[licznikwew+1]->rok)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }else
        if(jak==1L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(tab[licznikwew]->rok<tab[licznikwew+1]->rok)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }
    }else
    if(wgczego==3L)//wg przebiegu
    {
        if(jak==0L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(tab[licznikwew]->przebieg>tab[licznikwew+1]->przebieg)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }else
        if(jak==1L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(tab[licznikwew]->przebieg>tab[licznikwew+1]->przebieg)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }
    }else
    if(wgczego==4L)//wg ilosci napraw
    {
        if(jak==0L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(tab[licznikwew]->NAPRAWYOST==NULL)//zapobieganie wystapienia bledu gdy nie ma napraw w samochodzie
                    rozmiar=0;else
                    rozmiar=tab[licznikwew]->NAPRAWYOST->pop->LP;

                    if(tab[licznikwew+1]->NAPRAWYOST==NULL)//zapobieganie wystapienia bledu gdy nie ma napraw w samochodzie
                    rozmiar2=0;else
                    rozmiar2=tab[licznikwew+1]->NAPRAWYOST->pop->LP;

                    if(rozmiar>rozmiar2)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }else
        if(jak==1L)
        {
            for(licznik=0L; licznik<katsamochodow[ktorykat].ost->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katsamochodow[ktorykat].ost->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(tab[licznikwew]->NAPRAWYOST==NULL)//zapobieganie wystapienia bledu gdy nie ma napraw w samochodzie
                    rozmiar=0;else
                    rozmiar=tab[licznikwew]->NAPRAWYOST->pop->LP;

                    if(tab[licznikwew+1]->NAPRAWYOST==NULL)//zapobieganie wystapienia bledu gdy nie ma napraw w samochodzie
                    rozmiar2=0;else
                    rozmiar2=tab[licznikwew+1]->NAPRAWYOST->pop->LP;

                    if(rozmiar<rozmiar2)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
        }
    }
    katsamochodow[ktorykat].pocz=tab[0];
    katsamochodow[ktorykat].pocz->LP=1L;
    temp=katsamochodow[ktorykat].pocz;
    licznik=katsamochodow[ktorykat].ost->pop->LP;
    for(licznikwew=1; licznikwew<licznik; licznikwew+=1)
    {
        temp->next=tab[licznikwew];
        temp->next->pop=tab[licznikwew-1];
        temp=temp->next;
        temp->LP=licznikwew+1L;
    }
    temp->next=katsamochodow[ktorykat].ost;
    katsamochodow[ktorykat].ost->pop=temp;
    free(tab);
}

void sortowanienapwkat(unsigned long ktorykat, unsigned long jak)
{
    unsigned long licznik;
    unsigned long licznikwew;

    if(katalognap[ktorykat].NAPRAWYPOCZ==NULL)return;//jesli nie ma napraw to konczymy

    naprawy **tab, *temp;//tablica wskaznikow na naprawy w niej przechowujemy elementy listy
    //*temp zmienna pomocnicza do kopiowania i do tworzeni nowej listy

    tab=malloc(sizeof(*tab)*katalognap[ktorykat].NAPRAWYOST->pop->LP);
    for(licznik=0, temp=katalognap[ktorykat].NAPRAWYPOCZ; licznik<katalognap[ktorykat].NAPRAWYOST->pop->LP; licznik+=1, temp=temp->next)
        tab[licznik]=temp;//zapisanie listy w tablicy

    if(jak==0L)
    {
        for(licznik=0L; licznik<katalognap[ktorykat].NAPRAWYOST->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katalognap[ktorykat].NAPRAWYOST->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(strcmp(tab[licznikwew]->nazwa, tab[licznikwew+1]->nazwa)>0)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
    }else
    if(jak==1L)
    {
        for(licznik=0L; licznik<katalognap[ktorykat].NAPRAWYOST->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<katalognap[ktorykat].NAPRAWYOST->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(strcmp(tab[licznikwew]->nazwa, tab[licznikwew+1]->nazwa)<0)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
    }
    katalognap[ktorykat].NAPRAWYPOCZ=tab[0];
    katalognap[ktorykat].NAPRAWYPOCZ->LP=1L;
    temp=katalognap[ktorykat].NAPRAWYPOCZ;
    licznik=katalognap[ktorykat].NAPRAWYOST->pop->LP;
    for(licznikwew=1; licznikwew<licznik; licznikwew+=1)
    {
        temp->next=tab[licznikwew];
        temp->next->pop=tab[licznikwew-1];
        temp=temp->next;
        temp->LP=licznikwew+1L;
    }
    temp->next=katalognap[ktorykat].NAPRAWYOST;
    katalognap[ktorykat].NAPRAWYOST->pop=temp;
    free(tab);
}

void sortowanienapwsam(unsigned long ktorykat, unsigned long ktorysam, unsigned long jak)
{
    unsigned long licznik;
    unsigned long licznikwew;
    samochod *samo;
    naprawy **tab, *temp;//tablica wskaznikow na naprawy w niej przechowujemy elementy listy
    //*temp zmienna pomocnicza do kopiowania i do tworzeni nowej listy

    for(samo=katsamochodow[ktorykat].pocz; samo!=katsamochodow[ktorykat].ost; samo=samo->next)
        if(samo->LP==ktorysam+1L)break;//szukamy elemnetu o podanym numerze (ktorysam) +1 bo przekazalismy o jeden mniej

    if(samo->NAPRAWYPOCZ==NULL)return;//jesli nie ma napraw to konczymy

    tab=malloc(sizeof(*tab)*samo->NAPRAWYOST->pop->LP);
    for(licznik=0, temp=samo->NAPRAWYPOCZ; licznik<samo->NAPRAWYOST->pop->LP; licznik+=1, temp=temp->next)
        tab[licznik]=temp;//zapisanie listy w tablicy
    if(jak==0L)
    {
        for(licznik=0L; licznik<samo->NAPRAWYOST->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<samo->NAPRAWYOST->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(strcmp(tab[licznikwew]->nazwa, tab[licznikwew+1]->nazwa)>0)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
    }else
    if(jak==1L)
    {
        for(licznik=0L; licznik<samo->NAPRAWYOST->pop->LP; licznik+=1L)
            {
                for(licznikwew=0L; licznikwew<samo->NAPRAWYOST->pop->LP-1L-licznik; licznikwew+=1L)
                {
                    if(strcmp(tab[licznikwew]->nazwa, tab[licznikwew+1]->nazwa)<0)
                    {
                        temp=tab[licznikwew];
                        tab[licznikwew]=tab[licznikwew+1];
                        tab[licznikwew+1]=temp;
                    }
                }
            }
    }
    samo->NAPRAWYPOCZ=tab[0];
    samo->NAPRAWYPOCZ->LP=1L;
    temp=samo->NAPRAWYPOCZ;
    licznik=samo->NAPRAWYOST->pop->LP;
    for(licznikwew=1; licznikwew<licznik; licznikwew+=1)
    {
        temp->next=tab[licznikwew];
        temp->next->pop=tab[licznikwew-1];
        temp=temp->next;
        temp->LP=licznikwew+1L;
    }
    temp->next=samo->NAPRAWYOST;
    samo->NAPRAWYOST->pop=temp;
    free(tab);
}


