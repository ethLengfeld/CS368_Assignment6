# Author: Ethan Lengfeld , elengfeld@wisc.edu
# CS368_Assignment6
Assignment 6 for CS 368: Learn a Programming Language C++

# Assignment 6: Union Find
The files in Assignment 6 consist of demo.cpp which is used as a test class to demo.

## To Compile and Run Program
1. To run the program add all files to the any same directory.
2. Navigate to the directory location and type the command 'make'
3. This will create an executable called 'DemoUnionFind'
4. Type 'DemoUnionFind' in command line and the program will execute.

## To Clean Program
To remove executable and any .o files run the command 'make clean' 
Warning! This will delete the executable and will require rerunning 'make' to retest it

## Code Organization
demo.cpp is the testing class with the main function that will determine
if given graphs have cycles.
graph.h contains code to build graphs complete with verticies and edges
To determine if cycles exist graph.h will utilize UnionFind.h and SetUF.h
UnionFind.h will unionize the sets store as SetUF objects and using union by rank
will determine if cycles exist.
