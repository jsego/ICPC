
#include <iostream>
#include <map>

#define M 2147483647L

using namespace std;

int main() {
	int N, a, b;
	while (cin >> N) {
		map<pair<int, int>, long long> X, Y;
		cin >> a >> b;
		if (b < a) swap(a, b);
		X[make_pair(a, b)] = 1;
		for (int i = 1; i < N; ++i) {
			cin >> a;
			Y.clear();
			for (auto it = X.begin(); it != X.end(); ++it) {
				if (it->first.first < a) {
					pair<int, int> p(it->first.first, a);
					Y[p] = (Y[p] + it->second) % M;
				}
				if (a < it->first.second) {
					pair<int, int> p(a, it->first.second);
					Y[p] = (Y[p] + it->second) % M;
				}
			}
			X = Y;
		}
		
		long long res = 0;
		for (auto it = X.begin(); it != X.end(); ++it)
			res = (res + it->second) % M;
		cout << res << "\n";
	}
}
