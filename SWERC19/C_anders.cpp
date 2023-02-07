
#include <bits/stdc++.h>

using namespace std;

bool B[1000001];

int main() {
	int N;
	string s;
	while (cin >> N) {
		fill(B, B + N + 1, 0);
		for (int i = 0; i < N; ++i) {
			cin >> s;
			if (s[0] != '-' && s.size() < 7) B[atoi(s.c_str())] = 1;
		}
		
		int lo = 0;
		while (B[lo]) lo++;
		cout << lo << "\n";
	}
}

