
#include <bits/stdc++.h>

using namespace std;

int main() {
	int A, B, N, R, T;
	cin >> T;
	for (cin >> N, B = R = 0; T--; cin >> N, B = R = 0) {
		for (int i = 1; i <= N; ++i) cin >> A, R += (A - B) / 120, B = A;
		cout << (R + (1440 - B) / 120 < 2 ? "NO\n" : "YES\n");
	}
}

