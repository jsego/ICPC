
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool B[10];
set<char> L;
string S[10];
int N, R, V[10][10], X[10];

int num(unsigned i) {
	int res = 0;
	for (unsigned j = 0; j < S[i].size(); ++j)
		res = 10 * res + X[V[i][j]];
	return res;
}

void perm(unsigned k) {
	if (k == L.size()) {
		bool b = 1;
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			b &= X[V[i][0]] > 0;	// first digit non-zero
			if (i + 1 < N) sum += num(i);
			else sum -= num(i);
		}
		if (b && !sum) R++;
	}
	else for (int d = 0; d < 10; ++d)
		if (B[d]) {
			B[d] = 0;
			X[k] = d;
			perm(k + 1);
			B[d] = 1;
		}
}

int main() {
	fill(B, B + 10, 1);
	while (cin >> N) {
		for (int i = 0; i < N; ++i) {
			cin >> S[i];
			L.insert(S[i].begin(), S[i].end());
		}
		
		for (int i = 0; i < N; ++i)
			for (unsigned j = 0; j < S[i].size(); ++j)
				V[i][j] = distance(L.begin(), L.find(S[i][j]));
		
		R = 0;
		perm(0);
		cout << R << "\n";
		
		L.clear();
	}
}

