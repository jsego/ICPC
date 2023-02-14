
#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

string S;
pair<int, int> P;

void test(int n) {
	long long d = 1, r = 0;
	for (int i = 0; i < n; ++i)
		d = d * 26 % MOD, r = (26 * r + S[i] - 'A') % MOD;
	
	map<long long, pair<int, int> > M{{r, {1, 0}}};
	for (int i = n; i < S.size(); ++i) {
		r = (26 * r + (MOD - S[i - n] + 'A') * d + S[i] - 'A') % MOD;
		auto j = M.find(r);
		if (j != M.end()) ++j->second.first;
		else j = M.insert(M.begin(), {r, {1, i - n + 1}});
	}
			
	set<int> ix;
	for (auto i = M.begin(); i != M.end(); ++i)
		if (i->second.first == 1) ix.insert(i->second.second);
	if (ix.size()) P = {n, *ix.begin()};
}

int main() {
	while (cin >> S) {
		int e;
		P = {S.size(), 0};
		for (e = 1; P.first == S.size() && e < S.size(); e <<= 1) test(e);
		e >>= 1;
		if (P.first < S.size()) e >>= 1;
		
		int lo = e, hi = P.first;
		while (lo < hi) {
			long long mid = (lo + hi) / 2;
			test(mid);
			if (P.first == mid) hi = mid;
			else lo = mid + 1;
		}
		cout << S.substr(P.second, P.first) << "\n";
	}
}

