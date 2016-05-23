FLAGS = -std=c99 -g -Wall -c
CC = gcc
LINK = gcc
OBJECTS = main.o check.o sterdod.o usuwanie.o stermod.o wypisywanie.o dodawanie.o modyfikowanie.o stersort.o sortowanie.o sterusu.o sterwyp.o dotxt.o
TARGET = main.out

$(TARGET): $(OBJECTS)
	$(LINK) -o $(TARGET) $(OBJECTS)
main.o: main.c stdmoj.h
	$(CC) $(FLAGS) -o main.o main.c 
check.o: check.c stdmoj.h
	$(CC) $(FLAGS) -o check.o check.c
sterdod.o: sterdod.c stdmoj.h
	$(CC) $(FLAGS) -o sterdod.o sterdod.c
usuwanie.o: usuwanie.c stdmoj.h
	$(CC) $(FLAGS) -o usuwanie.o usuwanie.c
stermod.o: stermod.c stdmoj.h
	$(CC) $(FLAGS) -o stermod.o stermod.c
wypisywanie.o: wypisywanie.c stdmoj.h
	$(CC) $(FLAGS) -o wypisywanie.o wypisywanie.c
dodawanie.o: dodawanie.c stdmoj.h
	$(CC) $(FLAGS) -o dodawanie.o dodawanie.c
modyfikowanie.o: modyfikowanie.c stdmoj.h
	$(CC) $(FLAGS) -o modyfikowanie.o modyfikowanie.c
stersort.o: stersort.c stdmoj.h
	$(CC) $(FLAGS) -o stersort.o stersort.c
sortowanie.o: sortowanie.c stdmoj.h
	$(CC) $(FLAGS) -o sortowanie.o sortowanie.c
sterusu.o: sterusu.c stdmoj.h
	$(CC) $(FLAGS) -o sterusu.o sterusu.c
sterwyp.o: sterwyp.c stdmoj.h
	$(CC) $(FLAGS) -o sterwyp.o sterwyp.c
dotxt.o: dotxt.c stdmoj.h
	$(CC) $(FLAGS) -o dotxt.o dotxt.c
clean:
	rm -v -f *.o
