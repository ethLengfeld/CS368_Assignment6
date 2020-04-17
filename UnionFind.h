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
// Online sources:   https://en.wikipedia.org/wiki/Disjoint-set_data_structure#Path_compression
//                   f
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _UNIONFIND_H_
#define _UNIONFIND_H_

#include <vector>
#include <algorithm>
#include "SetUF.h"


template<typename T>
class UnionFind {
    
    private:
        std::vector<SetUF<T>> sets;

    public:

        /*
        *
        */
        UnionFind(const std::vector<T> &singletons) {
            // add singletons to set
            std::vector<SetUF<T>>* newSet = new std::vector<SetUF<T>>;
            int size = singletons.size();
            
            for(int i = 0; i < size; i++) {
                newSet->push_back(singletons.at(i));
            }

            sets = *newSet;
        }

        /*
        *
        */
        SetUF<T>& find(T node);

        /*
        *
        */
        void unionOp(SetUF<T> &x, SetUF<T> &y);

        /*
        *
        */
        void unionOp(T x, SetUF<T> &y);

        /*
        *
        */
        void unionOp(SetUF<T> &x, T y);

        /*
        *
        */
        void unionOp(T x, T y);
};


template <typename T>
SetUF<T>& UnionFind<T>::find(T node) {
    SetUF<T> *x;

    for(SetUF<T> &currNode : sets) {
        if(currNode.value == node) {
            x = &currNode;
            break;
        }
    }

    // navigate to for loop
    SetUF<T>* root = x;
    while(root->parent != root) {
        root = root->parent;
    }

    SetUF<T> *parent;
    while(x->parent != root) { 
        parent = x->parent;
        x->parent = root;
        x = parent;
    }

    return *root;
}


template <typename T>
void UnionFind<T>::unionOp(SetUF<T> &x, SetUF<T> &y) {

    if(x == y) {
        return;
    }
    
    if(x.rank < y.rank) {
        y.parent = &x;
    }
    else if (x.rank == y.rank) {
        x.rank++;
        y.parent = &x;
    }
    else {
        x.parent = &y;
    }
}

template <typename T>
void UnionFind<T>::unionOp(T x, SetUF<T> &y) {
    SetUF<T> &xNode = find(x);
    unionOp(xNode, y);
}


template <typename T>
void UnionFind<T>::unionOp(SetUF<T> &x, T y) {
    SetUF<T> &yNode = find(y);
    unionOp(x, yNode);
}

template <typename T>
void UnionFind<T>::unionOp(T x, T y) {
    SetUF<T> &xNode = find(x);
    SetUF<T> &yNode = find(y);
    unionOp(xNode, yNode);
}

#endif