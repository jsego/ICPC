
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef pair< int, int > Node;
typedef map< string, vector< int > > Edges;
typedef vector< Edges > Graph;

Graph G1, G2;
int L1, L2, P1, P2, T1, T2, Z;

int BFS( const Node & m, const Node & n ) {
	set< Node > s, t;
	s.insert( m );
	t.insert( m );
	for ( int d = 0; s.size(); ++d ) {
		set< Node > u;
		for ( set< Node >::iterator i = s.begin(); i != s.end(); ++i ) {
			if ( *i == n ) return d;
			Edges::iterator x = G1[i->first].begin();
			Edges::iterator y = G2[i->second].begin();

			// iterate over labels in alphabetical order for both graphs
			while ( x != G1[i->first].end() && y != G2[i->second].end() ) {
				if ( x->first < y->first ) ++x;
				else if ( y->first < x->first ) ++y;
				else {
					// if the label of both graphs is the same
					for ( unsigned j = 0; j < x->second.size(); ++j )
						for ( unsigned k = 0; k < y->second.size(); ++k ) {
							// add neighbor if not already visited
							Node node( x->second[j], y->second[k] );
							if ( t.find( node ) == t.end() )
								u.insert( Node( x->second[j], y->second[k] ) );
						}
					++x;
					++y;
				}
			}
		}
		t.insert( u.begin(), u.end() );
		s = u;
	}
	return -1;
}

int main() {
	int a, b;
	string s;
	cin >> Z;
	for ( int z = 1; z <= Z; ++z ) {
		cin >> L1 >> T1 >> P1;
		G1 = Graph( L1 );
		for ( int i = 0; i < P1; ++i ) {
			cin >> a >> s >> b;
			G1[a][s].push_back( b );
		}
		cin >> L2 >> T2 >> P2;
		G2 = Graph( L2 );
		for ( int i = 0; i < P2; ++i ) {
			cin >> a >> s >> b;
			G2[a][s].push_back( b );
		}

		if ( 1 < z ) cout << "\n";
		cout << BFS( Node( 0, 0 ), Node( T1, T2 ) ) << "\n";
	}
}
