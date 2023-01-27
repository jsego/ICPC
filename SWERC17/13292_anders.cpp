
#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

typedef long long T;
typedef pair<T, T> P;

T xp(P p, P q, P r) {
	return (q.X - p.X) * (r.Y - p.Y) - (r.X - p.X) * (q.Y - p.Y);
}

T sqdist(P p, P q) {
	return (p.X - q.X) * (p.X - q.X) + (p.Y - q.Y) * (p.Y - q.Y);
}

struct Vect {
	P p, q;
	T dist;
	Vect(P &a, P &b) {
		p = a;
		q = b;
		dist = sqdist(a, b);
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

int main() {
	int N, R;
	while (cin >> N >> R) {
		vector<P> V(N);
		for (int i = 0; i < N; ++i)
			cin >> V[i].first >> V[i].second;
		
		double W = 2 * R;
		vector<P> U = convexhull(V);
		for (unsigned i = 0; i < U.size(); ++i) {
			int lo = 1, hi = U.size() - 1;
			while (lo < hi) {
				int mid = (lo + hi) / 2;
				T x = U[i].X + U[(i + mid + 1) % U.size()].X - U[(i + mid) % U.size()].X;
				T y = U[i].Y + U[(i + mid + 1) % U.size()].Y - U[(i + mid) % U.size()].Y;
				P p(x, y);
				if (xp(U[i], U[(i + 1) % U.size()], p) > 0) lo = mid + 1;
				else hi = mid;
			}
			double d = xp(U[i], U[(i + 1) % U.size()], U[(i + lo) % U.size()]);
			d /= sqrt(sqdist(U[i], U[(i + 1) % U.size()]));
			if (d < W) W = d;
		}
		cout << setprecision(16) << W << "\n";
	}
}
