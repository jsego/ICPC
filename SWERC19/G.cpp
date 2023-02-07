
#include <bits/stdc++.h>

using namespace std;

bool A[200][201];							// friends
map<string, int> M;							// species mapping
string s, t, T[200];						// species names
int L, N, S, B[200], I[100000], F[100000];	// best, initial, final

int main() {
	while (cin >> S >> L >> N) {
		for (int i = 0; i < S; ++i) cin >> T[i];
		sort(T, T + S);
		for (int i = 0; i < S; ++i) M[T[i]] = i;
		
		memset(A, 0, sizeof A);
		for (int i = 0; i < S; ++i) A[i][S] = 1;
		for (int i = 0; i < L; ++i) cin >> s >> t, A[M[s]][M[t]] = A[M[t]][M[s]] = 1;
		for (int i = 0; i < N; ++i) cin >> s, I[i] = M[s];
			
		for (int i = 0; i < S; ++i)
			for (B[i] = 0; B[i] < N && I[B[i]] != i && A[i][I[B[i]]]; ++B[i]);
		
		for (int i = 0, j, k; i < N; ++i) {
			for (j = 0, k = -1; k < 0; ++j)
				if (B[j] < N && I[B[j]] == j) k = j;
			
			F[i] = k, I[B[k]] = S;
			for (j = 0; j < S; ++j)
				for ( ; B[j] < N && I[B[j]] != j && A[j][I[B[j]]]; ++B[j]);
		}
		for (int i = 0; i < N; ++i) cout << (i ? " " : "") << T[F[i]];
		cout << "\n";
	}
}
