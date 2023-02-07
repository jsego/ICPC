
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, P;
pair<ll, ll> A[1000];

ll xp(pair<ll, ll> & p, pair<ll, ll> & q) {
	return p.first * q.second - p.second * q.first;
}

ll area() {
	ll sum = 0;
	for (int i = 0; i < P; ++i)
		sum += xp(A[i], A[(i + 1) % P]);
	return abs(sum);
}

int main() {
	while (cin >> N) {
		ll res = 0;
		for (int i = 0; i < N; ++i) {
			cin >> P;
			for (int j = 0; j < P; ++j)
				cin >> A[j].first >> A[j].second;
			res += area();
		}
		cout << res / 2 << "\n";
	}
}

