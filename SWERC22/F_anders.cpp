
#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> G[51];
	int B, K, N, M, T, U[1225], V[1225];
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= N; ++i) G[i].clear();
		for (int i = 0; i < M; ++i)
			cin >> U[i] >> V[i], G[U[i]].push_back(V[i]), G[V[i]].push_back(U[i]);
		
		for (set<int> X, Y{1}, Z{1}; Y.size(); Y = X, X.clear())
			for (auto y : Y)
				for (int j = 0; j < G[y].size(); ++j)
					if (Z.find(G[y][j]) == Z.end()) K = G[y][j], X.insert(K), Z.insert(K);
		
		B = G[K].size() + 1 < N, cout << (B ? 2 : 3) << "\n";
		for (int i = 0; i < M; ++i) {
			if (U[i] == K) swap(U[i], V[i]);
			cout << (i ? " " : "") << (V[i] != K ? 1 : B || 1 < U[i] ? 2 : 3);
		}
		cout << "\n";
	}
}

