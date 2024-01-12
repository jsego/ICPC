
#include <bits/stdc++.h>

using namespace std;

int main() {
	int C[101], E[102][101], K, M, N, O[102][101], R, S, T;
	while (cin >> N >> M >> K) {
		R = 0, fill(&E[0][0], &E[N + 1][0], 1e9), fill(&O[0][0], &O[N + 1][0], 1e9);
		for (int i = 1; i <= N; ++i) cin >> C[i], E[i][i] = 0;
		for (int i = 1; i <= M; ++i) {
			cin >> S >> T;
			if (C[S] == C[T]) E[S][T] = E[T][S] = 1;
			else O[S][T] = O[T][S] = 1;
		}
		
		for (int k = 1; k <= N; ++k)
			for (int i = 1; i <= N; ++i)
				for (int j = 1; j <= N; ++j)
					E[i][j] = min(E[i][j], min(E[i][k] + E[k][j], O[i][k] + O[k][j])),
					O[i][j] = min(O[i][j], min(O[i][k] + E[k][j], E[i][k] + O[k][j]));
		
		for (int i = 1; i <= N; ++i)
			for (int j = 1; j <= N; ++j)
				S = min(min(O[i][j] + K, E[i][j] + K), (O[i][j] + E[i][j] + K) / 2), R = max(R, S);
		cout << R << "\n";
	}
}

