
#include <iostream>

using namespace std;

int main() {
	int e;
	long long A[26][2], v[26];

	A[0][1] = 1;
	A[0][0] = 0;
	for ( e = 1; e < 26; ++e ) {
		if ( e % 2 ) {
			A[e][1] = 5*A[e-1][1];
			A[e][0] = 5*A[e-1][0];
		}
		else {
			A[e][1] = 3*A[e-1][1] + 2*A[e-1][0];
			A[e][0] = 2*A[e-1][1] + 3*A[e-1][0];
		}
	}

	long long in;
	for ( cin >> in; in >= 0; cin >> in ) {
		for ( e = 0; in > 0; ++e ) {
			v[e] = in % 5;
			in /= 5;
		}

		bool even = 1;
		long long res = 0;
		for ( --e; e >= 0; --e )
			for ( unsigned i = 0; i < v[e]; ++i ) {
				res += A[e][even];
				even ^= e % 2;
			}
		cout << res + even << "\n";
	}
}
