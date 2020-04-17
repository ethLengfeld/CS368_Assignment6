////////////////////////////////////////////////////////////////////////////////
// Main File: Graph.h, SetUF.h, UnionFind.h
// This File: Graph.h
// Other Files: 	 Graph.h / SetUF.h / UnionFind.h / demo.cpp
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld (COMMENTS ONLY)
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <utility>
#include "UnionFind.h"

template<typename T> using Edge = std::pair<T, T>;

/**
 * Class that will build a grpah with 
**/
template<typename T>
class Graph {

	using Edge = std::pair<T, T>;

private:
	// store verticies in graph
	std::vector<T> vertices;
	// store edges between verticies
	std::vector<Edge> edges;

public:
	/**
	 * Constructor of graph with verticies and edges
	**/
	Graph(std::vector<T> v, std::vector<Edge> e) :
			vertices(v), edges(e) {
	}

	/**
	 * Add edge to graph
	**/
	void addEdge(Edge e) {
		edges.push_back(e);
	}
	;

	/*
	* Determine if given graph has a cycle.
	* For each edge find the set then root for each vertex
	* If the they are the same there is a cycle
	* Otherwise union together the two sets using
	* the union by rank algorithm
	*/
	bool containsCycle();
};


template<typename T>
bool Graph<T>::containsCycle() {
	UnionFind<T> uFind(vertices);
	for (Edge &e : edges) {
		SetUF<T> &xRoot = uFind.find(e.first);
		SetUF<T> &yRoot = uFind.find(e.second);
		if (xRoot == yRoot)
			return true;
		uFind.unionOp(xRoot, yRoot);
	}
	return false;
}

#endif
