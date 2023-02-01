
#include <bits/stdc++.h>

using namespace std;

int M, N, U[2000], V, X[4000000];

int main() {
	while (cin >> N >> M) {
		for (int i = 0; i < N; ++i)
			cin >> U[i];
		
		int k = 0;
		for (int i = 0; i < M; ++i) {
			cin >> V;
			for (int j = 0; j < N && U[j] <= V; ++j)
				X[k++] = V - U[j];
		}
		sort(X, X + k);
		
		pair<int, int> best(0, 0);
		for (int i = 0, j; i < k; i = j) {
			for (j = i + 1; j < k && X[i] == X[j]; ++j);
			if (best.second < j - i) best = {X[i], j - i};
		}
		cout << best.first << "\n";
	}
}

