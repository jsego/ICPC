
#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	string S;
	long long A, B, G, K, N, Q, X, Y;
	while (cin >> N >> S >> Q) {
		K = count(S.begin(), S.end(), '+'), K = min(K, N - K);
		for (int i = 0; i < Q; ++i) {
			cin >> A >> B, G = gcd(A, B), X = max(A, B) / G, Y = min(A, B) / G;
			if (2 * K == N) cout << "YES\n";
			else if (A == B) cout << "NO\n";
			else cout << ((N - 2 * K) % (X - Y) || K < (N - 2 * K) / (X - Y) * Y ? "NO\n" : "YES\n");
		}
	}
}

