
#include <iostream>
#include <set>

using namespace std;

int n, w, h, l;
pair<int, int> P[5];
string S[10], T = "X1234";

int encode() {
	int res = 0;
	for (int i = 1; i <= n; ++i)
		res = (res << 8) | (P[i].first * w + P[i].second);
	return res;
}

void decode(int x) {
	for (int i = n; i > 0; --i, x >>= 8) {
		int pos = x & 255;
		P[i] = make_pair(pos / w, pos % w);
	}
}

bool insert(set<int> & B, set<int> & C) {
	if (P[0] == P[1]) return 1;
	int x = encode();
	if (B.find(x) == B.end()) {
		B.insert(x);
		C.insert(x);
	}
	return 0;
}

bool move(int j, set<int> & B, set<int> & C) {
	bool b = 0;
	pair<int, int> q = P[j];
	
	for (--P[j].first; P[j].first >= 0 && S[P[j].first][P[j].second] == '.'; --P[j].first);
	if (++P[j].first < q.first) b |= insert(B, C);
	P[j] = q;
	
	for (++P[j].first; P[j].first < h && S[P[j].first][P[j].second] == '.'; ++P[j].first);
	if (q.first < --P[j].first) b |= insert(B, C);
	P[j] = q;
	
	for (--P[j].second; P[j].second >= 0 && S[P[j].first][P[j].second] == '.'; --P[j].second);
	if (++P[j].second < q.second) b |= insert(B, C);
	P[j] = q;
	
	for (++P[j].second; P[j].second < w && S[P[j].first][P[j].second] == '.'; ++P[j].second);
	if (q.second < --P[j].second) b |= insert(B, C);
	P[j] = q;
	
	return b;
}

int BFS() {
	set<int> A, B;
	A.insert(encode());
	B.insert(encode());
	for (int i = 0; i < l; ++i) {
		set<int> C;
		for (auto it = A.begin(); it != A.end(); ++it) {
			decode(*it);
			for (int j = 1; j <= n; ++j)
				S[P[j].first][P[j].second] = T[j];
			for (int j = 1; j <= n; ++j)
				if (move(j, B, C))
					return i + 1;
			for (int j = 1; j <= n; ++j)
				S[P[j].first][P[j].second] = '.';
		}
		A = C;
	}
	return 0;
}

int main() {
	while (cin >> n >> w >> h >> l) {
		for (int i = 0; i < h; ++i) {
			cin >> S[i];
			for (int j = 0; j <= n; ++j) {
				auto it = S[i].find(T[j]);
				if (it != string::npos) {
					P[j] = make_pair(i, it);
					S[i][it] = '.';
				}
			}
		}
		
		int res = BFS();
		if (res) cout << res << "\n";
		else cout << "NO SOLUTION\n";
	}
}
