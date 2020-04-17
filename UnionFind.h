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
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _UNIONFIND_H_
#define _UNIONFIND_H_

#include <vector>
#include <algorithm>
#include "SetUF.h"

/**
 * Class that will unionize sets
 * used in order to find cycles in 
 * graph.
**/
template<typename T>
class UnionFind {
    
    private:
        // A container to hold all singletons
        std::vector<SetUF<T>> sets;

    public:

        /**
        * Constructor that will add all singletons to
        * container set
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

        /**
        * Find the root the set to which
        * the argument node belongs to
        */
        SetUF<T>& find(T node);

        /**
        * Unionize the two sets based on rank.
        * Using two sets.
        */
        void unionOp(SetUF<T> &x, SetUF<T> &y);

        /**
        * Unionize the two sets based on rank.
        * Using generic node and specified set.
        * Use find() to get set of generic node.
        */
        void unionOp(T x, SetUF<T> &y);

        /**
        * Unionize the two sets based on rank.
        * Using specified set and generic node.
        * Use find() to get set of generic node.
        */
        void unionOp(SetUF<T> &x, T y);

        /**
        * Unionize the two sets based on rank.
        * Using two generic nodes.
        * Use find() to get set of generic node.
        */
        void unionOp(T x, T y);
};


template <typename T>
SetUF<T>& UnionFind<T>::find(T node) {
    SetUF<T> *x;

    // find node in set of singletons
    for(SetUF<T> &currNode : sets) {
        if(currNode.value == node) {
            x = &currNode;
            break;
        }
    }

    // find root
    SetUF<T>* root = x;
    while(root->parent != root) {
        root = root->parent;
    }

    // Path compression
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
    // union by rank algorithm
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