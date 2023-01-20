
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Z[5001];
int A, B, E, P, x, y;
vector<int> V[5001], W[5001];

void rec(int i, vector<int> v[]) {
	if (Z[i]) return;
	Z[i] = 1;
	for (unsigned j = 0; j < v[i].size(); ++j)
		rec(v[i][j], v);
}

int main() {
	while (cin >> A >> B >> E >> P) {
		for (int i = 0; i < P; ++i) {
			cin >> x >> y;
			V[y].push_back(x);
			W[x].push_back(y);
		}
		
		int r = 0, s = 0, t = 0;
		for (int i = 0; i < E; ++i) {
			fill(Z, Z + E, 0);
			rec(i, W);
			int c = count(Z, Z + E, 1);
			if (E < A + c) r++;
			if (E < B + c) s++;
			
			fill(Z, Z + E, 0);
			rec(i, V);
			if (count(Z, Z + E, 1) > B) t++;
		}
		
		cout << r << "\n" << s << "\n" << t << "\n";
		
		for (int i = 0; i < E; ++i) {
			V[i].clear();
			W[i].clear();
		}
	}
}
