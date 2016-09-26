/*
* Generate 2*n - 1 chars under
* the digraphs constrains and
* print n chars increasing the
* offset by one each time
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool O[300][300];
char T[ 40 ];
string best = "";

void recur( int p ){
	if( p == 39 ){
		best = "";
		for(int i = 0; i < p; i++)
			best.push_back( T[ i ] );
		return;
	}

	for(int i = int('a'); i <= int('z') && best.length() != size_t( 39 ); i++){
		// Allowed digraph
		if( O[ int( T[ p - 1 ] ) ][ i ] ){
			T[ p ] = char(i);
			// Get new best
			if( p+1 > int( best.length() ) ){
				best = "";
				for(int i = 0; i < p+1; i++)
					best.push_back( T[ i ] );
			}
			// Check with one more
			recur( p + 1 );
		}
	}
}

int main(){
	int kases; cin >> kases;
	while( kases-- ){
		// Initialize
		best = "";
		for(int i = int('a'); i <= int('z'); i++)
			for(int j = int('a'); j <= int('z'); j++)
				O[i][j] = true;

		// Constrain Matrix
		int N; cin >> N;
		char a, b;
		for(int i = 0; i < N; i++){
			cin >> a >> b;
			O[ int(a) ][ int(b) ] = false;
		}
		// Recursivity for the first line
		for(int i = int('a'); i <= int('z'); i++){
			T[ 0 ] = char(i);
			if( best.size() == size_t( 0 ) )
				best.push_back( T[ 0 ] );
			recur( 1 );
			if( int( best.length() ) == 39 ){
				break;
			}
		}
		//Result
		int tam = ( int( best.size() ) + 1 ) / 2;
		for(int i = 0; i < tam; i++){
			cout << best.substr( i , tam ) << endl;
		}
	}
}
