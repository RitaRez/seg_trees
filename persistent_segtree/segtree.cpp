#include <bits/stdc++.h>

#include "vertex.hpp"
#include "segtree.hpp"

using namespace std;

void Segtree::build(){
	versions.push_back(build(0, n-1));
}
Vertex * Segtree::build(int l, int r){
	if (l == r)
        return new Vertex(arr[l]);

	int m = (l + r) / 2;
    return new Vertex(build(l, m), build(m+1, r));
}


void Segtree::update(int p, int new_value){
	Vertex* current = get_current();
	versions.push_back(update(current, 0, n-1, p, new_value));
}
Vertex * Segtree::update(Vertex *v, int l, int r, int p, int new_value){
    if (l == r)
        return new Vertex(new_value);
	
	int m = (l + r) / 2;
	if (p <= m)
        return new Vertex(update(v->left, l, m, p, new_value), v->right);
    else
        return new Vertex(v->left, update(v->right, m+1, r, p, new_value));
}


int Segtree::query(int ql, int qr){
	Vertex* current = get_current();
	return query(current, 0, n-1, ql, qr);
}
int Segtree::query(int idx, int ql, int qr){
	Vertex* version = get_version(idx);
	return query(version, 0, n-1, ql, qr);
}
int Segtree::query(Vertex* v, int l, int r, int ql, int qr){

	if (ql > r or qr < l or l > r)
       return INT_MIN;

	if (ql <= l and r <= qr)
	    return v->max_val;
	
	int m = (l+r) / 2;
	return max(query(v->left, l, m, ql, qr), query(v->right, m+1, r, ql, qr));
}


Vertex* Segtree::get_current(){
	return versions.back();
}
Vertex* Segtree::get_version(int i){
	return versions[i];
}