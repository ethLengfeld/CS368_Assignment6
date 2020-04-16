# Ethan Lengfeld
# 9074020836
# Makefile to compile Assignment 6 - Union Find code

CXX=g++
CXXFLAGS = -Wall
EXE = DemoUnionFind

all: demo.o
	$(CXX) $(CXXFLAGS) -o $(EXE) demo.o

demo.o: demo.cpp Graph.h UnionFind.h SetUF.h
	$(CXX) $(CXXFLAGS) -c demo.cpp

clean:
	-del demo.o
	-del DemoUnionFind.exe