#ifndef VERTEX_H
#define VERTEX_H

#include <bits/stdc++.h>

using namespace std;

class Vertex {

    private:
        // stores max of the elements in range relative to the node
        int max_val;
        // stores the value to be added to the node
        int lazy;
        // pointer to left and right children
        Vertex *left, *right;

    public:
        Vertex(int val);
        Vertex(Vertex* l, Vertex* r);
        Vertex(Vertex* l, Vertex* r, int val);

    friend class Segtree;    //friend class
};

#endif