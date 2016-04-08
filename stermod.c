#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"


extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
extern size_t ilekatsam;//zlicza katalogi samochodow

void stermod()
{
    char wybor[3]; // tablica przechowujaca rozkazy uzytkownika
    unsigned long ktory;//zmienna przechowujaca wybory uzytkownika
    unsigned long ktorysam;//zmienna przechowujaca wybory uzytkownika
    unsigned long ktoranap;//zmienna przechowujaca wybory uzytkownika
    unsigned long ktorykatnap;//zmienna przechowujaca wybory uzytkownika
    samochod *samo;//te dwie zmienne sluza do przekazywania odpowiedniego argumentu do funkcji modyfikujace, uzytkownik wpisuje numer typu unsugned long a nie samochod czy naprawa
    naprawy *napra;

    while(1)
    {
        fputs("samochod(1), katalog samochodow(2), naprawe w katalogu(3), katalog napraw(4),\n", stdout);
        fputs("wrocic(5)", stdout);
        komenda(wybor);
        if(strcmp(wybor,"1\n")==0)
        {
            fprintf(stdout, "Ktory (najpierw nr. katalogu potem samochodu) ?Wyswietl liste katologow i samochody(0)");

            komenda2(&ktory);

            if(ktory==0L)
            {
                wypiszsamikatsam();

                komenda2(&ktory);
            }

            if(ktory<=ilekatsam && ktory>0L)//tutaj jesli uzytkownik wpisze numer istniejacego katalogu samochodow
            {
                komenda2(&ktorysam);

                if(katsamochodow[ktory-1L].pocz!=NULL && katsamochodow[ktory-1L].ost->pop->LP>=ktorysam && ktorysam>0L)//tutaj jesli istnieje samochod
                {
                    for(samo=katsamochodow[ktory-1].pocz; samo!=katsamochodow[ktory-1].ost; samo=samo->next)
                    if(samo->LP==ktorysam)break;//szukamy elemnetu o podanym numerze
                    modyfikowaniesamwkat(samo, ktory-1, stdin);
                }
            }
        }else
        if(strcmp(wybor,"2\n")==0)
        {
            fprintf(stdout, "Ktory ?wypisz katalogi(0)");
            komenda2(&ktory);
            if(ktory==0L)
            {
                if(ilekatsam==0L) break;

                wypiszkatsam();
                komenda2(&ktory);
            }

            if(ktory<=ilekatsam && ktory>0L)//tutaj jesli uzytkownik wpisze numer istniejacego katalogu samochodow
            {
                modyfikowaniekatsam(ktory-1, stdin);
            }
        }else
        if(strcmp(wybor,"3\n")==0)
        {
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
                    for(napra=katalognap[ktorykatnap-1L].NAPRAWYPOCZ; napra!=katalognap[ktorykatnap-1].NAPRAWYOST; napra=napra->next)
                        if(napra->LP==ktoranap)break;
                    modyfikowanienapwkat(napra, stdin);
                }
            }
        }else
        if(strcmp(wybor,"4\n")==0)
        {
            fprintf(stdout, "Ktory ?wypisz katalogi(0)");
            komenda2(&ktory);
            if(ktory==0L)
            {
                if(ilekatnap==0L) break;

                wypiszkatnap();
                komenda2(&ktory);
            }

            if(ktory<=ilekatnap && ktory>0L)//tutaj jesli uzytkownik wpisze numer istniejacego katalogu napraw
                modyfikowaniekatnap(ktory-1, stdin);
        }else
        if(strcmp(wybor,"5\n")==0)
        {
            break;
        }else
        fprintf(stderr,"error: ZLA KOMENDA\n");
    }
}
