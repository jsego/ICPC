
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Pair;
typedef vector<Pair> Vec;

int x, y, z, N, T;
map<int, Vec> C, S;
vector<int> G[7200];

bool pass(Pair p, Vec v) {
	int k = v[0].second;
	if (p.second <= p.first)
		return pass({p.first, 360}, v) || p.second && pass({0, p.second}, v);
	if (p.first < v[0].first || v[v.size() - 1].second < p.second) return 1;
	for (unsigned i = 1; i < v.size(); k = v[i].second, ++i) 
		if (k < v[i].first && p.first < v[i].first && k < p.second) return 1;
	return 0;
}

bool bfs() {
	set<int> X;
	for (int i = 0; i < S.size(); ++i) X.insert(i);
	set<int> Y = X, Z;
	while (X.size()) {
		Z = X, X.clear();
		for (int x : Z) {
			if (C.size() * S.size() <= x) return 1;
			for (int y : G[x])
				if (Y.find(y) == Y.end()) X.insert(y), Y.insert(y);
		}
	}
	return 0;
}		

int main() {
	char c;
	cin >> T;
	while (T--) {
		cin >> N, C.clear(), S.clear();
		for (int i = 0; i < N; ++i) {
			cin >> c >> x >> y >> z;
			if (c == 'C' && y < z) C[x].push_back({y, z});
			else if (c == 'C') { C[x].push_back({y, 360}); if (z) C[x].push_back({0, z}); }
			else S[z].push_back({x, y});
		}
		if (!C.size()) { cout << "YES\n"; continue; }
		if (!S.size()) S[0].push_back({0, 0});
		
		for (auto &p : S) sort(p.second.begin(), p.second.end());
		
		int i = 0, o = 0;
		for (auto p = C.begin(); p != C.end(); ++i, o = p->first, ++p) {
			int j = 0, k = S.rbegin()->first;
			sort(p->second.begin(), p->second.end());
			for (auto q = S.begin(); q != S.end(); ++j, k = q->first, ++q) {
				if (pass({k, q->first}, p->second)) {
 					G[i * S.size() + j].push_back((i + 1) * S.size() + j);
					if (i && i + 1 < C.size()) G[(i + 1) * S.size() + j].push_back(i * S.size() + j);
				}
				if (i && pass({o, p->first}, q->second)) {
					G[i * S.size() + j].push_back(i * S.size() + (j + 1) % S.size()),
					G[i * S.size() + (j + 1) % S.size()].push_back(i * S.size() + j);
				}
			}
		}
		
		cout << (bfs() ? "YES\n" : "NO\n");
		
		for (int i = 0; i < C.size() * S.size(); ++i) G[i].clear();
	}
}

