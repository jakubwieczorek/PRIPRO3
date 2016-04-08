main.out: main.o sterdod.o usuwanie.o dobinarnego.o stermod.o wypisywanie.o dodawanie.o modyfikowanie.o stersort.o sortowanie.o sterusu.o sterwyp.o
	gcc -o main.out main.o sterdod.o usuwanie.o dobinarnego.o stermod.o wypisywanie.o dodawanie.o modyfikowanie.o stersort.o sortowanie.o sterusu.o sterwyp.o
main.o: main.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o main.o main.c 
sterdod.o: sterdod.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o sterdod.o sterdod.c
usuwanie.o: usuwanie.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o usuwanie.o usuwanie.c
dobinarnego.o: dobinarnego.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o dobinarnego.o dobinarnego.c
stermod.o: stermod.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o stermod.o stermod.c
wypisywanie.o: wypisywanie.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o wypisywanie.o wypisywanie.c
dodawanie.o: dodawanie.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o dodawanie.o dodawanie.c
modyfikowanie.o: modyfikowanie.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o modyfikowanie.o modyfikowanie.c
stersort.o: stersort.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o stersort.o stersort.c
sortowanie.o: sortowanie.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o sortowanie.o sortowanie.c
sterusu.o: sterusu.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o sterusu.o sterusu.c
sterwyp.o: sterwyp.c stdmoj.h
	gcc -g -std=c99 -c -Wall -o sterwyp.o sterwyp.c
