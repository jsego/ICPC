
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	int N, M;
	for (int t = 0; cin >> N >> M; ++t) {
		if (t) cout << "\n";
		if (M < N) swap(N, M);
		for (int i = N; i <= M; ++i)
			cout << i + 1 << "\n";
	}
}
