#include <bits/stdc++.h>


class Segtree {
/**
 * Implementation of a segment tree that for a given range [l, r] returns the maximal element in that range.
*/   
    public:
        Segtree();

    private:

        int n;                // Segtree size 
        vector<int> segtree;  // Segtree array
        vector<int> arr;      // Input array

        /**
        * Builds the segtree recursively by checking if current node is a leaf node, if so, 
        * returns the value of the input array at index l. Else, returns the max of the left and right child nodes.
        *
        * @param p is the segtree index of the current node.
        * @param l is the left bound for the range of the current node.
        * @param r is the right bound for the range of the current node.
        *
        * @return the value of the current node.
        */
        int build(int p, int l, int r);


        /**
        * Builds the segtree recursively by checking if current node is a leaf node, if so, 
        * returns the value of the input array at index l. Else, returns the max of the left and right child nodes.
        *
        * @param p is the segtree index of the current node.
        * @param l is the left bound for the range of the current node.
        * @param r is the right bound for the range of the current node.
        * @param i is the left bound for the query searching range.
        * @param j is the right bound for the query searching range.
        *
        * @return the maximal element in the [i, j] range.
        */
        int query(int p, int l, int r, int i, int j);
}