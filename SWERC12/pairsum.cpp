
#include <iostream>

#define M 1000000007
#define ULL unsigned long long

using namespace std;

int main() {
	int C, T, P[15], a[15];
	ULL A[1 << 15], B[1 << 15];

	cin >> T; // number of test cases

	for ( int i = 1; i <= T; ++i ) {

		cin >> C; // number of primes

		// compute res = [P0^0 + ... + P0^a0] * ... * [P(C-1)^0 + ... + P(C-1)^a(C-1)]
		ULL res = 1;

		// compute the sums and factors for each combination b0,...,b(C-1) of the primes
		A[0] = B[0] = 1;

		for ( int j = 0; j < C; ++j ) {

			cin >> P[j] >> a[j]; // the prime Pj and its exponent aj

			// compute part = [Pj^0 + ... + Pj^(aj-1)] and exp = Pj^aj
			ULL part = 0, exp = 1;
			for ( int k = 0; k < a[j]; ++k ) {
				part = ( part + exp ) % M;
				exp = ( exp * P[j] ) % M;
			}
			
			// for each combination b0,...,b(j-1) of the primes P0,...,P(j-1)
			for ( int k = 0; k < 1 << j; ++k ) {

				// for bj true, multiply sum by Pj^aj
				A[k | 1 << j] = ( A[k] * exp ) % M;

				// for bj true, multiply factor by (aj+1)
				B[k | 1 << j] = ( B[k] * ( a[j] + 1 ) ) % M;

				// for bj false, multiply sum by [Pj^0 + ... + Pj^(aj-1)]
				A[k] = ( A[k] * part ) % M;

				// for bj false, multiply factor by 1 (i.e. do nothing)

			}

			// complete the sum [Pj^0 + ... + Pj^aj] and update res
			part = ( part + exp ) % M;
			res = ( res * part ) % M;

		}

		// for each combination b0,...,b(C-1) of the primes (except all false)
		for ( int j = 1; j < 1 << C; ++j ) {

			// add sum*(factor-1) to the result
			res = ( res + A[j] * ( B[j] - 1 ) ) % M;

			//cout << j << ": " << A[j] << "," << B[j] << "\n";

		}

		// the number n appears one more time
		res = ( res + A[( 1 << C ) - 1] ) % M;

		cout << "Case " << i << ": " << res << "\n";

	}
}
