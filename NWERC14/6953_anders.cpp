
#include <iostream>

using namespace std;

#define ULL unsigned long long

ULL N, A[500001];
bool B[500001], Z[500001];
pair< bool, int > P[1000001];
int M, V[500001][2], S[500001];

int main() {
	char c;
	while ( cin >> N >> M ) {
		for ( int i = 1; i <= M; ++i ) {
			cin >> c >> V[i][0] >> V[i][1];
			B[i] = c == 'L';
			A[i] = Z[i] = 0;
		}

		// topological sort using a stack

		Z[0] = 1;
		int K = M, i = 0;
		P[0] = make_pair( 0, 1 );
		while ( i >= 0 ) {
			pair< bool, int > p = P[i--];
			if ( p.first ) S[--K] = p.second;
			else if ( !Z[p.second] ) {
				Z[p.second] = 1;
				P[++i] = make_pair( 1, p.second );
				if ( !Z[V[p.second][0]] ) P[++i] = make_pair( 0, V[p.second][0] );
				if ( !Z[V[p.second][1]] ) P[++i] = make_pair( 0, V[p.second][1] );
			}
		}

		// for each switch in topological order, count number of balls
		// note that loop starts at K! (if some switches are never visited)

		A[1] = N;
		for ( int i = K; i < M; ++i ) {
			ULL h = A[S[i]] / 2, r = A[S[i]] % 2;

			A[V[S[i]][0]] += h;
			A[V[S[i]][1]] += h;

			// if odd number, send last ball down correct way and flip switch

			if ( r ) {
				if ( B[S[i]] ) ++A[V[S[i]][0]];
				else ++A[V[S[i]][1]];
				B[S[i]] ^= 1;
			}
		}

		// print result

		for ( int i = 1; i <= M; ++i )
			cout << ( B[i] ? "L" : "R" );
		cout << "\n";
	}
}
