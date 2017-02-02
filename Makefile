CC = g++
CFLAGS = -Wall
stats: main.o stats.o
	$(CC) $(CFLAGS) -o stats main.o stats.o
main.o: main.cpp stats.h
	$(CC) $(CFLAGS) -c main.cpp
stats.o: stats.h
