#include<iostream>
#include<vector>

using namespace std;

int F[ 10001 ];
vector< int > p;


void primes(){
	p.push_back( 2 );
	for( int i = 3; i < 101; i+=2 ){
		bool ok = true;
		for( int j = 0; j < int(p.size()); j++ )
			if( i % p[ j ] == 0 ){
				ok = false; break;
			}
		if( ok ) p.push_back( i );
	}
}

int main(){
	primes();
	for( int i = 0; i < 10001; i++ ) F[ i ] = 0;
	F[ 1 ] = 2;
	for( int i = 2; i < 10001; i++ ){
		F[ i ] = F[ i - 1 ];
		int aux = i, totient = i;
		for( int j = 0; j < int(p.size()); j++ ){
			int val = 0;
			while( aux % p[ j ] == 0 ){
				aux /= p[ j ];
				val = p[ j ];
			}
			if( val )
				totient = ( totient * ( val - 1 ) ) / val;
		}
		if( aux > 1 ) totient = ( totient * ( aux - 1 ) )/ aux;
		F[ i ] += totient;
	}
	int P;
	cin >> P;
	while( P-- ){
		int K, N;
		cin >> K >> N;
		cout << K << " " << F[ N ] << endl;
	}
}
