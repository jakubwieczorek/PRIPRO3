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
extern size_t ilesam;


bool dodkatsam(FILE* file)//zwraca 1 gdy blad alokacji pamieci dla katalogu
{//0 gdy powodzenie
    if((katsamochodow=realloc(katsamochodow, sizeof(*katsamochodow)*(ilekatsam+1L)))==NULL)
    {
        perror("error:");
        return true;
    }

    modyfikowaniekatsam(ilekatsam, file);

    katsamochodow[ilekatsam].numer=ilekatsam+1L;

    katsamochodow[ilekatsam].pocz=NULL;
    katsamochodow[ilekatsam].ost=NULL;

    ilekatsam+=1L;//zwiekszamy liczbe katalogow samochodow

    return false;
}

int dodsam(int where, FILE *file)//zwraca 1 gdy blad alokacji pamieci dla pierwszego katalogu, 2 gdy blad alokacji pamieci dla nowego samochodu
{//0 gdy powodzenie
    int wybor;// tablica przechowujaca rozkazy uzytkownika
    samochod *aktualny;
	
	wybor=where;
	if(file==stdin);
	{
		check_int(&wybor, "W ktorym katalogu dodac samochod ?(Wyswietl liste katalogow 0):=>", 2, -1, ilekatsam+1);
     	   	if(wybor==0)
       		{
			wypiszkatsam();
        		check_int(&wybor, "W ktorym katalogu dodac samochod ?:=>", 2, 0, ilekatsam+1);
       		}
	}
	
        //tutaj czytanie samochodu do katalogu wybor-1
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
                    if((aktualny=malloc(sizeof(samochod)))==NULL) return 2;//tu jest blad alokacji
                    aktualny->next=katsamochodow[wybor-1].ost;
                    aktualny->pop=katsamochodow[wybor-1].ost->pop;
                    aktualny->pop->next=aktualny;
                    aktualny->next->pop=aktualny;
                }
		
            modyfikowaniesamwkat(aktualny, wybor, file);
            if(aktualny!=katsamochodow[wybor-1].pocz)
                aktualny->LP=aktualny->pop->LP+1L; //zwiekszenie numeru dango samochodu
            //w tych strukturach dane np. typu unsigned short nie sa inicjalizowane zerem, wiec trzeba
            //zwieszyc LP. korzystajac z poprzedniej struktury
            aktualny->NAPRAWYPOCZ=NULL;//na poczatek przypisuje NULL nowej naprawie
            aktualny->NAPRAWYOST=NULL;
    
	return 0;
}

int dodnap(int where, FILE* file)// 1 gdy blad alokacji pamieci dla nowej naprawy
{//0 gdy powodzenie
    int wybor;
    naprawy *aktualny;
	
	wybor=where;
	if(file==stdin)
	{
		check_int(&wybor, "W ktorym katalogu dodac naprawe ?(Wyswietl liste katalogow 0):=>", 2, -1, ilekatnap+1);
        	if(wybor==0L)
        	{
            		wypiszkatnap();
	    		check_int(&wybor, "W ktorym katalogu dodac naprawe ?:=>", 2, 0, ilekatnap+1);
		}
	}
        
	if(wybor<=ilekatnap && wybor>0L)
	{//tutaj czytanie samochodu do katalogu wybor-1
            if(katalognap[wybor-1].NAPRAWYPOCZ==NULL)//gdy w katalogu nie ma zadnej naprawy
            {
                if((katalognap[wybor-1].NAPRAWYPOCZ=malloc(sizeof(naprawy)))==NULL) return 1;//alokacja o rozmiarze zmiennej
                //samochod, a nie samochod* - to wskaznik a wskaznik ma duzo mniejszy rozmiar
                if((katalognap[wybor-1].NAPRAWYOST=malloc(sizeof(naprawy)))==NULL) return 1;
                //utworzenie listy
 
               katalognap[wybor-1].NAPRAWYPOCZ->next=katalognap[wybor-1].NAPRAWYOST;
                katalognap[wybor-1].NAPRAWYOST->pop=katalognap[wybor-1].NAPRAWYPOCZ;
                katalognap[wybor-1].NAPRAWYPOCZ->pop=NULL;
                katalognap[wybor-1].NAPRAWYOST->next=NULL;

                aktualny=katalognap[wybor-1].NAPRAWYPOCZ;//operujemy na aktualnym
                aktualny->LP=1L;//zerujemy numer samochodu tak aby po dodaniu wynosil 1 potem 2 itd.
            }else
                {// gdy juz lista jest utworzona dodajemy na jeden przed ostatnim nowy
                    if((aktualny=malloc(sizeof(naprawy)))==NULL) return 1;//tu jest alokacji
                    aktualny->next=katalognap[wybor-1].NAPRAWYOST;
                    aktualny->pop=katalognap[wybor-1].NAPRAWYOST->pop;
                    aktualny->pop->next=aktualny;
                    aktualny->next->pop=aktualny;
                }
            modyfikowanienapwkat(aktualny, file);

            if(aktualny!=katalognap[wybor-1].NAPRAWYPOCZ)
                aktualny->LP=aktualny->pop->LP+1L; //zwiekszenie numeru dango samochodu
            //w tych strukturach dane np. typu unsigned short nie sa inicjalizowane zerem, wiec trzeba
            //zwieszyc LP. korzystajac z poprzedniej struktury
	 }
	isnap++;
    return 0;
}

int dodnapdosam(int where, FILE *file, int ktoryp, int ktorykatnapp, int ktoranapp)
{
    int wybor;//ktory samochod
    int ktory;//ktory katalog samochodow
    int ktorykatnap;//ktorykatalog
    int ktoranap;//ktora naprawa
    naprawy *aktualnynap;//zmienne do szukania napraw czy samochodow
    samochod *aktualny;
    naprawy *nowanap;//nowa naprawa w samochodzie
 	
	wybor=where;
	ktory=ktoryp;
	ktorykatnap=ktorykatnapp;
	ktoranap=ktoranapp;
	
	if(file==stdin)
	{      
		check_int(&ktory, "W ktorym (najpierw nr. katalogu potem samochodu) ?Wyswietl liste katalogow i samochody(0)=>", 2, -1, ilekatsam+1);

        	if(ktory==0)
        	{
            		wypiszsamikatsam();

	    		check_int(&ktory, "W ktorym katalogu ?=>", 2, -1, ilekatsam+1);
        	}

		if(katsamochodow[ktory-1].pocz!=NULL) 
		{
	    
	    		check_int(&wybor, "W ktorym samochodzie ?=>", 2, 0, katsamochodow[ktory-1].ost->pop->LP+1);
    	    
               	 	for(aktualny=katsamochodow[ktory-1].pocz; aktualny!=katsamochodow[ktory-1].ost; aktualny=aktualny->next)
                	{
				if(aktualny->LP==wybor)	break;//szukamy elementu o podanym numerze
			}     	 
		}else 
		{puts("Brak samochodow w tym katalogu"); return 0;}

        	check_int(&ktorykatnap,"Ktora naprawe (najpierw nr. katalogu potem naprawy) ?Wyswietl liste katalogow i naprawy(0)=>", 2, -1, ilekatnap+1);
        
		if(ktorykatnap==0)
        	{
            		wypisznapikatnap();   
			check_int(&ktorykatnap,"Ktory katalog ?=>", 2, -1, ilekatnap+1);
	        }
	
		if(katalognap[ktorykatnap-1].NAPRAWYPOCZ!=NULL) 
		{
      	 		check_int(&ktoranap,"Ktora naprawa ?=>", 2, -1, katalognap[ktorykatnap-1].NAPRAWYOST->pop->LP+1);
			for(aktualnynap=katalognap[ktorykatnap-1L].NAPRAWYPOCZ; aktualnynap!=katalognap[ktorykatnap-1].NAPRAWYOST; 
			aktualnynap=aktualnynap->next)	
        	        {//szukanie naprawy
				if(aktualnynap->LP==ktoranap)	break;
               		}
		}else
		{puts("Brak napraw w tym katalogu"); return 0;}
        }
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
	isnap++;
    return 0;
}

bool dodkatnap(FILE* file)//zwraca jeden gdy blad alokacji dla katalogu, 0 gdy powodzenie
{
    fputs("Dodajesz nowy katalog napraw.", stdout);
    if((katalognap=realloc(katalognap, sizeof(*katalognap)*(ilekatnap+1L)))==NULL)
    {
        perror("error:");
        return true;
    }

    modyfikowaniekatnap(ilekatnap, file);

    katalognap[ilekatnap].numer=ilekatnap+1L;//zwiekszam numer katalogu

    katalognap[ilekatnap].NAPRAWYPOCZ=NULL;//dla listy przypisuje NULL na koncu i poczatku
    katalognap[ilekatnap].NAPRAWYOST=NULL;

    ilekatnap+=1L;//zwiekszamy liczbe katalogow samochodow

    return false;
}
