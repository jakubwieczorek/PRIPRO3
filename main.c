#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stdmoj.h"

katnapraw *katalognap;//katalogi napraw
katsam *katsamochodow;//katalogi samochodow

size_t ilekatnap;//zlicze katalogi napraw
size_t ilekatsam;//zlicza katalogi samochodow

void komenda(char *wybor)
{
    fgets(wybor, 3, stdin);
    if(wybor[1]!='\n') while(fgetc(stdin)!='\n');
}

void komenda2(unsigned long *wybor)
{
    while(fscanf(stdin, "%ld", wybor)!=1)while(fgetc(stdin)!='\n');
    while(fgetc(stdin)!='\n');
}

void menu(int condition)
{	
	
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf("& 1) dodac \"1\".\n");
	if(condition==1)
	{
		printf("& 2) wyswietlic \"2\"\n"); 
		printf("& 3) zmodyfikowac\"3\"\n");
		printf("& 4) usunac \"4\"\n");
		printf("& 5) posortowac \"5\"\n");
		printf("& 6) exportowac \"6\"\n");
	}
	printf("& 0) zakonczyc \"0\".\n");
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");

}

int main()
{
	int cond=0, choise;
	char choise_str[10];
        while(1)
        {
	    menu(cond);
 	    check_int(&choise, "=>", 2, -1, 7);
            
	    if(choise==1)
            {
                sterdod();
            } else
            if(choise==2)
            {
                sterwyp();
            }else
            if(choise==3)
            {
                stermod();
            }else
            if(choise==4)
            {
                sterusu();
            }else
            if(choise==5)
            {
                stersort();
            }else
	    if(choise==6)
            {
                expdobin();
            }else
            if(choise==0)
            {
                while(1)
                {
                   	check_str("Czy na pewno chcesz zakonczyc ?[y/n]:=>  ", choise_str, 10);
                    	if(choise_str[0]=='y') return 0; else
                    	if(choise_str[0]=='n') break;
                }
            }
        }

    return EXIT_SUCCESS;
}
