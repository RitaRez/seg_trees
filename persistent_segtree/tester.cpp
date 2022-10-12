#include <bits/stdc++.h>
#include <random>

#include "vertex.hpp"
#include "segtree.hpp"

using namespace std;


#define NTESTS 5

int get_random(){
    return rand() % 100;
}


int find_max_range(int l, int r, vector<int> &arr){

    int m = 0;
    for(int i = l; i <= r; i++){
        m = max(m, arr[i]);
    }
    return m;
}

void test_new_version(int n, Segtree segtree, vector<int> &arr, int version){
    
    for(int i = 0; i < NTESTS; i++){
        
        int l = rand() % n, r = rand() % n;
        if(l > r) swap(l, r);

        int corr = find_max_range(l, r, arr);
        int mine = segtree.query(version, l, r);

        cout << "L: " << l << " R: " << r << " Correct: " << corr << " Seg: " << mine <<  endl;        

        if(corr != mine)
            cout << "Wrong answer" << endl;
    }
}

void test_case(){

    int n = 64;
    
    vector<int> arr;
    for(int i = 0; i < n; i++){
        arr.push_back(get_random());
    }

    // Testing first version
    Segtree segtree(arr);
	segtree.build();
    test_new_version(n, segtree, arr, 0);

    // Testing second version
    int p = rand() % n, new_value = get_random();
    cout << p << endl;
    segtree.update(p, new_value);
    arr[p] = new_value;
    test_new_version(n, segtree, arr, 1);

    // Testing third version
    p = rand() % n;
    new_value = get_random();
    cout << p << endl;
    segtree.update(p, new_value);
    arr[p] = new_value;
    test_new_version(n, segtree, arr, 2);
}


int main(){
    srand(time(NULL));
    test_case();
    return 0;
}
