# Ethan Lengfeld
# 9074020836
# Makefile to compile Assignment 6 - Union Find code

CXX=g++
CXXFLAGS = -Wall
EXE = DemoUnionFind

all: demo.o InfiniteInt.o
	$(CXX) $(CXXFLAGS) -o $(EXE) demo.o InfiniteInt.o

InfiniteInt.o: InfiniteInt.cpp InfiniteInt.h
	$(CXX) $(CXXFLAGS) -c InfiniteInt.cpp

demo.o: demo.cpp InfiniteInt.h
	$(CXX) $(CXXFLAGS) -c demo.cpp

clean:
	-del demo.o
	-del InfiniteInt.o
	-del DemoUnionFind.exe