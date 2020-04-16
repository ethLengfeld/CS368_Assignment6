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
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _SETUF_H_
#define _SETUF_H_

/*
 *
 *
 * 
*/ 
template<typename T>
class SetUF {

    class UnionFind<T>;

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
            this->parent = a.parent;
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
    if(this != &a) {
        value = a.value;
        rank = 0;
        this->parent = a.parent;
    }
    return *this;
}

#endif