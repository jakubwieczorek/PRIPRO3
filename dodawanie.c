#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"
//
extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow

bool dodkatsam()//zwraca 1 gdy blad alokacji pamieci dla katalogu
{//0 gdy powodzenie
    fputs("Dodajesz nowy katalog samochodow.", stdout);
    if((katsamochodow=realloc(katsamochodow, sizeof(*katsamochodow)*(ilekatsam+1L)))==NULL)
    {
        perror("error:");
        return true;
    }

    modyfikowaniekatsam(ilekatsam, stdin);

    katsamochodow[ilekatsam].numer=ilekatsam+1L;

    katsamochodow[ilekatsam].pocz=NULL;
    katsamochodow[ilekatsam].ost=NULL;

    ilekatsam+=1L;//zwiekszamy liczbe katalogow samochodow

    return false;
}

int dodsam()//zwraca 1 gdy blad alokacji pamieci dla pierwszego katalogu, 2 gdy blad alokacji pamieci dla nowego samochodu
{//0 gdy powodzenie
    unsigned long wybor;// tablica przechowujaca rozkazy uzytkownika
    samochod *aktualny;
    if(ilekatsam==0L)//jesli nie ma zadnego katalogu samochodu to trzeba go uprzednio dodac
        if(dodkatsam())return 1;//jesli blad alokacji pamieci dla ppierwszego katalogu

    while(1)
    {
        fputs("W ktorym katalogu dodac samochod ?wyswietl liste katalogow(0)", stdout);
        if(fscanf(stdin, "%ld", &wybor)!=1) while(fgetc(stdin)!='\n');
        fgetc(stdin);

        if(wybor==0L)
        {
            wypiszkatsam();
            if(fscanf(stdin, "%ld", &wybor)!=1) while(fgetc(stdin)!='\n');
            fgetc(stdin);
        }
        if(wybor<=ilekatsam && wybor>0L)
        {//tutaj czytanie samochodu do katalogu wybor-1
            if(katsamochodow[wybor-1].pocz==NULL)//gdy w katalogu nie ma zadnego samochodu
            {
                if((katsamochodow[wybor-1].pocz=malloc(sizeof(samochod)))==NULL) return 2;//alokacja o rozmiarze zmiennej
                //samochod, a nie samochod* - to wskaznik a wskaznik ma duzo mniejszy rozmiar
                if((katsamochodow[wybor-1].ost=malloc(sizeof(samochod)))==NULL) return 2;
                //utworzenie listy
                katsamochodow[wybor-1].pocz->next=katsamochodow[wybor-1].ost;
                katsamochodow[wybor-1].ost->pop=katsamochodow[wybor-1].pocz;
                katsamochodow[wybor-1].pocz->pop=NULL;
                katsamochodow[wybor-1].ost->next=NULL;

                aktualny=katsamochodow[wybor-1].pocz;//operujemy na aktualnym
                aktualny->LP=1L;//zerujemy numer samochodu tak aby po dodaniu wynosil 1 potem 2 itd.
            }else
                {// gdy juz lista jest utworzona dodajemy na jeden przed ostatnim nowy
                    if((aktualny=malloc(sizeof(samochod)))==NULL) return 2;//tu jest blad
                    aktualny->next=katsamochodow[wybor-1].ost;
                    aktualny->pop=katsamochodow[wybor-1].ost->pop;
                    aktualny->pop->next=aktualny;
                    aktualny->next->pop=aktualny;
                }

            modyfikowaniesamwkat(aktualny, wybor, stdin);
            if(aktualny!=katsamochodow[wybor-1].pocz)
                aktualny->LP=aktualny->pop->LP+1L; //zwiekszenie numeru dango samochodu
            //w tych strukturach dane np. typu unsigned short nie sa inicjalizowane zerem, wiec trzeba
            //zwieszyc LP. korzystajac z poprzedniej struktury
            aktualny->NAPRAWYPOCZ=NULL;//na poczatek przypisuje NULL nowej naprawie
            aktualny->NAPRAWYOST=NULL;
            break;
        }else
        {
            fputs("error: Niepoprawne dane\n", stderr);
            continue;
        }
    }
    return 0;
}

int dodnap()//zwraca 1 gdy blad alokacji pamieci dla pierwszego katalogu, 2 gdy blad alokacji pamieci dla nowego samochodu
{//0 gdy powodzenie
    unsigned long wybor;// tablica przechowujaca rozkazy uzytkownika
    naprawy *aktualny;

    if(ilekatnap==0L)//jesli nie ma zadnego katalogu samochodu to trzeba go uprzednio dodac
        if(dodkatnap())return 1;//jesli blad alokacji pamieci dla ppierwszego katalogu

    while(1)
    {
        fputs("W ktorym katalogu dodac naprawe ?wyswietl liste katalogow(0)", stdout);
        if(fscanf(stdin, "%ld", &wybor)!=1) while(fgetc(stdin)!='\n');
        fgetc(stdin);

        if(wybor==0L)
        {
            wypiszkatnap();
            if(fscanf(stdin, "%ld", &wybor)!=1) while(fgetc(stdin)!='\n');
            fgetc(stdin);
        }
        if(wybor<=ilekatnap && wybor>0L)
        {//tutaj czytanie samochodu do katalogu wybor-1
            if(katalognap[wybor-1].NAPRAWYPOCZ==NULL)//gdy w katalogu nie ma zadnej naprawy
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
            modyfikowanienapwkat(aktualny, stdin);

            if(aktualny!=katalognap[wybor-1].NAPRAWYPOCZ)
                aktualny->LP=aktualny->pop->LP+1L; //zwiekszenie numeru dango samochodu
            //w tych strukturach dane np. typu unsigned short nie sa inicjalizowane zerem, wiec trzeba
            //zwieszyc LP. korzystajac z poprzedniej struktury

            break;
        }else
        {
            fputs("error: Niepoprawne dane\n", stderr);
            continue;
        }
    }
    return 0;
}

int dodnapdosam()
{
    unsigned long wybor;//ktory samochod
    unsigned long ktory;//ktory katalog samochodow
    unsigned long ktorykatnap;//ktorykatalog
    unsigned long ktoranap;//ktora naprawa
    naprawy *aktualnynap;//zmienne do szukania napraw czy samochodow
    samochod *aktualny;
    naprawy *nowanap;//nowa naprawa w samochodzie
    bool end;

    if(ilekatsam==0L)//jesli nie ma zadnego katalogu samochodow to trzeba go uprzednio dodac
        if(dodkatsam())return 1;//jesli blad alokacji pamieci dla ppierwszego katalogu
    end=false;

    for(wybor=0; wybor<ilekatsam; wybor+=1)
    {//sprawdzamy czy istnieje jakis samochod jesli nie to trzeba go dodac
        if(katsamochodow[wybor].pocz!=NULL)
        {
            end=true;
            break;
        }
    }

    if(end==false)if(dodsam())return 2;

    if(ilekatnap==0L)//jesli nie ma zadnego katalogu napraw to trzeba go uprzednio dodac
        if(dodkatnap())return 3;//jesli blad alokacji pamieci dla pierwszego katalogu


    end=true;

    for(wybor=0L; wybor<ilekatnap; wybor+=1L)
    {//sprawdzamy czy istnieje jakas naprawa jesli nie to trzeba ja dodac
        if(katalognap[wybor].NAPRAWYPOCZ!=NULL)
        {
            end=false;
            break;
        }
    }
    if(end)if(dodnap())return 4;

    while(1)
    {
        end=true;

        fprintf(stdout, "W ktorym (najpierw nr. katalogu potem samochodu) ?Wyswietl liste katologow i samochody(0)");

        komenda2(&ktory);

        if(ktory==0L)
        {
            wypiszsamikatsam();

            komenda2(&ktory);//ktory katalog samchodow
        }

        if(ktory<=ilekatsam && ktory>0L)//tutaj jesli uzytkownik wpisze numer istniejacego katalogu samochodow
        {
            komenda2(&wybor);//ktory samochod

            if(katsamochodow[ktory-1L].pocz!=NULL && katsamochodow[ktory-1L].ost->pop->LP>=wybor && wybor>0L)//tutaj jesli istnieje samochod
            {
                for(aktualny=katsamochodow[ktory-1].pocz; aktualny!=katsamochodow[ktory-1].ost; aktualny=aktualny->next)
                if(aktualny->LP==wybor)
                {
                    end=false;
                    break;//szukamy elementu o podanym numerze
                }
                if(end)break;

                end=true;

                fprintf(stdout, "Ktora naprawe (najpierw nr. katalogu potem naprawy) ?Wyswietl liste katologow i naprawy(0)");

                komenda2(&ktorykatnap);
                if(ktorykatnap==0L)
                {
                    wypisznapikatnap();
                    komenda2(&ktorykatnap);
                }

                if(ktorykatnap<=ilekatnap && ktorykatnap>0L)//tutaj jesli uzytkownik wpisze numer istniejacego katalogu napraw
                {
                    komenda2(&ktoranap);
                    if(katalognap[ktorykatnap-1L].NAPRAWYPOCZ!=NULL && katalognap[ktorykatnap-1L].NAPRAWYOST->pop->LP>=ktoranap && ktoranap>0L)//tutaj jesli istnieje naprawa
                    {
                        for(aktualnynap=katalognap[ktorykatnap-1L].NAPRAWYPOCZ; aktualnynap!=katalognap[ktorykatnap-1].NAPRAWYOST; aktualnynap=aktualnynap->next)
                        {
                            if(aktualnynap->LP==ktoranap)
                            {
                                end=false;
                                break;
                            }
                        }
                        if(end)break;
                    }else break;
                    //***********************************************************
                    if(aktualny->NAPRAWYPOCZ==NULL)//gdy w samochodzie nie ma ¿adnej naprawy
                    {
                        if((aktualny->NAPRAWYPOCZ=malloc(sizeof(naprawy)))==NULL) return 5;//alokacja o rozmiarze zmiennej
                        //naprawy, a nie naprawy* - to wskaznik a wskaznik ma duzo mniejszy rozmiar
                        if((aktualny->NAPRAWYOST=malloc(sizeof(naprawy)))==NULL) return 5;
                        //utworzenie listy
                        aktualny->NAPRAWYPOCZ->next=aktualny->NAPRAWYOST;
                        aktualny->NAPRAWYOST->pop=aktualny->NAPRAWYPOCZ;
                        aktualny->NAPRAWYPOCZ->pop=NULL;
                        aktualny->NAPRAWYOST->next=NULL;

                        nowanap=aktualny->NAPRAWYPOCZ;//operujemy na nowej naprawie
                        nowanap->LP=1L;//zerujemy numer naprawy tak aby po dodaniu wynosil 1 potem 2 itd.
                    }else
                        {// gdy juz lista jest utworzona dodajemy na jeden przed ostatnim nowy
                            if((nowanap=malloc(sizeof(naprawy)))==NULL) return 2;//tu jest blad
                            nowanap->next=aktualny->NAPRAWYOST;
                            nowanap->pop=aktualny->NAPRAWYOST->pop;
                            nowanap->pop->next=nowanap;
                            nowanap->next->pop=nowanap;
                        }

                    strcpy(nowanap->nazwa, aktualnynap->nazwa);
                    nowanap->iloscgodz=aktualnynap->iloscgodz;

                    if(nowanap!=aktualny->NAPRAWYPOCZ)
                        nowanap->LP=nowanap->pop->LP+1L; //zwiekszenie numeru danej naprawy
                    //w tych strukturach dane np. typu unsigned short nie sa inicjalizowane zerem, wiec trzeba
                    //zwieszyc LP. korzystajac z poprzedniej struktury

                    break;
                }
            }else continue;
        }
    }
    return 0;

}

bool dodkatnap()//zwraca jeden gdy blad alokacji dla katalogu, 0 gdy powodzenie
{
    fputs("Dodajesz nowy katalog napraw.", stdout);
    if((katalognap=realloc(katalognap, sizeof(*katalognap)*(ilekatnap+1L)))==NULL)
    {
        perror("error:");
        return true;
    }

    modyfikowaniekatnap(ilekatnap, stdin);

    katalognap[ilekatnap].numer=ilekatnap+1L;//zwiekszam numer katalogu

    katalognap[ilekatnap].NAPRAWYPOCZ=NULL;//dla listy przypisuje NULL na koncu i poczatku
    katalognap[ilekatnap].NAPRAWYOST=NULL;

    ilekatnap+=1L;//zwiekszamy liczbe katalogow samochodow

    return false;
}
