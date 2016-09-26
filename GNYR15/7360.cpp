#include<iostream>

using namespace std;

#define SQ(a) ((a)*(a))

long long B[ 51 ][ 51 ];


int main(){
	for( int i = 0; i < 51; i++ )
		B[ i ][ 0 ] = 1;
	for( int i = 1; i < 51; i++ ){
		for( int j = 1; j <= i; j++ ){
			B[ i ][ j ] = B[ i - 1 ][ j ] + B[ i - 1 ][ j - 1 ];
		}
	}
	//cout << B[ 100 ][ 50 ] << endl;
	int P; cin >> P;
	while( P-- ){
		int K, S;
		cin >> K >> S;  S /= 2;
		long long res = 0;
		for( int i = S&1; i*3 <= S; i+=2 ){
			//cout << "B[" << S << "][" << i << "]: " << B[ S ][ i ] << endl;
			res += SQ(B[ (S-i)/2 + i ][ i ]);
		}
		cout << K << " " << res << endl;
	}
}
