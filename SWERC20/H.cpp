
#include <bits/stdc++.h>

using namespace std;

struct node;

typedef node * Ptr;
typedef pair<int, Ptr> Pair;

char C;
string S;
int D, N, X;
Ptr P[100001], Q[100001];

struct node {
	int g, v;
	Ptr d, r;
	node(node *n) : g(n->g), v(n->v), d(n->d), r(n->r) {}
	node(int k, int x, Ptr m, Ptr n) : g(k), v(x), d(m), r(n) {}
	Pair insert(int x) {
		if (r && r->v < x) {
			r = new node(r);
			Pair p = r->insert(x);
			return {p.first < 0 ? p.first : p.first + g, p.second};
		}
		if (d) {
			d = new node(d);
			Pair p = d->insert(x);
			bool b = 0 < p.first && (double)rand() / RAND_MAX < 0.5;
			if (b) r = new node(g - p.first + 1, x, p.second, r), g = p.first;
			else ++g;
			return {b ? p.first : -1, r};
		}
		r = new node(1, x, d, r);
		return {1, r};
	}
	int index(int x) {
		if (r && r->v <  x) return g + r->index(x);
		if (r && r->v == x) return g;
		if (d) return d->index(x);
		return 1;
	}
};

struct skiplist {
	Ptr h, m, n;
	skiplist() : h(new node(1, 0, 0, 0)) {}
	void raise() {
		h = new node(h->g, h->v, h, 0);
		for (n = h->d->r, m = h; n; n = n->r)
			if ((double)rand() / RAND_MAX < 0.5)
				m->r = new node(n->g, n->v, n, 0), m = m->r;
			else m->g += n->g;
	}
	void insert(int x) {
		h = new node(h), h->insert(x);
		if (log2(++h->v) == floor(log2(h->v))) raise();
	}
};

int main() {
	while (cin >> N >> ws) {
		skiplist add, del;
		P[0] = add.h, Q[0] = del.h;
		for (int i = 1; i <= N; ++i) {
			getline(cin, S);
			stringstream ss(S);
			while (ss >> C >> X)
				if (C == '-') del.insert(X);
				else add.insert(X);
			P[i] = add.h, Q[i] = del.h;
		}
		
		int res = 0;
		for (int i = 0; i < N; ++i)
			cin >> D, res = (N + res + P[D]->v - Q[D]->v - P[D]->index(res) + Q[D]->index(res)) % N;
		cout << res << "\n";
	}
}

