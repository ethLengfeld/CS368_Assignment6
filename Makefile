# Ethan Lengfeld
# 9074020836
# Makefile to compile Assignment 6 - Union Find code

CXX=g++
CXXFLAGS = -Wall
EXE = DemoUnionFind

all: demo.o
	$(CXX) $(CXXFLAGS) -o $(EXE) demo.o

demo.o:
	$(CXX) $(CXXFLAGS) -c demo.cpp Graph.h UnionFind.h SetUF.h

clean:
	-del demo.o
	-del DemoUnionFind.exe