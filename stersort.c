#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

extern katnapraw *katalognap;//katalogi napraw
extern katsam *katsamochodow;//katalogi samochodow

extern size_t ilekatnap;//zlicze katalogi napraw
size_t ilekatsam;//zlicza katalogi samochodow

void stersort()
{
    unsigned long ktory;//ktorykatalog
    unsigned long ktorysam;//ktorysamochod
    unsigned long wgczego;//zmienna przechowujaca wybory uzytkownika
    unsigned long jak;//czy rosnaco czy malejaco
    char wybor[3]; // tablica przechowujaca rozkazy uzytkownika

    while(1)
    {
        fputs("samochody w katalogu(1), katalogi samochodow(2), katalogi napraw(3), naprawy w samochodzie(4)\nnaprawy w katalogu (5), ", stdout);
        fputs("wrocic(6)", stdout);

        komenda(wybor);

        if(strcmp(wybor,"1\n")==0)
        {
            fprintf(stdout, "W ktorym ?wypisz katalogi(0)");
            komenda2(&ktory);//ktory katalog
            if(ktory==0L)
            {
                if(ilekatsam==0L) continue;

                wypiszkatsam();
                komenda2(&ktory);
            }

            if(ktory<=ilekatsam && ktory>0L)//tutaj jesli uzytkownik wpisze numer istniejacego katalogu samochodow
            {
                puts("wg:\na) marki \"1\".\nb) modelu \"2\".\nc) roku \"3\".\nd) przebiegu \"4\".");
                puts("e) ilosci napraw wcisnij \"5\".");
                komenda2(&wgczego);//wgczego
                if(wgczego==1L || wgczego==2L || wgczego==3L || wgczego==4L || wgczego==5L)
                {
                    puts("rosnaco \"1\", malejaco \"2\".");
                    komenda2(&jak);
                    if(jak==1L || jak==2L)
                    {
                        sortowaniesamwkat(ktory-1, wgczego-1, jak-1);
                    }
                }
            }
        }else
        if(strcmp(wybor,"2\n")==0)
        {
            if(ilekatsam==0L) continue;

            puts("rosnaco \"1\", malejaco \"2\".");
            komenda2(&jak);
            if(jak==1L || jak==2L)
            {
                sortowaniekatsam(jak-1);
            }
        }else
        if(strcmp(wybor,"3\n")==0)
        {
            if(ilekatnap==0L) continue;

            puts("rosnaco \"1\", malejaco \"2\".");
            komenda2(&jak);
            if(jak==1L || jak==2L)
            {
                sortowaniekatnap(jak-1);
            }
        }else
        if(strcmp(wybor,"4\n")==0)
        {
            fprintf(stdout, "W ktorym (najpierw nr. katalogu potem samochodu) ?Wyswietl liste katologow i samochody(0)");
            komenda2(&ktory);

            if(ktory==0L)
            {
                wypiszsamikatsam();

                komenda2(&ktory);//ktory katalog
            }

            if(ktory<=ilekatsam && ktory>0L)//tutaj jesli uzytkownik wpisze numer istniejacego katalogu samochodow
            {
                komenda2(&ktorysam);//ktory samochod

                if(katsamochodow[ktory-1L].pocz!=NULL && katsamochodow[ktory-1L].ost->pop->LP>=ktorysam && ktorysam>0L)
                {
                    puts("wg nazw: rosnaco \"1\", malejaco \"2\".");
                    komenda2(&jak);
                    if(jak==1L || jak==2L)
                    {
                        sortowanienapwsam(ktory-1, ktorysam-1, jak-1);
                    }
                }
            }
        }else
        if(strcmp(wybor,"5\n")==0)
        {
            fprintf(stdout, "W ktorym ?wypisz katalogi(0)");
            komenda2(&ktory);//ktory katalog
            if(ktory==0L)
            {
                if(ilekatnap==0L) continue;

                wypiszkatnap();
                komenda2(&ktory);
            }

            if(ktory<=ilekatnap && ktory>0L)//tutaj jesli uzytkownik wpisze numer istniejacego katalogu napraw
            {
                puts("wg nazw: rosnaco \"1\", malejaco \"2\".");
                komenda2(&jak);
                if(jak==1L || jak==2L)
                {
                    sortowanienapwkat(ktory-1, jak-1);
                    break;
                }
            }
        }else
        if(strcmp(wybor,"6\n")==0)
        {
            return;
        }else
        {
            fprintf(stderr,"error: ZLA KOMENDA\n");
        }
    }
}
