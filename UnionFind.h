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
        //SetUF<T>& findSetFromValue(T node);

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
    // std::cout << "node= " << node << std::endl;

    SetUF<T> x(node);//= findSetFromValue(node);

    for(SetUF<T> &currNode : sets) {
        if(currNode.value == x.value) {
            x = currNode;
            //return currNode;
            break;
        }
    }

// std::cout << "x = " << x << std::endl;



// std::cout << "x.parent->value = " << x.parent->value << std::endl;
    // if(x.parent->value != x.value) {
    //     SetUF<T> &temp = find(x.parent->value);
    //     x.parent = &temp;
    // }

    SetUF<T> root(x);
// std::cout << "root = " << root << std::endl;
// std::cout<< "here1"<<std::endl;
    while(*(root.parent) != root) {
        // SetUF<T> tt = *(root.parent);
        // std::cout<< "root.parent= "<< root.parent->value <<std::endl;
        // std::cout<< "here1.1"<<std::endl;
        root = *(root.parent);
        // std::cout<< "here1.2"<<std::endl;
    }
// std::cout<< "here2"<<std::endl;
    SetUF<T> parent(root);
    // std::cout << "x.parent->value= " << x.parent->value << std::endl;
    // std::cout << "root.value= " << root.value << std::endl;

    // while(x.parent->value != root.value) {
       while(*(x.parent) != root) { 
// std::cout<< "here3"<<std::endl;
        parent = *(x.parent);
// std::cout<< "here4"<<std::endl;
        x.parent = &root;
// std::cout<< "here5"<<std::endl;
        x = parent;
    // std::cout << "LOOP: x.parent->value= " << x.parent->value << std::endl;
    // std::cout << "LOOP: root.value= " << root.value << std::endl;
    }

    // std::cout << "root after= " << root.value << std::endl << std::endl;
    SetUF<T> *rootPtr = &root;
// std::cout<< "here6"<<std::endl;
    // return *(x.parent);
    // std::cout << "rootPtr->value=" << rootPtr->value << std::endl;
// std::cout<< "here7"<<std::endl;
    return *rootPtr;
}


template <typename T>
void UnionFind<T>::unionOp(SetUF<T> &x, SetUF<T> &y) {
    std::cout << "&x&y"<< std::endl;

    SetUF<T> xRoot = find(x.value);
    SetUF<T> yRoot = find(y.value);

    if(xRoot == yRoot) {
        return;
    }
    SetUF<T> tempRoot(xRoot);
    if(xRoot.rank < yRoot.rank) {
        xRoot = yRoot;
        yRoot = tempRoot;
    }
    yRoot.parent = &xRoot;
    if(xRoot.rank == yRoot.rank) {
        xRoot.rank++;
    }
}

template <typename T>
void UnionFind<T>::unionOp(T x, SetUF<T> &y) {
    std::cout << "x&y"<< std::endl;
    SetUF<T> xNode(x);
    SetUF<T> xRoot = find(xNode.value);
    SetUF<T> yRoot = find(y.value);

    // if(xRoot.value == yRoot.value) {
    if(xRoot == yRoot) {    
        return;
    }
    SetUF<T> tempRoot(xRoot);
    if(xRoot.rank < yRoot.rank) {
        xRoot = yRoot;
        yRoot = tempRoot;
    }
    yRoot.parent = &xRoot;
    if(xRoot.rank == yRoot.rank) {
        xRoot.rank++;
    }
}


template <typename T>
void UnionFind<T>::unionOp(SetUF<T> &x, T y) {
    std::cout << "&xy"<< std::endl;
    SetUF<T> yNode(y);
    SetUF<T> xRoot = find(x.value);
    SetUF<T> yRoot = find(yNode.value);

    if(xRoot == yRoot) {
        return;
    }
    SetUF<T> tempRoot(xRoot);
    if(xRoot.rank < yRoot.rank) {
        xRoot = yRoot;
        yRoot = tempRoot;
    }
    yRoot.parent = &xRoot;
    if(xRoot.rank == yRoot.rank) {
        xRoot.rank++;
    }
}

template <typename T>
void UnionFind<T>::unionOp(T x, T y) {
    std::cout << "xy"<< std::endl;
    SetUF<T> xNode(x);
    SetUF<T> yNode(y);
    SetUF<T> xRoot = find(xNode.value);
    SetUF<T> yRoot = find(yNode.value);

    if(xRoot == yRoot) {
        return;
    }
    SetUF<T> tempRoot(xRoot);
    if(xRoot.rank < yRoot.rank) {
        xRoot = yRoot;
        yRoot = tempRoot;
    }
    yRoot.parent = &xRoot;
    if(xRoot.rank == yRoot.rank) {
        xRoot.rank++;
    }
}

#endif