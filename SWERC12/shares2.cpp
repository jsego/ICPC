
#include <iostream>
#include <map>

#define LL long long

using namespace std;

int main() {
	int k, x, N, P;
	LL y, C, V[501], W[501];

	while ( cin >> C >> N >> P ) {
		for ( int i = 1; i <= N; ++i )
			cin >> V[i] >> W[i];

		map< LL, LL > m;
		m[0] = 0;
		for ( int i = 0; i < P; ++i ) {
			cin >> k;
			LL A = 0, B = 0;
			map< LL, LL > n( m );
			for ( int j = 0; j < k; ++j ) {
				cin >> x >> y;
				A += y * V[x];
				B += y * ( W[x] - V[x] );
			}
			for ( map< LL, LL >::iterator j = n.begin(); j != n.end(); ++j ) {
				LL p = j->first + A;
				LL v = j->second + B;
				if ( p <= C ) {
					map< LL, LL >::iterator k = m.upper_bound( p );
					while ( k != m.end() && k->second < v ) m.erase( k++ );
					if ( (--k)->second < v ) m[p] = v;
				}
			}
		}
		cout << m.rbegin()->second << "\n";
	}
}
