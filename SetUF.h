////////////////////////////////////////////////////////////////////////////////
// Main File: Graph.h, SetUF.h, UnionFind.h
// This File: SetUF.h
// Other Files: 	 Graph.h / SetUF.h / UnionFind.h / demo.cpp
// Semester:         CS 368 Spring 2020
//
// Author:           Ethan Lengfeld
// Email:            elengfeld@wisc.edu
// CS Login:         lengfeld
//
//
// Online sources:   https://beginnersbook.com/2017/09/friend-class-and-friend-functions/
//                   CS368-Templates Slides
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _SETUF_H_
#define _SETUF_H_

// #include "UnionFind.h"

template<typename T> class UnionFind;

/*
 *
 *
 * 
*/ 
template<typename T> 
class SetUF {

    friend class UnionFind<T>;

    private:
        T value;
        unsigned rank;
        SetUF *parent;

    public:
    	/*
        *
        */
        SetUF(T v) :
            value(v),
            rank(0),
            parent(this)
        {}

        /*
        *
        */
        SetUF(const SetUF &a){
            value = a.value;
            rank = 0;
            parent = this;
        }

        /*
        *
        */
        SetUF& operator=(const SetUF &a);

        /*
        *
        */
        operator T() const { return value; }

};

template<typename T>
SetUF<T>& SetUF<T>::operator=(const SetUF &a) {
    // std::cout << "this->value" << this->value << std::endl;
    // std::cout << "a.value" << a.value << std::endl;

    if(this != &a) {
        value = a.value;
        rank = 0;
        parent = this;
    }
    return *this;
}

#endif