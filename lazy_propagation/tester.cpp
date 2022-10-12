#include <bits/stdc++.h>
#include "segtree.hpp"


#define NTESTS 150
#define NUPDATES 10

using namespace std;

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

void test_new_version(int n, Segtree segtree, vector<int> &arr){
    
    for(int i = 0; i < NTESTS; i++){
        
        int l = rand() % n, r = rand() % n;
        if(l > r) swap(l, r);

        int corr = find_max_range(l, r, arr);
        int mine = segtree.query(1, 0, n - 1, l, r);


        if(corr != mine){
            cout << "Wrong answer" << endl;
            cout << "L: " << l << " R: " << r << " Correct: " << corr << " Seg: " << mine <<  endl;        
        }
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
    segtree.build(1, 0, n - 1);
    test_new_version(n, segtree, arr);

    for(int i = 0; i < NUPDATES; i++){
        // Testing second version
        int l = rand() % n, r = rand() % n,  increment = get_random();

        cout << "L: " << l << " R: " << r << " Increment: " << increment << endl;
        segtree.update_range(1, 0, n - 1, l, r, increment);
        for(int i = l; i <= r; i++){
            arr[i] += increment;
        }
        test_new_version(n, segtree, arr);
    }


}



int main() {

    srand(time(NULL));
    test_case();
    return 0;

}
