
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Pair;

set<Pair> M;
vector<Pair> G[100000];
int a, b, l, I, L, S, U, C[100000];

void dijkstra() {
	set<Pair> S;
	S.insert({0, 0});
	fill(C, C + I, 1000000000);
	C[0] = 0;
	while (S.size()) {
		Pair p = *S.begin();
		S.erase(S.begin());
		if (U <= 2 * p.first) return;
		for (unsigned j = 0; j < G[p.second].size(); ++j) {
			Pair q(p.first + G[p.second][j].second, G[p.second][j].first);
			if (q.second < p.second) M.insert({q.second, p.second});
			else M.insert({p.second, q.second});
			if (q.first < C[q.second]) {
				S.erase({C[q.second], q.second});
				S.insert(q);
				C[q.second] = q.first;
			}
		}
	}
}

int main() {
	while (cin >> I >> S >> L >> U) {
		M.clear();
		for (int i = 0; i < S; ++i)
			cin >> a >> b >> l, G[a].push_back({b, l}), G[b].push_back({a, l});
		dijkstra();
		cout << M.size() << "\n";
		for (int i = 0; i < I; ++i) G[i].clear();
	}
}

