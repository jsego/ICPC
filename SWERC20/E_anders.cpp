
#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, N;
	for (c = 1000000; cin >> N; c = 1000000) {
		for (int i = 0; i < N; ++i) cin >> a >> b, c = min(b / a, c);
		cout << c << "\n";
	}
}

