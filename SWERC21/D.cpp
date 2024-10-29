/*
 * D - Ice Cream Shop
 */
#include <bits/stdc++.h>

using namespace std;

int d, p, M, N, P[200000], X[200002];

int main() {
	while (cin >> N >> M) {
		for (int i = 0; i <  N; ++i) cin >> P[i];
		for (int i = 1; i <= M; ++i) cin >> X[i];
		sort(X + 1, X + M + 1), X[0] = -2e9, X[M + 1] = 2e9;

		map<int, long long> A;
		for (int i = 0; i < N; ++i) {
			p = lower_bound(X, X + M + 2, i * 100) - X;
			d = min(X[p] - i * 100, i * 100 - X[p - 1]);
			A[i * 100 - d] += P[i], A[i * 100 + d] -= P[i];
		}
		long long res = 0, sum = 0;
		for (auto &x : A) sum += x.second, res = max(res, sum);
		cout << res << "\n";
	}
}

