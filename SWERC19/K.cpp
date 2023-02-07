
#include <bits/stdc++.h>

using namespace std;

vector<int> G[100001];
int a, b, M, N, T, B[100001];

int main() {
	while (cin >> N >> M >> T) {
		for (int i = 0; i < M; ++i)
			cin >> a >> b, G[b].push_back(a);
		
		set<int> V, W;
		fill(B, B + N, T), B[T] = N;
		for (unsigned i = 0; i < G[T].size(); ++i)
			V.insert(G[T][i]), B[G[T][i]] = G[T][i];
		
		while (V.size()) {
			W = V, V.clear();
			for (auto i = W.begin(); i != W.end(); ++i)
				for (unsigned j = 0; j < G[*i].size(); ++j)
					if (B[G[*i][j]] == T)
						V.insert(G[*i][j]), B[G[*i][j]] = B[*i];
					else if (B[G[*i][j]] != B[*i] && B[G[*i][j]] != N) {
						if (B[G[*i][j]] != G[*i][j]) V.insert(G[*i][j]);
						B[G[*i][j]] = N;
					}
		}
		
		int res = 0;
		for (int i = 0; i < N; ++i) if (B[i] == i) res++;
		cout << res << "\n";
		for (int i = 0; i < N; ++i) {
			G[i].clear();
			if (B[i] == i) cout << i << "\n";
		}
	}
}
