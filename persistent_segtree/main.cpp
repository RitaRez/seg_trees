#include <bits/stdc++.h>
#include "vertex.hpp"
#include "segtree.hpp"

int main(){
    
    
    cout << "Enter the number of elements in the array: "; 
    int n; cin >> n;

    cout << "Enter the elements of the array: " ;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Segtree segtree(arr);

    // creating Version-0
	segtree.build();
    cout << "O maior elemento do array é: " << segtree.query(0, n-1) << endl;

    segtree.update(n-1, 3);

    cout << "O maior elemento do array é: " << segtree.query(0, n-1) << endl;


    return 0;
}