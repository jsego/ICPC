
#include <algorithm>
#include <iostream>

#define MAX( a, b ) ( a < b ? b : a )
#define MIN( a, b ) ( a < b ? a : b )

using namespace std;

int A, B, M, c, z;
pair< int, int > P[10], Q[10];

int res() {
	// if only one machine, run in sequence
	if ( M == 1 ) return P[0].first * A + Q[0].first * B;

	// if different machines are fastest, run in parallel
	if ( P[0].second != Q[0].second ) return MAX( P[0].first * A, Q[0].first * B );

	// iterate over all possible options!
	int res = 2000000001;
	for ( int i = 0; i <= A; ++i ) {
		// first run i batches of process 1 on best machine
		int r = P[0].first * i;

		// compute number of times process 2 can run in parallel on Q[1].second
		int y = r / Q[1].first;

		// 1: run process 2 on Q[1].second for y steps
		int alt = r + MAX( P[1].first * ( A - i ), Q[0].first * ( B - y ) );
		res = MIN( res, alt );

		// 2: run process 2 on Q[1].second for ( y + 1 ) steps, possibly using P[2].second
		if ( y < B ) {
			int f = Q[1].first * ( y + 1 );
			int g = P[1].first * ( A - i ) + f - r;
			if ( i < B && M > 2 && P[1].second == Q[1].second )
				g = MIN( g, P[2].first + P[1].first * ( A - i - 1 ) );
			alt = MAX( r + g, f + Q[0].first * ( B - y - 1 ) );
			res = MIN( res, alt );
		}
	}
	for ( int i = 0; i <= B; ++i ) {
		// first run i batches of process 2 on best machine
		int r = Q[0].first * i;

		// compute number of times process 1 can run in parallel on P[1].second
		int y = r / P[1].first;

		// 1: run process 1 on P[1].second for y steps
		int alt = r + MAX( Q[1].first * ( B - i ), P[0].first * ( A - y ) );
		res = MIN( res, alt );

		// 2: run process 1 on P[1].second for ( y + 1 ) steps, possibly using Q[2].second
		if ( y < A ) {
			int f = P[1].first * ( y + 1 );
			int g = Q[1].first * ( B - i ) + f - r;
			if ( i < B && M > 2 && P[1].second == Q[1].second )
				g = MIN( g, Q[2].first + Q[1].first * ( B - i - 1 ) );
			alt = MAX( r + g, f + P[0].first * ( A - y - 1 ) );
			res = MIN( res, alt );
		}
	}
	return res;
}

int main() {
	cin >> z;
	for ( c = 0; c < z; ++c ) {
		cin >> A >> B >> M;
		for ( int i = 0; i < M; ++i ) {
			cin >> P[i].first;
			P[i].second = i;
		}
		for ( int i = 0; i < M; ++i ) {
			cin >> Q[i].first;
			Q[i].second = i;
		}

		// sort machines based on processing time for 1 and 2
		sort( P, P + M );
		sort( Q, Q + M );

		cout << res() << "\n";
	}
}
