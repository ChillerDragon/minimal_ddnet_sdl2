all: main

ECHO :=
CC := clang
CCLDFLAGS := -lSDL2 -g

main: main.c Makefile
	$(ECHO)$(CC) $(CCFLAGS) main.c $(CCLDFLAGS) -o main

