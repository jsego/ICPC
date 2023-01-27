
#include <bits/stdc++.h>

#define SIZE 256
#define MOD 1000000000
#define ULL unsigned long long

using namespace std;

int N, Z, Q[SIZE];
vector<int> V[SIZE];

struct mat {
	ULL a[SIZE][SIZE] = {};
	mat() {}
	mat(int x) {
		for (int i = 0; i < Z; i++) a[i][i] = x;
	}
	mat operator*(mat & m) {
		mat n;
		for (int i = 0; i < Z; i++)
			for (int j = 0; j < Z; j++)
				for (int k = 0; k < Z; k++)
					n.a[i][j] = (n.a[i][j] + a[i][k] * m.a[k][j]) % MOD;
		return n;
	}
};

mat expo(mat & m, ULL e) {
	if (e == 0) return mat(1);
	else {
		mat n = expo(m, e / 2);
		if (e % 2 > 0) return n * n * m;
		else return n * n;
	}
}

mat A, B;

int main() {
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < 8; ++j)
			if (i >> j == 0) {
				V[i].push_back(1 << j);
				if (j < 7) V[i].push_back(3 << j);
			}
	
	for (int i = 0; i < SIZE; ++i) {
		int n = 0;
		set<int > S;
		Q[n++] = 255 ^ i;
		S.insert(255 ^ i);
		A.a[i][255 ^ i] = 1;
		for (int j = 0; j < n; ++j) {
			int base = Q[j] ^ 255 ^ i;
			for (unsigned k = 0; k < V[base].size(); ++k)
				if ((V[base][k] & Q[j]) == 0) {
					int res = V[base][k] | Q[j];
					if (S.find(res) == S.end()) {
						S.insert(res);
						Q[n++] = res;
					}
					A.a[i][res] += A.a[i][Q[j]];
				}
		}
	}
	
	ULL M;
	while (cin >> N >> M) {
		Z = 1 << N;
		for (int i = 0; i < Z; ++i)
			for (int j = 0; j < Z; ++j)
				B.a[i][j] = A.a[256 - Z + i][j];
				
		ULL res = 0;
		mat C = expo(B, M - 1);
		for (int i = 0; i < Z; ++i)
			res = (res + B.a[Z - 1][i] * C.a[i][Z - 1]) % MOD;
		cout << res << "\n";
	}
}
