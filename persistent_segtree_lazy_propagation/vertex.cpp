#include <bits/stdc++.h>
#include "vertex.hpp"

using namespace std;

Vertex::Vertex(int val) : left(nullptr), right(nullptr), max_val(val) {}
Vertex::Vertex(Vertex* l, Vertex* r) : left(l), right(r), max_val(INT_MIN) {
    if (left) max_val = max(max_val, left->max_val);
    if (right) max_val = max(max_val, right->max_val);
}
Vertex::Vertex(Vertex* l, Vertex* r, int val) : left(l), right(r), max_val(val) {}
