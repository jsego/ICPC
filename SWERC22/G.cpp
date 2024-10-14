
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	string S;
	while (cin >> N >> S) {
		int c = count(S.begin(), S.begin() + N, 'W');
		map<int, int> M{{c, 1}};
		for (int i = 0; i + N < S.size(); ++i) c += S[i + N] == 'W', c -= S[i] == 'W', M[c]++;
		cout << M.rbegin()->first << "\n";
	}
}

