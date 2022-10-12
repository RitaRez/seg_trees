#include <bits/stdc++.h>
#include "segtree.hpp"

using namespace std;

int main() {

  int n;
  cout << "Enter the number of elements in the array: ";
  cin >> n;

  vector<int> arr;
  cout << "Enter the elements of the array: ";
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    arr.push_back(v);
  }

  Segtree segtree(arr);
  segtree.build(1, 0, n - 1);

  int q;
  cout << "Enter the number of queries: ";
  cin >> q;
  while (q--) {
    int type;
    cout << "Enter the type of query (1 for update, 2 for query): ";
    cin >> type;
    if (type == 1) {
      int l, r, value;
      cout << "Enter the left bound, right bound and value: ";
      cin >> l >> r >> value;
      segtree.update_range(1, 0, n - 1, l, r, value);
    }
    else {
      int l, r;
      cout << "Enter the left bound and right bound: ";
      cin >> l >> r;
      cout << "The maximal element in the [" << l << ", " << r << "] range is " << segtree.query(1, 0, n - 1, l, r) << endl;
    }
  }

  return 0;
}
