
#include <iostream>

using namespace std;

int gcd( int m, int n ) {
	if ( m % n == 0 ) return n;
	else return gcd( n, m % n );
}

int main() {
	int m, n;
	while ( cin >> m >> n ) {
		int res = ( n - 1 ) * ( m + 1 );
		for ( int i = 1; 2 * i * ( i + 1 ) < m; ++i )
			for ( int j = i + 1; j * j + i * i <= m; j += 2 )
				if ( gcd( i, j ) == 1 )
					res += m / ( i * i + j * j );
		cout << res << "\n";
	}
}
