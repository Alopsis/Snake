CC=gcc
OPTIONS=-Wall `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`  

main: divers.o update.o suivant.o main.o mlv.o
	$(CC) $(OPTIONS) divers.o update.o suivant.o main.o mlv.o  `pkg-config --libs-only-l MLV` -o main

main.o: main.c main.h
	$(CC) $(OPTIONS) -c main.c

divers.o: divers.c divers.h
	$(CC) $(OPTIONS) -c divers.c


update.o: update.c update.h
	$(CC) $(OPTIONS) -c update.c

suivant.o: suivant.c suivant.h
	$(CC) $(OPTIONS) -c suivant.c

mlv.o:	mlv.c mlv.h
	$(CC) $(OPTIONS) -c mlv.c 
clear:
	rm -r *.o

