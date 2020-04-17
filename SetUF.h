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

// forward declaration
template<typename T> class UnionFind;

/**
 * Class to represent the set
 * for a union find
*/ 
template<typename T> 
class SetUF {

    friend class UnionFind<T>;

    private:
        // store generic value
        T value;
        // store the depth of a given set
        unsigned rank;
        // store the parent node of current node in set
        SetUF *parent;

    public:
    	/**
        * Constructor to store singleton value at root
        */
        SetUF(T v) :
            value(v),
            rank(0),
            parent(this)
        {}

        /**
        * Copy Constructor to store singleton value at root
        */
        SetUF(const SetUF &a) {
            value = a.value;
            rank = 0;
            parent = this;
        }

        /**
        * Copy Constructor to store singleton value at root
        */
        SetUF& operator=(const SetUF &a);

        /**
        * Conversion fucntion to cast class to generic value
        */
        operator T() const { return value; }

};

template<typename T>
SetUF<T>& SetUF<T>::operator=(const SetUF &a) {

    if(this != &a) {
        value = a.value;
        rank = 0;
        parent = this;
    }
    
    return *this;
}

#endif