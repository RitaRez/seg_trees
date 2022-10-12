#include <bits/stdc++.h>
#include "segtree.hpp"

using namespace std;

Segtree::Segtree(vector<int> arr) {
    this->arr = arr;
    this->n = arr.size();
    this->lazy.resize(4 * n);
    this->segtree.resize(4 * n);
}

int Segtree::build(int p, int l, int r) {
    if (l == r)
        return segtree[p] = arr[l];

    int mid = (l + r) / 2;
    return segtree[p] = max(build(2 * p, l, mid), build(2 * p + 1, mid + 1, r));
}

void Segtree::update_range(int p, int l, int r, int ql, int qr, int value) {
    if (lazy[p] != 0) {
        segtree[p] += lazy[p];
        if (l != r) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    if (l > r || l > qr || r < ql)
        return;

    if (l == r) {
        segtree[p] += value;
        return;
    }

    if (l >= ql && r <= qr) {
        segtree[p] += value;
        lazy[2 * p] += value;
        lazy[2 * p + 1] += value;
        return;
    }

    int mid = (l + r) / 2;
    update_range(2 * p, l, mid, ql, qr, value);
    update_range(2 * p + 1, mid + 1, r, ql, qr, value);
    segtree[p] = max(segtree[2 * p], segtree[2 * p + 1]);
}

int Segtree::query(int p, int l, int r, int ql, int qr) {
    if (lazy[p] != 0) {
        segtree[p] += lazy[p];
        if (l != r) {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }

    if (qr < l or ql > r)
        return INT_MIN;

    if (l >= ql and r <= qr)
        return segtree[p];

    int mid = (l + r) / 2;
    return max(query(2 * p, l, mid, ql, qr), query(2 * p + 1, mid + 1, r, ql, qr));
}
