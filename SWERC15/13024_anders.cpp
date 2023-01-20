
#include <algorithm>
#include <iostream>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef long long T;
typedef pair<T, T> P;

T xp(P p, P q, P r) {
	return (q.X - p.X) * (r.Y - p.Y) - (r.X - p.X) * (q.Y - p.Y);
}

struct Vect {
	P p, q;
	T dist;
	Vect(P &a, P &b) {
		p = a;
		q = b;
		dist = (a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y);
	}
	bool operator<(const Vect &v) const {
		T t = xp(p, q, v.p);
		return t < 0 || t == 0 && dist < v.dist;
	}
};

vector<P> convexhull(vector<P> & v) {
	sort(v.begin(), v.end());
	vector<Vect> u;
	for (unsigned i = 1; i < v.size(); i++)
		u.push_back(Vect(v[i], v[0]));
	sort(u.begin(), u.end());
	
	vector<P> w(v.size(), v[0]);
	int j = 1; w[1] = u[0].p;
	for (unsigned i = 1; i < u.size(); i++) {
		T t = xp(w[j - 1], w[j], u[i].p);
		for (j--; t < 0 && j > 0; j--)
			t = xp(w[j - 1], w[j], u[i].p);
		j += t > 0 ? 2 : 1;
		w[j] = u[i].p;
	}
	w.resize(j + 1);
	return w;
}

bool inhull(P p, vector<P> & w) {
	if (w.size() < 3) return false;
	if (xp(w[0], w[1], p) < 0) return false;
	if (xp(w[0], w[w.size() - 1], p) > 0) return false;
	
	int lo = 1, hi = w.size() - 2;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (xp(w[0], w[mid], p) < 0) hi = mid - 1;
		else lo = mid;
	}
	return xp(w[lo], w[lo + 1], p) >= 0;
}

int main() {
	P p;
	int L, S;
	while (cin >> L) {
		vector<P> V(L);
		for (int i = 0; i < L; ++i)
			cin >> V[i].first >> V[i].second;
		vector<P> W = convexhull(V);
		
		cin >> S;
		int res = 0;
		for (int i = 0; i < S; ++i) {
			cin >> p.first >> p.second;
			if (inhull(p, W)) res++;
		}
		cout << res << "\n";
	}
}

