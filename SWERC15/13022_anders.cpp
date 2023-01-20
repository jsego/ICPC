
#include <iostream>
#include <set>

using namespace std;

typedef unsigned long long ULL;

int main() {
	set<ULL> S;
	for (int e = 1; e <= 64; ++e)
		for (int i = 1; i <= e; ++i) {
			int os = (i + 1) / 2;
			int zs = i / 2;
			if (i == 1) S.insert(((ULL)1 << e) - 1);
			else for (int j = 1; os * j + zs <= e; ++j)
				if ((e - os * j) % zs == 0) {
					ULL res = 0;
					for (int k = 0; k < os; ++k) {
						res = res << j | ((ULL)1 << j) - 1;
						if (k < zs) res <<= (e - os * j) / zs;
					}
					S.insert(res);
				}
		}
	
	ULL X, Y;
	while (cin >> X >> Y)
		cout << distance(S.upper_bound(0 < X ? X - 1 : 0), S.upper_bound(Y)) << "\n";
}
