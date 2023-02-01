
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e+9;
int m, n, a[1001][1001], X[1001];
pair<int, int> R, B[1001], C[1001];

int man(pair<int, int> & p, pair<int, int> &q) {
	return abs(p.first - q.first) + abs(p.second - q.second);
}

// Hungarian algorithm
// 1-indexed!
// a can be negative, so min/max is easy :)
// requires n <= m
// Return value is the cost. The vector passed will contain the assignment.

int hungarian() {
    vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
    for(int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(m + 1, INF);
        vector<char> used(m + 1, false);
        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            for (int j = 1; j <= m; ++j)
                if (!used[j]) {
                    int cur = a[i0][j] - u[i0] - v[j];
                    if (cur < minv[j])
                        minv[j] = cur, way[j] = j0;
                    if (minv[j] < delta)
                        delta = minv[j], j1 = j;
                }
            for (int j = 0; j <= m; ++j)
                if (used[j])
                    u[p[j]] += delta, v[j] -= delta;
                else
                    minv[j] -= delta;
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    int out = 0;
    for (int j = 1; j <= m; ++j)
        out += a[p[j]][j];
    return out;
}

int main() {
	while (cin >> n >> m) {
		for (int i = 1; i <= n; ++i)
			cin >> B[i].first >> B[i].second;
		for (int j = 1; j <= m; ++j)
			cin >> C[j].first >> C[j].second;
		cin >> R.first >> R.second;
		
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			X[i] = man(R, B[i]);
			res += X[i];
		}
		
		int gm = INF;
		for (int i = 1; i <= n; ++i) {
			int tm = INF;
			for (int j = 1; j <= m; ++j) {
				int mh = man(B[i], C[j]);
				if (mh < tm) tm = mh;
				a[i][j] = min(X[i], mh);
			}
			
			int diff = max(0, tm - X[i]);
			if (diff < gm) gm = diff;
			
			for (int j = m + 1; j <= n; ++j)
				a[i][j] = X[i];
		}
		if (m < n) m = n;
		cout << res + hungarian() + gm << "\n";
	}
}
