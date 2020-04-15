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

    friend class UnionFind<T>;

    private:
        T value;
        unsigned rank;
        SetUF *parent;

    public:
        SetUF(T v) :
            value(v),
            rank(0)
        {}

        SetUF(const SetUF &a);

        SetUF& operator=(const SetUF &a);

        operator T() const { return value; }

};

#endif