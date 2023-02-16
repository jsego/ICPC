
#include <bits/stdc++.h>

using namespace std;

int main() {
	int L, T, W;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> W >> L;
		set<int> S{1, 2};
		if (L < W) swap(L, W);
		for (int i = 1; i * i <= L; ++i) {
			if ((W - 2) % i == 0 && (L - 0) % i == 0) S.insert(i);
			if ((W - 1) % i == 0 && (L - 1) % i == 0) S.insert(i);
			if ((W - 0) % i == 0 && (L - 2) % i == 0) S.insert(i);
			if ((W - 2) % ((L - 0) / i) == 0 && (L - 0) % i == 0) S.insert((L - 0) / i);
			if ((W - 1) % ((L - 1) / i) == 0 && (L - 1) % i == 0) S.insert((L - 1) / i);
			if ((W - 0) % ((L - 2) / i) == 0 && (L - 2) % i == 0) S.insert((L - 2) / i);
		}
		cout << S.size();
		for (auto i = S.begin(); i != S.end(); ++i) cout << " " << *i;
		cout << "\n";
	}
}

