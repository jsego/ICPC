
#include <algorithm>
#include <cstdio>

#define M 1000000000

using namespace std;

int m, n, x, y, z, c[500], d[500], p[500], s[500], t[500], V[500][500];

int bfs( int k ) {
	for ( int i = 0; i < n; ++i ) d[i] = p[i] = -1;

	d[k] = 0;
	int a = 1;
	p[k] = s[0] = k;
	while ( a > 0 ) {
		int r = M, b = 0;
		for ( int j = 0; j < a; ++j )
			for ( int k = 0; k < c[s[j]]; ++k ) {
				if ( p[V[s[j]][k]] < 0 ) {
					t[b++] = V[s[j]][k];
					d[V[s[j]][k]] = d[s[j]] + 1;
					p[V[s[j]][k]] = s[j];
				}
				else if ( p[s[j]] != V[s[j]][k] ) {
					if ( d[V[s[j]][k]] + d[s[j]] + 1 < r )
						r = d[V[s[j]][k]] + d[s[j]] + 1;
				}
			}
		if ( r < M ) return r;
		copy( t, t + b, s );
		a = b;
	}
	return M;
}

int main() {
	scanf( "%d\n", &z );
	for ( int i = 1; i <= z; ++i ) {
		scanf( "%d %d\n", &n, &m );
		for ( int j = 0; j < n; ++j ) c[j] = 0;

		for ( int j = 0; j < m; ++j ) {
			scanf( "%d %d\n", &x, &y );
			V[x][c[x]++] = y;
			V[y][c[y]++] = x;
		}

		int min = M;
		for ( int j = 0; j < n; ++j ) {
			int b = bfs( j );
			if ( b < min ) min = b;
		}

		printf( "Case %d: ", i );
		if ( min < 1000000000 ) printf( "%d\n", min );
		else printf( "impossible\n" );
	}
}
