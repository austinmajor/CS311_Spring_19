## A simple makefile

CC = g++
CFLAGS = -g -Wall -Wextra -Weffc++
PROG = ch09ex09

$(PROG): $(PROG).o Book.o Patron.o Library.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BINDIR)/$(PROG) $(PROG).o Book.o Patron.o Library.o

$(PROG).o: $(PROG).cpp Book.h Patron.h Library.h
	$(CC) $(CFLAGS) -c $(PROG).cpp

Book.o: Book.cpp Book.h
	$(CC) $(CFLAGS) $(LDFLAGS) -c Book.cpp

Patron.o: Patron.cpp Patron.h
	$(CC) $(CFLAGS) -c Patron.cpp

Library.o: Library.cpp Library.h
	$(CC) $(CFLAGS) -c Library.cpp
