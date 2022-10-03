#include <bits/stdc++.h>
#include "segtree.h"

using namespace std;

int Segtree::build(int p, int l, int r){
    if(l == r)
        return segtree[p] = arr[l];
    
    int mid = (l + r) / 2;
    return segtree[p] = max((2 * p, l, mid), build(2 * p + 1, mid + 1, r));
}

int Segtree::query(int p, int l, int r, int i, int j){
    if(j < l or i > r)
        return -1;

    if(l >= i and r <= j)
        return segtree[p];

    int mid = (l + r) / 2;
    return max(query(2 * p, l, mid, i, j), query(2 * p + 1, mid + 1, r, i, j));
}


int main(){

    cout << "Enter the number of elements in the array: " ;
    cout >> n;

    return 0;
}