
#include <bits/stdc++.h>

using namespace std;

int main() {
	int A, B, K, M, N, X[100];
	for (A = K = 0; cin >> N >> M; A = K = 0) {
		for (int i = 0; i < N; ++i) cin >> X[i];
		sort(X, X + N);
		for (int i = 1; !K && i <= N; ++i) if (M / i < X[N - i]) K = X[N - i];
		cout << (K ? "Bernardo\n" : "Alessia\n") << flush;
		
		set<int> S{M + 1};
		for (int i = 1; i <= N; ++i, A = 0)
			if (K) cin >> A >> B, cout << (A < K ? B : (A + B - 1) / K * K) << "\n" << flush;
			else {
				for (auto j = S.begin(); *j - A <= X[N - i]; A = *j, ++j);
				cout << X[N - i] << " " << A + 1 << "\n" << flush, cin >> B, S.insert(B);
			}
	}
}

