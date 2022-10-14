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

void Segtree::update_range(int ql, int qr, int new_value){
	Vertex* current = get_current();
	versions.push_back(update_range(current, 0, n-1, ql, qr, new_value));
}
Vertex * Segtree::update_range(Vertex *v, int l, int r, int ql, int qr, int value){
	
	// Se vértice atual for folha retornamos ele com incremento

	if(v->lazy != 0){
		Vertex *old_v = v;
		v = new Vertex(v->left, v->right, v->max_val + v->lazy);
		if(l != r){
			v->left->lazy += old_v->lazy;
			v->right->lazy += old_v->lazy;
		}
		old_v->lazy = 0;
	}

	if (l > r || l > qr || r < ql){
		return v;
	}
	// if (l == r){ 
	// 	return new Vertex(v->max_val + value);
	// }
	
	if (l >= ql && r <= qr) {
		v->max_val += value;
		if(l != r){
			v->left->lazy += value;
			v->right->lazy += value;
		}
		return v;
	}

	int mid = (l + r) / 2;
	Vertex *lv = new Vertex(update_range(v->left, l, mid, ql, qr, value), update_range(v->right, mid + 1, r, ql, qr, value));
	return lv;
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

	if(v->lazy != 0){
		v->max_val += v->lazy;
		if(l != r){
			v->left->lazy += v->lazy;
			v->right->lazy += v->lazy;
		}
		v->lazy = 0;
	}
	
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