
#include <bits/stdc++.h>

using namespace std;

int main() {
	int A[100000], B[100000], I, J, N, R, T, Z[100001];
	cin >> T;
	while (T--) {
		cin >> N, memset(Z, 0, 4 * N + 4);
		for (I = 0; I < N; ++I) cin >> A[I];
		for (J = 0; J < N; ++J) cin >> B[J];
		for (I = J = R = 0; J < N; ++J) {
			Z[B[J]] = 1;
			if (B[J] != A[I]) R = J + 1;
			while (I < N && Z[A[I]]) ++I;
		}
		cout << R << "\n";
	}
}

