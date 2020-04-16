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


template<typename T>
class UnionFind {
    
    private:
        std::vector<SetUF<T>> sets;

    public:

        /*
        *
        */
        UnionFind(const std::vector<T> &singletons) {
            // singletons
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
    // std::cout << "finding node" << std::endl; 
    // std::cout << "node= " << node << std::endl << std::endl;

    int size = sets.size();
    SetUF<T> foundNode = sets.at(0);
    
    for(int i = 0; i < size; i++) {
        if(node == sets.at(i)) {
            return sets.at(i);
        }
    }

    return foundNode;
}


template <typename T>
void UnionFind<T>::unionOp(SetUF<T> &x, SetUF<T> &y) {
    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;
}

template <typename T>
void UnionFind<T>::unionOp(T x, SetUF<T> &y) {
    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;
}


template <typename T>
void UnionFind<T>::unionOp(SetUF<T> &x, T y) {
    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;
}

template <typename T>
void UnionFind<T>::unionOp(T x, T y) {
    std::cout << "x=" << x << std::endl;
    std::cout << "y=" << y << std::endl;
} 



#endif