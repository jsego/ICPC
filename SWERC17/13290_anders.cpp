
#include <bits/stdc++.h>

using namespace std;

typedef map<pair<int, int>, int> Map;

int M, N;
pair<int, int> P[5001], Q[1000000];
string A[1001], B[1001];

int ladders(int i) {
	int n = 0;
	int j = B[i].find('|', 0);
	for ( ; j != string::npos; j = B[i].find('|', j + 1))
		for (int k = j; k != string::npos; k = B[i].find('|', k + 1))
			if (j < k || A[i - 1][j] == '-')
				Q[n++] = {j, k};
	return n;
}

bool free(int i, int j, int m) {
	if (i < j) return 1;
	pair<int, int> p(j, 0);
	auto k = lower_bound(P, P + m, p);
	return k == P + m || i < k->first;
}

pair<int, int> ival(int a, int b, int m) {
	if (b < a) swap(a, b);
	pair<int, int> p(a + 1, 0);
	pair<int, int> q(b, 0);
	auto i = lower_bound(P, P + m, p);
	auto j = lower_bound(P, P + m, q);
	return {P < --i ? --i - P : 0, j == P + m ? m - 1 : j - P};
}

int value(pair<int, int> & p, const pair<int, int> & q, int c, int m) {
	pair<int, int> r = ival(p.first, q.first, m);
	pair<int, int> s = ival(p.second, q.second, m);
	if (s.first <= r.second) return P[s.second].second - P[r.first].second;
	else return P[s.second].second - P[s.first].second + P[r.second].second - P[r.first].second;
}

int value(pair<int, int> & p, int m) {
	pair<int, int> q = ival(p.first, p.second, m);
	return P[q.second].second - P[q.first].second;
}

int main() {
	P[0] = {-1, 0};
	while (cin >> N >> M) {
		for (int i = 1; i <= N; ++i)
			cin >> A[i - 1] >> B[i];
		
		Map X;
		int n = ladders(N);
		for (int i = 0; i < n; ++i)
			X[Q[i]] = 0;
		
		for (int i = N - 1; i > 0; --i) {
			int j = A[i].find_first_not_of('-', 0), m = 1;
			for ( ; j != string::npos; j = A[i].find_first_not_of('-', j + 1))
				P[m++] = {j, P[m - 1].second + A[i][j] - '0'};
			
			Map Y;
			n = ladders(i);
			for (int j = 0; j < n; ++j) {
				if (Q[j].first < Q[j].second || A[i][Q[j].first] == '-') {
					int res = value(Q[j], m);
					for (auto k = X.begin(); k != X.end() && free(k->first.first, Q[j].second, m); ++k)
						if (free(Q[j].first, k->first.second, m)) {
							int val = value(Q[j], k->first, k->second, m);
							if (res < val + k->second) res = val + k->second;
						}
					Y[Q[j]] = res;
				}
				else Y[Q[j]] = A[i][Q[j].first] - '0';
			}
			X = Y;
		}
		
		int best = 0;
		for (auto k = X.begin(); k != X.end(); ++k)
			if (best < k->second) best = k->second;
		cout << best << "\n";
	}
}

