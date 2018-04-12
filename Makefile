HEADERS = \public\battle.h \public\logo.h \public\map.h \public\player.h

all: main

main.o: main.c $(HEADERS)
    gcc -c main.c -o main.o

main: main.o
    gcc main.o -o main

clean:
    -rm -f main.o
    -rm -f main