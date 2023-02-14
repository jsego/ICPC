
#include <bits/stdc++.h>

using namespace std;

int main() {
	int K, N;
	string S[100000];
	while (cin >> N >> K >> ws) {
		map<string, pair<int, int> > M;
		for (int i = 0; i < 3 * N; ++i) {
			getline(cin, S[i]);
			auto j = M.find(S[i]);
			if (j == M.end()) M[S[i]] = {1, i};
			else M[S[i]] = {j->second.first + 1, i};
		}
		
		vector<pair<int, int> > V;
		for (auto i = M.begin(); i != M.end(); ++i) V.push_back(i->second);
		sort(V.begin(), V.end());
		
		for (unsigned i = 1; i <= K && i <= V.size(); ++i)
			cout << S[V[V.size() - i].second] << "\n";
	}
}

