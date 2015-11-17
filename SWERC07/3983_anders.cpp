
#include <cmath>
#include <iostream>

using namespace std;

#define MIN( a, b ) ( a < b ? a : b )

int C, N, Z, A[100001], D[100001], E[100001], W[100001], X[100001], Y[100001];

int dist( int i, int j ) {
	return abs( X[i] - X[j] ) + abs( Y[i] - Y[j] );
}

int main() {
	cin >> Z;
	A[0] = D[0] = E[0] = W[0] = X[0] = Y[0] = 0;
	for ( int z = 1; z <= Z; ++z ) {
		cin >> C >> N;
		for ( int i = 1; i <= N; ++i ) {
			A[i] = 1000000000;
			cin >> X[i] >> Y[i] >> W[i];
			D[i] = dist( 0, i );
			E[i-1] = dist( i-1, i );

			int d = D[i], w = W[i];
			for ( int j = i; j > 0 && w <= C; --j, d += E[j], w += W[j] ) {
				int res = A[j-1] + d + D[j];
				A[i] = MIN( A[i], res );
			}
		}

		if ( 1 < z ) cout << "\n";
		cout << A[N] << "\n";
	}
}
