
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	string s;
	while (cin >> N) {
		map<string, int> M;
		for (int i = 0; i < N; ++i) {
			cin >> s;
			M[s]++;
		}
		
		s = "NONE";
		for (auto i = M.begin(); i != M.end(); ++i)
			if (N < i->second * 2) s = i->first;
		cout << s << "\n";
	}
}

