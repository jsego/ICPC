
#include <bits/stdc++.h>

using namespace std;

vector<int> G[100000];
int a, b, j, k, M, N, C[100000], P[100000];

int bfs(int n) {
	memset(C, -1, N * sizeof(int));
	C[n] = 0, P[0] = n, k = 1;
	for (j = 0; j < k; ++j)
		for (int m : G[P[j]])
			if (C[m] < 0) C[m] = C[P[j]] + 1, P[k++] = m;
	if (j < N) return -1;
	else return C[P[N - 1]];
}

int main() {
	while (cin >> N >> M) {
		for (int i = 0; i < N; ++i) G[i].clear();
		for (int i = 0; i < M; ++i)
			cin >> a >> b, G[a - 1].push_back(b - 1), G[b - 1].push_back(a - 1);
		
		int m = 0;
		for (int i = 0; 0 <= m && i < 20; ++i) {
			int r = bfs(rand() % N);
			if (m < r || r < 0) m = r;
		}
		cout << (m < 1 ? m : ceil(log2(m))) << "\n";
	}
}

