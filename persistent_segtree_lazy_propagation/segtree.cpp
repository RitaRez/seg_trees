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
	
	cout << "L: " << l << " R: " << r << " max_value: " << v->max_val << endl;
	// Se vértice atual for folha retornamos ele com incremento
	if (l == r){ 
		return new Vertex(v->max_val + value);
	}
	if (l > r || l > qr || r < ql){
		return v;
	}
	Vertex *new_left = v->left;
	Vertex *new_right = v->right;
	int mid = (l + r) / 2;
	
	// Se os filhos forem lazy vai criar novos nós para versão atual
	if (v->left->lazy != 0) {
		//Copia criada com o update_range
		new_left = new Vertex(v->left->left, v->left->right, v->left->max_val + v->left->lazy);
		// Se o filho da esquerda não for uma folha
		if (l != mid){
			new_left->left->lazy += v->left->lazy;
			new_left->right->lazy += v->left->lazy;
		}
    }
	
	if (v->right->lazy != 0) {
		//Copia criada com o update_range
		new_right = new Vertex(v->right->right, v->right->right, v->right->max_val + v->right->lazy);
		// Se o filho da esquerda não for uma folha
		if ((mid + 1) != r){
			//Propagando o lazy pros filhos dos filhos
			new_right->left->lazy += v->right->lazy;
			new_right->right->lazy += v->right->lazy;
		}
    }

	if (l >= ql && r <= qr) {
		Vertex *new_v = new Vertex(new_left, new_right, v->max_val + value);
		new_left->lazy += value;
		new_right->lazy += value;
		return new_v;
	}

	return new Vertex(update_range(new_left, l, mid, ql, qr, value), update_range(new_right, mid + 1, r, ql, qr, value));
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
	Vertex *new_left = v->left;
	Vertex *new_right = v->right;
	
	// Se os filhos forem lazy vai criar novos nós para versão atual
	if (v->left->lazy != 0) {
		//Copia criada com o update_range
		new_left = new Vertex(v->left->left, v->left->right, v->left->max_val + v->left->lazy);
		// Se o filho da esquerda não for uma folha
		if (l != m){
			new_left->left->lazy += v->left->lazy;
			new_left->right->lazy += v->left->lazy;
		}
		v->left = new_left;
    }
	
	if (v->right->lazy != 0) {
		//Copia criada com o update_range
		new_right = new Vertex(v->right->right, v->right->right, v->right->max_val + v->right->lazy);
		// Se o filho da esquerda não for uma folha
		if ((m + 1) != r){
			//Propagando o lazy pros filhos dos filhos
			new_right->left->lazy += v->right->lazy;
			new_right->right->lazy += v->right->lazy;
		}
		v->right = new_right;
    }
	
	
	return max(query(v->left, l, m, ql, qr), query(v->right, m+1, r, ql, qr));
}


Vertex* Segtree::get_current(){
	return versions.back();
}
Vertex* Segtree::get_version(int i){
	return versions[i];
}