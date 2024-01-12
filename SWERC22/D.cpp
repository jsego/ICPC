
#include <bits/stdc++.h>

using namespace std;

int main() {
	int i, j, l, u[3], V[100001];
	while (cin >> u[0] >> u[1] >> u[2] >> l) {
		memset(V, 0, 4 * l + 4);
		
		// fill in slots 2, 3, 4
		for (i = 2; i < 5; ++i)
			if      (4 <= i && u[2]) V[i] = 4, --u[2];
			else if (3 <= i && u[1]) V[i] = 3, --u[1];
			else if (          u[0]) V[i] = 2, --u[0];
		
		// alternate 2 and 4
		for ( ; i <= l && u[0] && u[2]; --u[0], --u[2]) V[i++] = 2, V[i++] = 4;
		
		// finish 2
		for ( ; i <= l && u[0]; --u[0]) V[i++] = 2;
		
		// possibly insert 4 after (-, -, 4), (2, -, 4) or (-, 3, 4)
		if (i == 5 && (!V[2] || !V[3]) && u[2]) V[i++] = 4, --u[2];
		
		// finish 3
		for ( ; i <= l && u[1]; --u[1]) V[i++] = 3;
		
		// possibly insert 4 after (-, -, 4, 4) or (2, -, 4, 4)
		if (i == 6 && !V[3] && u[2]) V[i++] = 4, --u[2];
		
		// finish 4
		for (++i; i <= l && u[2]; ++i)
			for (int k = 0; k < 3 && u[2]; ++k) V[i++] = 4, --u[2];
		
		for (i = 2, j = 0; i <= l; ++i) if (V[i]) ++j;
		cout << j << "\n", memset(u, 0, 12);
		for (i = 2; i <= l; ++i)
			if (V[i]) {
				pair<int, int> p(-1, -1);
				for (j = 0; j < 3; ++j) if (u[j] <= i - V[i] && p.second < u[j]) p = {j, u[j]};
				cout << p.first + 1 << " " << i - V[i] << " " << i << "\n", u[p.first] = i;
			}
	}
}

