CC=gcc
CFLAGS=-g
LIBS=-lncurses
LIBPATH=-L/usr/lib/x86_64-linux-gnu/libncurses.so
TARGET=menu
UNAME_R=$(shell uname -r)

all: $(TARGET)

$(TARGET): menu.o main.o
ifeq ($(UNAME_R),*ARCH)
	$(CC) $(CFLAGS) -o $(TARGET) main.o menu.o $(LIBS)
else
	$(CC) $(CFLAGS) -o $(TARGET) main.o menu.o $(LIBPATH) $(LIBS)
endif
	$(RM) *.o

menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

clean:
	$(RM) $(TARGET) *.o
