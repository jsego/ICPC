
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	long long n, A, B, X[3], Y[3], Z[3];
	while (cin >> n) {
		fill(X, X + 3, 0);
		fill(Y, Y + 3, 0);
		fill(Z, Z + 3, 0);
		
		for (int i = 0; i < n; ++i) {
			cin >> A;
			X[i % 3] += A;
		}
		for (int i = 0; i < n; ++i) {
			cin >> B;
			Y[i % 3] += B;
		}
		
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				Z[(i + j) % 3] += X[i] * Y[j];
				
		cout << Z[1] << " " << Z[2] << " " << Z[0] << "\n";
	}
}
