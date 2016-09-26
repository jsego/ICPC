#include<iostream>
#include<iomanip>
#include<string>
#include<set>
using namespace std;

int L[300];
int C[300];

int main(){
	cout.setf( ios::fixed );
	cout.precision( 4 );
	string s;
	while( cin >> s, s != "0" ){
		int f = int( 'a' ), t = int( 'z' ) + 1;
		for(int i = f; i < t; i++) {
			L[i] = -1;
			C[i] = 0;
		}
		int num_reuses = 0;
		int den_reuses = 0;
		int mask;
		for(int j = 0; j < int( s.length() ); j++){
			mask = ( 1 << int( s[ j ] - 'a' ) );
			for( int i = f; i < t; i++ ){
				if( i != int(s[ j ]) )
					C[ i ] |= mask;
			}
			if( L[ int(s[ j ]) ] != -1 ){
				mask = 1;
				for( int i = 0; i < 26; i++){
					if( mask & C[ int(s[ j ]) ] )
						num_reuses++;
					mask <<= 1;
				}
				den_reuses++;
				//cout << j << " " << num_reuses << "/" << den_reuses << endl;
			}
			C[ int( s[ j ] ) ] = 0;
			L[ int(s[ j ]) ] = j;
		}
		if( den_reuses == 0 )
			cout << "NaN" << endl;
		else
			cout << double( num_reuses ) / double( den_reuses ) << endl;
	}
}
