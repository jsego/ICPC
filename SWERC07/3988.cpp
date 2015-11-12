#include <iostream>
#include <list>
#include <map>
#include <string>
#include<algorithm>

using namespace std;

typedef list< pair< int , int > > L;
typedef list< int >::iterator LI;
typedef map< string , int > M;

int main() {
	L v[ 2000 ];
	bool b[ 2000 ];
	int z, d[ 2000 ];
	cin >> z;
	for ( int ct = 1; ct <= z; ct++) {
		int n, p, a, c=0;
		string s, t;

		cin >> n >> p;
		M m;
		for (int i = 0; i < p; i++) {
			cin >> s >> t >> a;

			M::iterator f = m.find( s );
			if ( f == m.end() )
				f = m.insert( m.begin(), make_pair( s, c++ ) );

			M::iterator g = m.find( t );
			if ( g == m.end() )
				g = m.insert( m.begin(), make_pair( t, c++ ) );

			v[ f->second ].push_back( make_pair( g->second , a ) );
			v[ g->second ].push_back( make_pair( f->second , a ) );
		}

		d[ 0 ] = 0;
		b[ 0 ] = true;
		for ( int i = 1; i < n; i++ ) {
			d[ i ] = 31;
			b[ i ] = false;
		}

		int sum = 0;
		list< int > l;
		l.push_back( 0 );

		for( int i = 0; i < n; i++ ) {
			LI best;
			int min = 31;
			for( LI j = l.begin(); j != l.end(); j++ )
				if (d[ *j ] < min) {
					best = j;
					min = d[ *j ];
				}

			sum += d[ *best ];

			for( L::iterator j = v[ *best ].begin(); j != v[ *best ].end(); j++ ){
				d[ j->first ] = j->second < d[ j->first ] ? j->second : d[ j->first ];
				if ( !b[ j->first ] ) {
					b[ j->first ] = true;
					l.push_back( j->first );
				}
			}
			l.erase(best);
		}
		cout << sum << "\n" << (ct < z ? "\n" : "");
		for (int i = 0; i < n; i++)
			v[i].clear();
	}
}
