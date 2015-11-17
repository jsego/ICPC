
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

typedef vector< map< int, int > > Graph;

Graph G;
int C, L, T, Z, V[90000];

int dijkstra( int s ) {
	set< pair< int, int > > m;           // cola de prioridad
	vector< int > z( C * L, 1000000000); // distancias iniciales
	z[s] = 0;                            // distancia a s es 0
	m.insert( make_pair( 0, s ) );       // insertar (0,s) en m
	while ( m.size() ) {
		pair< int, int > p = *m.begin(); // p=(coste,nodo) con menor coste
		m.erase( m.begin() );            // elimina este par de m
		//cout << "Visit " << p.second / C << "," << p.second % C << " at " << p.first << "\n";
		if ( p.second == T )
			return p.first;              // cuando nodo es T, acaba

		// para cada nodo adjacente al nodo p.second
		for ( map< int, int >::iterator i = G[p.second].begin(); i != G[p.second].end(); ++i ) {
			// q = (coste hasta nodo adjacente, nodo adjacente)
			pair< int, int > q( p.first + i->second, i->first );
			// si q.first es la menor distancia hasta q.second
			if ( q.first < z[q.second] ) {
				m.erase( make_pair( z[q.second], q.second) ); // borrar anterior
				m.insert( q );                                // insertar q
				z[q.second] = q.first;                        // actualizar distancia
			}
		}
	}
	return -1;
}

void edge( int i, int j, int c ) {
	map< int, int >::iterator k = G[i].find( j );
	if ( k == G[i].end() || c < k->second )
		G[i][j] = c;
}

void neighbors( int i ) {
	if ( i % C - 1 >= 0 && V[i - 1] ) edge( i, i - 1, 1 );
	if ( i % C + 1 <  C && V[i + 1] ) edge( i, i + 1, 1 );
	if ( i / C - 1 >= 0 && V[i - C] ) edge( i, i - C, 1 );
	if ( i / C + 1 <  L && V[i + C] ) edge( i, i + C, 1 );
}

void fill( int i, int k, int j, int M, int N ) {
	if ( j == T || M == 0 || ( j != i && V[j] > 1 ) ) edge( i, j, k - M );
	else {
		if ( j % C - N >= 0 && V[j - N]     ) fill( i, k, j - N,     M - 1, N );
		if ( j % C + N <  C && V[j + N]     ) fill( i, k, j + N,     M - 1, N );
		if ( j / C - N >= 0 && V[j - N * C] ) fill( i, k, j - N * C, M - 1, N );
		if ( j / C + N <  L && V[j + N * C] ) fill( i, k, j + N * C, M - 1, N );
	}
}

int main() {
	int a, b;
	cin >> Z;
	for ( int z = 1; z <= Z; ++z ) {
		cin >> L >> C;
		for ( int i = 0; i < C * L; ++i )
			cin >> V[i];

		cin >> a >> b;
		int s = C * a + b;
		cin >> a >> b;
		T = C * a + b;

		// construct graph
		G = Graph( C * L );
		for ( int i = 0; i < C * L; ++i ) {
			if ( V[i] == 1 ) neighbors( i );
			else if ( V[i] > 1 ) {
				int M = V[i] / 10, N = V[i] % 10;
				fill ( i, M, i, M, N );
			}
		}

		if ( 1 < z ) cout << "\n";
		int res = dijkstra( s );
		if ( res < 0 ) cout << "IMPOSSIBLE\n";
		else cout << res << "\n";
	}
}
