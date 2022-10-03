#include <bits/stdc++.h>
#include "vertex.hpp"
#include "segtree.hpp"


int main(){

    Vertex* version[MAXN];

    int n;
    cout << "Enter the number of elements in the array: " ;
    cin >> n;
    

    vector<int> arr(n);
    cout << "Enter the elements of the array: " ;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Segtree segtree(arr);

    // creating Version-0
	version[0] = segtree.build(0, n-1);

    cout << "O maior elemento do array é: " << segtree.query(version[0], 0, n-1, 0, n-1) << endl;

    version[1] = segtree.update(version[0], 0, n-1, n-1, 3);

    cout << "O maior elemento do array é: " << segtree.query(version[1], 0, n-1, 0, n-1) << endl;


    return 0;
}





// int main(int argc, char const *argv[])
// {
// 	int A[] = {1,2,3,4,5};
// 	int n = sizeof(A)/sizeof(int);

// 	for (int i=0; i<n; i++)
// 	arr[i] = A[i];

// 	// creating Version-0
// 	Vertex* root = new Vertex(NULL, NULL, 0);
// 	build(root, 0, n-1);

// 	// storing root node for version-0
// 	version[0] = root;

// 	// upgrading to version-1
// 	version[1] = new Vertex(NULL, NULL, 0);
// 	upgrade(version[0], version[1], 0, n-1, 4, 1);

// 	// upgrading to version-2
// 	version[2] = new Vertex(NULL, NULL, 0);
// 	upgrade(version[1],version[2], 0, n-1, 2, 10);

// 	cout << "In version 1 , query(0,4) : ";
// 	cout << query(version[1], 0, n-1, 0, 4) << endl;

// 	cout << "In version 2 , query(3,4) : ";
// 	cout << query(version[2], 0, n-1, 3, 4) << endl;

// 	cout << "In version 0 , query(0,3) : ";
// 	cout << query(version[0], 0, n-1, 0, 3) << endl;
// 	return 0;
// }