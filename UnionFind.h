////////////////////////////////////////////////////////////////////////////////
// Main File: Graph.h, SetUF.h, UnionFind.h
// This File: UnionFind.h
// Other Files: 	 Graph.h / SetUF.h / UnionFind.h / demo.cpp
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _UNIONFIND_H_
#define _UNIONFIND_H_

#include <vector>
#include "SetUF.h"

template <typename T>
class UnionFind { 

    private:
        std::vector<SetUF<T>> sets;

    public:
        UnionFind(const std::vector<T> &singletons);

        SetUF<T>& find(T node);

        void unionOp(SetUF<T> &x, SetUF<T> &y);

        void unionOp(T x, SetUF<T> &y);

        void unionOp(SetUF<T> &x, T y);

        void unionOp(T x, T y);
};




#endif