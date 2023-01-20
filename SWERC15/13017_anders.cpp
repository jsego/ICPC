
#include <iostream>
#include <set>

using namespace std;

int main() {
	int N, T, s;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		multiset<long long> M;
		for (int i = 0; i < N; ++i) {
			cin >> s;
			M.insert(s);
		}
		
		long long res = 0;
		while (1 < M.size()) {
			long long a = *M.begin();
			M.erase(M.begin());
			long long b = *M.begin();
			M.erase(M.begin());
			res += a + b;
			M.insert(a + b);
		}
		cout << res << "\n";
	}
}
