#include<iostream>
#include<cmath>
using namespace std;

#define MODU 2147483647
int N;
int A[2002];
unsigned B[2002][2002];
unsigned S[2002][2];

int main(){
	while( cin >> N ){
		for(int n = 0; n <= N; n++){
			cin >> A[ n ]; 
			S[ n ][ 0 ] = S[ n ][ 1 ] = 0; 
			for(int i = 0; i < N + 2; i++)
				B[ n ][ i ] = 0;
		}

		B[ 1 ][ A[ 0 ] ] = 1;
		if( A[ 0 ] < A[ 1 ] ) S[ 1 ][ 0 ] = 1;
		else S[ 1 ][ 1 ] = 1;

		for(int a = 2; a < N+1; a++){ // arrow
			bool left = ( A[ a ] < A[ a - 1 ] );
			for(int s = 1; s < N+2; s++){
				if( ( s >= A[ a ] && s <= A[ a - 1 ] ) || ( s >= A[ a - 1 ] && s <= A[ a ] ) ) // between 2 arrows
					continue;
				B[ a ][ s ] = (B[ a ][ s ] + B[ a - 1 ][ s ])%MODU;
				if( s < A[ a ] ) S[ a ][ 0 ] = ( S[ a ][ 0 ] + B[ a ][ s ]) % MODU;
				else if( s > A[ a ] ) S[ a ][ 1 ] = ( S[ a ][ 1 ] + B[ a ][ s ] ) % MODU;
			} 	
				
			if( left ){
				B[ a ][ A[ a - 1 ] ] = (B[ a ][ A[ a - 1 ] ] + S[ a - 1 ][ 0 ]) % MODU;
				S[ a ][ 1 ] = ( S[ a ][ 1 ] + S[ a - 1 ][ 0 ]) % MODU;
			}
			else{
				B[ a ][ A[ a - 1 ] ] = (B[ a ][ A[ a - 1 ] ] + S[ a - 1 ][ 1 ]) % MODU;
				S[ a ][ 0 ] = ( S[ a ][ 0 ] + S[ a - 1 ][ 1 ]) % MODU;				
			}
		} 
		cout << (S[ N ][ 0 ] + S[ N ][ 1 ]) % MODU << endl;
	}
}
