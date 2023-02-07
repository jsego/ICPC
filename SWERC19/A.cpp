
#include <bits/stdc++.h>

#define SQ(a) (a) * (a)

using namespace std;

typedef pair<unsigned, unsigned> Pair;

Pair A[1002];
vector<Pair> G[1002], Z[1002];
unsigned l, m, n, B, N, T, C[101];

unsigned dist(unsigned a, unsigned b) {
	return ceil(sqrt(SQ(A[a].first - A[b].first) + SQ(A[a].second - A[b].second)));
}

void dijkstra() {
	set<Pair> S;
	S.insert({0, 0});
	Z[0].push_back({0, 0});
	while (S.size()) {
		Pair p = *S.begin();
		S.erase(S.begin());
		if (p.second == 1001) return;
		Pair q(p.first, 0);
		q = *lower_bound(Z[p.second].begin(), Z[p.second].end(), q);
		for (unsigned j = 0; j < G[p.second].size(); ++j) {
			unsigned v = G[p.second][j].first, d = dist(p.second, v);
			Pair r(q.first + d * C[G[p.second][j].second], q.second + d);
			if (r.second <= B && Z[v].size()) {
				unsigned i = lower_bound(Z[v].begin(), Z[v].end(), r) - Z[v].begin();
				if (!i || r.second < Z[v][i - 1].second) {
					auto k = Z[v].emplace(Z[v].begin() + i, r);
					for (++k; k != Z[v].end() && r.second <= k->second; ) {
						S.erase({k->first, v});
						k = Z[v].erase(k);
					}
					S.insert({r.first, v});
				}
			}
			else if (r.second <= B) {
				Z[v].push_back(r);
				S.insert({r.first, v});
			}
		}
	}
}

int main() {
	while (cin >> A[0].first >> A[0].second) {
		cin >> A[1001].first >> A[1001].second >> B >> C[0] >> T;
		for (int i = 1; i <= T; ++i) cin >> C[i];
		cin >> N;
		for (int i = 1; i <= N; ++i) {
			cin >> A[i].first >> A[i].second >> l;
			for (int j = 0; j < l; ++j)
				cin >> n >> m, G[i].push_back({n + 1, m}), G[n + 1].push_back({i, m});
			G[0].push_back({i, 0});
			G[i].push_back({1001, 0});
		}
		G[0].push_back({1001, 0});
		
		dijkstra();
		if (Z[1001].size()) cout << (int)Z[1001][0].first << "\n", Z[1001].clear();
		else cout << "-1\n";
		for (int i = 0; i <= N; ++i) G[i].clear(), Z[i].clear();
	}
}

