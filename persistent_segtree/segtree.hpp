#ifndef SEGTREE_H
#define SEGTREE_H

#include <bits/stdc++.h>
#include "vertex.hpp"

using namespace std;

#define MAXN 100

class Segtree {

    private:
        vector<int> arr;

    public:
        Segtree(vector<int> arr): arr(arr) {}

        /**
        * Builds the segtree recursively by checking if current vertex is a leaf, if so, 
        * returns the value of the input array at index l. Else, returns the max of the left and right child nodes.
        *
        * @param l is the left bound for the range of the current node.
        * @param r is the right bound for the range of the current node.
        *
        * @return the current node.
        */
        Vertex *build(int l, int r);


        /**
        * Upgrades the segtree rooted in vertex prev changing the value stored in position p for value "new_value".
        * Stores this new tree in the tree rooted in vertex cur. 
        * returns the value of the input array at index l. Else, returns the max of the left and right child vertices.
        *
        * @param prev is the root of the tree before the current update.
        * @param cur is the root of the updated tree.
        * @param l is the left bound for the range of the current vertex.
        * @param r is the right bound for the range of the current vertex.
        * @param p is the position to be changed in the update.
        * @param new_value is the value to be updated in p.
        *
        * @return the current vertex.
        */
        Vertex* update(Vertex *v, int l, int r, int p, int new_value);


        /**
        * Builds the segtree recursively by checking if current vertex is a leaf vertex, if so, 
        * returns the value of the input array at index l. Else, returns the max of the left and right child vertices.
        *
        * @param v is the current vertex.
        * @param l is the left bound for the range of the current vertex.
        * @param r is the right bound for the range of the current vertex.
        * @param ql is the left bound for the query searching range.
        * @param qr is the right bound for the query searching range.
        *
        * @return the maximal element in the [i, j] range.
        */
        int query(Vertex* v, int l, int r, int ql, int qr);
};

#endif
