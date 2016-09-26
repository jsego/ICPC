
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

#define TRIP( x, y, z ) make_pair( x, make_pair( y, z ) )
#define QUAD( v, w, y, z ) make_pair( make_pair( v, w ), make_pair( y, z ) )
#define V first.first
#define W first.second
#define X first
#define Y second.first
#define Z second.second

using namespace std;

typedef pair< int, int > P;
typedef pair< int, P > T;
typedef pair< P, P > Q;

int N;
vector< T > A[300];

T dijkstra( int s, int t, int n ) {
	set< Q > m;
	vector< vector< P > > z( N, vector< P >( N + 1, make_pair( 1000000000, 0 ) ) );
	z[s][0] = make_pair( 0, 0 );
	m.insert( QUAD( 0, 0, s, 0 ) );

	while ( m.size() ) {
		Q p = *m.begin();
		m.erase( m.begin() );
		if ( p.Y == t ) return TRIP( t, p.V, p.W );
		for ( unsigned i = 0; p.Z <= n && i < A[p.Y].size(); ++i ) {
			Q q = QUAD( p.V + A[p.Y][i].Y, p.W + A[p.Y][i].Z, A[p.Y][i].X, p.Z + 1 );
			if ( q.first < z[q.Y][q.Z] ) {
				m.erase( make_pair( z[q.Y][q.Z], make_pair( q.Y, q.Z ) ) );
				m.insert( q );
				//z[q.Y][q.Z] = q.first;
				for ( int j = q.Z; j <= min( N, n + 1 ); ++j )
					z[q.Y][j] = q.first;
			}
		}
	}
	return TRIP( -1, -1, -1 );
}

int main() {
	string s, t;
	bool b = true;
	int f, q, c, d;
	map< string, int > m;
	while ( cin >> N >> f >> q ) {
		if ( b ) b = false;
		else cout << ".\n";

		for ( int i = 0; i < N; ++i ) {
			cin >> s;
			m[s] = i;
		}
		for ( int i = 0; i < f; ++i ) {
			cin >> s >> t >> c >> d;
			A[m[s]].push_back( TRIP( m[t], c, d ) );
		}
		cin >> s;
		int orig = m[s];
		for ( int i = 0; i < q; ++i ) {
			cin >> s >> c;
			T res = dijkstra( orig, m[s], c );
			if ( res.Y < 0 ) cout << "* *\n";
			else cout << res.Y << " " << res.Z << "\n";
		}

		m.clear();
		for ( int i = 0; i < N; ++i )
			A[i].clear();
	}
}
