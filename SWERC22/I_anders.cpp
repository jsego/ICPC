
#include <bits/stdc++.h>

using namespace std;

long long N, X[101], Y[101];

int ch(set<int> & s) {
	pair<int, long long> p(0, 1e18L);
	auto k = s.begin(), i = k++, j = k++;
	for (bool b = 1; b; i = j, j = k, ++k, b = i != s.begin(), k = k == s.end() ? s.begin() : k) {
		long long a = abs(X[*i] * (Y[*j] - Y[*k]) + X[*j] * (Y[*k] - Y[*i]) + X[*k] * (Y[*i] - Y[*j]));
		if (a < p.second) p = {*j, a};
	}
	return p.first;
}

int main() {
	while (cin >> N) {
		set<int> s;
		for (int i = 1; i <= N; ++i) cin >> X[i] >> Y[i], s.insert(i);
		if (N & 1) cout << "Beatrice\n" << flush, cin >> N, s.erase(N);
		else cout << "Alberto\n" << flush;
		while (3 < s.size()) N = ch(s), s.erase(N), cout << N << "\n" << flush, cin >> N, s.erase(N);
	}
}

