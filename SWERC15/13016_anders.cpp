
#include <bits/stdc++.h>

using namespace std;

set<int> res;
int mask = (1 << 26) - 1;
vector<pair<string, int> > ones;

struct perm {
	int v[3];
	perm() : v{mask, mask, mask} {}
	perm(perm & p) : v{p.v[0], p.v[1], p.v[2]} {}
	bool mk(int i, int j) {
		v[(i + 1) % 3] &= mask ^ 1 << j;
		v[(i + 2) % 3] &= mask ^ 1 << j;
		return (v[0] | v[1] | v[2]) == mask;
	}
	bool rm(int i, int j) {
		v[i] &= mask ^ 1 << j;
		return (v[0] | v[1] | v[2]) == mask;
	}
	int fixed() {
		return ((v[1] | v[2]) ^ v[0]) & v[0];
	}
};

void rec(unsigned n, unsigned k, int x, perm & p) {
	if (n == 3)
		res.insert(x);
	else for (unsigned i = k; i < 26; ++i)
		if (p.v[0] >> i & 1 && (x >> i & 1) == 0)
			rec(n + 1, i + 1, x | 1 << i, p);
}

void rec(unsigned i, perm & p) {
	if (i == ones.size()) {
		int x = p.fixed(), n = 0;
		for (int j = 0; j < 26; ++j)
			if (x >> j & 1) ++n;
		if (n <= 3) rec(n, 0, x, p);
	}
	else for (int k = 0; k < 2; ++k) {
		perm q(p);
		bool b = 1;
		b = b && q.mk(ones[i].second, ones[i].first[k] - 'A');
		b = b && q.rm(ones[i].second, ones[i].first[1 - k] - 'A');
		if (b) rec(i + 1, q);
	}
}

int main() {
	string s;
	int N, x, y;
	while (cin >> N) {
		res.clear();
		ones.clear();
	
		perm p;
		bool b = 1;
		for (int i = 0; i < N; ++i) {
			cin >> s >> x >> y;
			if (s[1] < s[0]) swap(s[0], s[1]);
			if (y == 2) {
				b = b && p.mk(x, s[0] - 'A');
				b = b && p.mk(x, s[1] - 'A');
			}
			else if (!y) {
				b = b && p.rm(x, s[0] - 'A');
				b = b && p.rm(x, s[1] - 'A');
			}
			else ones.push_back({s, x});
		}
		
		if (b) {
			rec(0, p);
			cout << res.size() << "\n";
		}
		else cout << "0\n";
	}
}
