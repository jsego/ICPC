
#include <bits/stdc++.h>

#define MOD 1000000007L

using namespace std;

typedef pair<int, int> Pair;

Pair P[1000000];
long long C[1000001] = {1};
int K, L, N, S[20][1000000];

Pair xgcd(int a, int b) {
	if (b == 0) return {1, 0};
	else {
		Pair p = xgcd(b, a % b);
		return {p.second, p.first - a / b * p.second};
	}
}

void catalan() {
	for (int i = 0; i < 1000000; ++i) {
		Pair p = xgcd(MOD, i + 2);
		C[i + 1] = 2 * (2 * i + 1) * C[i] % MOD * (MOD + p.second) % MOD;
	}
}

Pair rec(Pair p, int a) {
	if (p.first == 0) {
		if (a + 1 < p.second) P[L++] = {a, p.second};
		return {p.second + 1, 1};
	}
	
	Pair q(a, 0);
	if (S[p.first - 1][p.second] == S[p.first][p.second])
		q = rec({p.first - 1, p.second}, a);
	if (S[p.first - 1][p.second + (1 << p.first - 1)] == S[p.first][p.second]) {
		Pair r = rec({p.first - 1, p.second + (1 << p.first - 1)}, q.first);
		q = {r.first, q.second + r.second};
	}
	return q;
}

long long num(int j) {
	Pair Q[20];
	int m = 1000001, c = P[j].first, k = 0;
	for (int i = K - 1; i >= 0; --i)
		if (1 << i <= P[j].second - c) {
			Q[k++] = {i, c};
			if (S[i][c] < m) m = S[i][c];
			c += 1 << i;
		}
	
	Pair p(P[j].first, 0);
	for (int i = 0; i < k; ++i)
		if (S[Q[i].first][Q[i].second] == m) {
			Pair q = rec(Q[i], p.first);
			p = {q.first, p.second + q.second};
		}
	if (p.first + 1 < P[j].second) P[L++] = {p.first, P[j].second};
	return C[p.second];
}

int main() {
	catalan();
	while (cin >> N) {
		L = 0;
		if (1 < N) P[L++] = {0, N};
		for (int j = 0; j < N; ++j) cin >> S[0][j];
		
		for (K = 1; 1 << K <= N; ++K)
			for (int j = 0; j + (1 << K) <= N; ++j)
				S[K][j] = min(S[K - 1][j], S[K - 1][j + (1 << K - 1)]);
		
		long long res = 1;
		for (int i = 0; i < L; ++i)
			res = (res * num(i)) % MOD;
		cout << res << "\n";
	}
}

