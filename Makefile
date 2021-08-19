
all: main

include $(wildcard *.d)
#include $(wildcard lib/*.d)

ECHO :=
CXX := clang++
CXXFLAGS := -std=c++11 \
            --write-dependencies
CXXLDFLAGS := -lSDL2

main: main.cpp Makefile
	$(ECHO)$(CXX) $(CXXFLAGS) main.cpp $(CXXLDFLAGS) -o main

