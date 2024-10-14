
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long A[302][302], H, K, N, X[301];
	while (cin >> N >> H) {
		fill(&A[0][0], &A[N + 1][0], 1e18L);
		for (int i = 1; i <= N; ++i) cin >> X[i], A[i][i] = H;
		for (int j = 1; j < N; ++j)
			for (int i = 1; i + j <= N; ++i) {
				K = min(H, (X[i + j] - X[i] - 1) / 2);
				for (int k = i; k < i + j; ++k)
					A[i][i + j] = min(A[i][i + j], A[i][k] + A[k + 1][i + j] - H + K);
			}
		cout << A[1][N] << "\n";
	}
}

