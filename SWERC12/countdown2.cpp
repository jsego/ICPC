
#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int C, K, T;
pair< int, int > B;
set< multiset< int > > S;
pair< int, pair< int, int > > U[6], V[6];

pair< int, int > best( multiset< int > &m ) {
	multiset< int >::iterator i = m.begin();
	pair< int, int > b( *i, abs( *i - T ) );
	for ( ++i; i != m.end(); ++i )
		if ( abs( *i - T ) < b.second )
			b = make_pair( *i, abs( *i - T ) );
	return b;
}

void rec( int k, multiset< int > &m ) {
	if ( S.find( m ) != S.end() ) return;
	else S.insert( m );

	pair< int, int > b = best( m );
	if ( b.second < B.second ) {
		B = b;
		K = k;
		copy( V, V + k, U );
	}

	for ( multiset< int >::iterator i = m.begin(), j; i != m.end(); ++i )
		for ( j = i, ++j; j != m.end(); ++j ) {
			V[k].second.first = *i;
			V[k].second.second = *j;
			for ( V[k].first = 0; V[k].first < 4; ++V[k].first ) {
				int res = 0;
				switch ( V[k].first ) {
					case 0: res = *i + *j; break;
					case 1: res = *i * *j; break;
					case 2: if ( *i < *j ) res = *j - *i; break;
					case 3: if ( *j % *i == 0 ) res = *j / *i; break;
				}

				if ( res ) {
					multiset< int > n( m );
					n.erase( n.find( *i ) );
					n.erase( n.find( *j ) );
					n.insert( res );
					rec( k + 1, n );
				}
			}
		}
}

int main() {
	int x;
	cin >> C;
	for ( int i = 0; i < C; ++i ) {
		multiset< int > m;
		for ( int j = 0; j < 6; ++j ) {
			cin >> x;
			m.insert( x );
		}
		cin >> T;
		cout << ( i ? "\n" : "" ) << "Target: " << T << "\n";

		S.clear();
		B = make_pair( 0, 1000000000 );
		rec( 0, m );

		for ( int j = 0; j < K; ++j ) {
			cout << U[j].second.second << " ";
			int res = 0;
			switch ( U[j].first ) {
				case 0: cout << "+"; res = U[j].second.second + U[j].second.first; break;
				case 1: cout << "*"; res = U[j].second.second * U[j].second.first; break;
				case 2: cout << "-"; res = U[j].second.second - U[j].second.first; break;
				case 3: cout << "/"; res = U[j].second.second / U[j].second.first; break;
			}
			cout << " " << U[j].second.first << " = " << res << "\n";
		}
		cout << "Best approx: " << B.first << "\n";
	}
}
