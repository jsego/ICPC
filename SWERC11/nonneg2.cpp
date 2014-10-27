
#include <iostream>

using namespace std;

int main() {
	int n, A[1000001];
	bool B[1000001];
	for ( cin >> n; n > 0; cin >> n ) {
		for ( int i = 0; i < n; ++i ) {
			cin >> A[i];
			B[i] = 1;
		}

		bool loop = 1;
		// iterar en sentido contrario
		for ( int i = n - 1, j; loop && i >= 0; --i ) {
			if ( A[i] < 0 ) {
				// si encontramos un número negativo, iterar hasta que la suma sea positiva
				B[i] = 0;
				int res = A[i];
				for ( j = i - 1; res < 0 && j != i; --j ) {
					// posiblemente hay que seguir iterando una vez más desde el final
					if ( j < 0 ) {
						loop = 0;
						if ( i + 1 == n ) break;
						j = n - 1;
					}
					res += A[j];
					if ( res < 0 ) B[j] = 0;
				}
				i = j + 1;
			}
		}

		int res = 0;
		for ( int i = 0; i < n; ++i ) res += B[i];
		cout << res << "\n";
	}
}
