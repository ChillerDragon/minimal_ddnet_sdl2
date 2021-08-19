all: main

ECHO :=
CC := clang
CCLDFLAGS := -lSDL2

main: main.c Makefile
	$(ECHO)$(CC) $(CCFLAGS) main.c $(CCLDFLAGS) -o main

