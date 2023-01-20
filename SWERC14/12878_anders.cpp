
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int P, T;						// nodes and edges
int C[10000];					// cost of node
vector<pair<int,int>> G[10000];	// graph
vector<pair<int,int>> N[10000];	// incoming edges

void dijkstra() {
	fill(C, C + P, 1000000000);
	C[0] = 0;
	set<pair<int,int>> S;		// priority queue
	S.insert(make_pair(0, 0));
	while (S.size()) {
		int u = S.begin()->second;
		S.erase(S.begin());
		for (unsigned j = 0; j < G[u].size(); ++j) {
			int v = G[u][j].first;
			if (C[u] + G[u][j].second < C[v]) {
				S.erase(make_pair(C[v], v));
				C[v] = C[u] + G[u][j].second;
				S.insert(make_pair(C[v], v));
				N[v].clear();
				N[v].push_back(make_pair(u, G[u][j].second));
			}
			else if (C[u] + G[u][j].second == C[v])
				N[v].push_back(make_pair(u, G[u][j].second));
		}
	}
}

int main() {
	while (cin >> P >> T) {
		for (int i = 0; i < T; ++i) {
			int x, y, c;
			cin >> x >> y >> c;
			G[x].push_back(make_pair(y, c));
			G[y].push_back(make_pair(x, c));
		}

		dijkstra();
		
		int res = 0;
		set<int> S;
		S.insert(P - 1);
		vector<int> V(1, P - 1);
		for (unsigned i = 0; i < V.size(); ++i)
			for (unsigned j = 0; j < N[V[i]].size(); ++j) {
				int u = N[V[i]][j].first;
				res += 2 * N[V[i]][j].second;
				if (S.find(u) == S.end()) {
					S.insert(u);
					V.push_back(u);
				}
			}
		cout << res << "\n";
		
		for (unsigned i = 0; i < P; ++i) {
			G[i].clear();
			N[i].clear();
		}
	}
}

