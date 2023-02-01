
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, long long> Pair;
typedef vector<pair<int, Pair> > Vec;

Pair operator+(const Pair & p, const Pair & q) {
	return {p.first + q.first, p.second + q.second};
}

bool operator<(const Pair & p, const Pair & q) {
	return p.first < q.first || p.first == q.first && q.second < p.second;
}

int B, N;
Vec V[10000];
map<string, int> M;
Pair X[10001], Y[10001], Z[10000], P(1000000000, 0);

Pair rec(int k) {
	if (!V[k].size()) return Z[k] = {0, 0};
	if (Z[k] < P) return Z[k];
	for (unsigned i = 0; i < V[k].size(); ++i) {
		Pair p = rec(V[k][i].first) + V[k][i].second;
		if (p < Z[k]) Z[k] = p;
	}
	return Z[k];
}

int main() {
	int c, p;
	string s, t, u;
	while (cin >> B >> N) {
		M.clear();
		for (int i = 0; i < N; ++i) {
			cin >> s >> t >> u >> c >> p;
			auto j = M.find(s);
			if (j == M.end()) j = M.insert({s, M.size()}).first;
			auto k = M.find(t);
			if (k == M.end()) k = M.insert({t, M.size()}).first;
			V[j->second].push_back({k->second, {c, p}});
		}
		
		fill(Z, Z + M.size(), P);
		for (unsigned i = 0; i < M.size(); ++i)
			rec(i);

		int mx = 1;
		X[0] = Y[0] = {0, 0};
		for (unsigned i = 0; i < M.size(); ++i) {
			if (!V[i].size()) continue;
			V[i].clear();
			int j = 1, k = 0, my = 1;
			while (j < mx && k < mx) {
				if (X[j].first < X[k].first + Z[i].first) {
					if (Y[my - 1].second < X[j].second)
						Y[my++] = X[j];
					j++;
				}
				else if (X[k].first + Z[i].first < X[j].first) {
					if (Y[my - 1].second < X[k].second + Z[i].second)
						Y[my++] = X[k] + Z[i];
					k++;
				}
				else {
					long long res = max(X[j].second, X[k].second + Z[i].second);
					if (Y[my - 1].second < res)
						Y[my++] = {X[j].first, res};
					j++;
					k++;
				}
			}
			while (j < mx) {
				if (Y[my - 1].second < X[j].second)
					Y[my++] = X[j];
				j++;
			}
			while (k < mx && X[k].first + Z[i].first <= B) {
				if (Y[my - 1].second < X[k].second + Z[i].second)
					Y[my++] = X[k] + Z[i];
				k++;
			}
			mx = my;
			copy(Y, Y + my, X);
		}
		
		cout << X[mx - 1].second << "\n" << X[mx - 1].first << "\n";
	}
}
