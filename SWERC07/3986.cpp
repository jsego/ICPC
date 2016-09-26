#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>

#define LE length()
#define SL size()
#define PB push_back

using namespace std;

vector< string > OS1,OS2;
vector< int > v1,v2;
int mat[ 1001 ][ 1001 ],bridges[ 1001 ][ 1001 ];

int main(){
	int kases; 
	cin >> kases;
	while( kases-- ){
		OS1.clear(); 
		OS2.clear(); 
		v1.clear(); 
		v2.clear();

		int cit1,cit2,cost; 
		cin >> cit1;
		string s,o;
		for( int ci = 0 ;ci < cit1; ci++ ){
			cin >> s >> o >> cost; 
			OS1.PB( o );
			v1.PB( cost );
		}

		cin >> cit2;
		for( int ci = 0; ci < cit2; ci++ ){
			cin >> s >> o >> cost; 
			OS2.PB( o ); 
			v2.PB( cost );
		}

		for( size_t i = 0; i <= OS2.SL; i++ ){
			mat[ 0 ][ i ] = bridges[ 0 ][ i ] = 0;
		}
		for( size_t i = 0; i <= OS1.SL; i++ ){
			mat[ i ][ 0 ] = bridges[ i ][ 0 ] = 0;
        }

		int sum, val1, val2;
		for( size_t i = 1; i <= OS1.SL; i++ ){
			for( size_t j = 1; j <= OS2.SL; j++ ){
				mat[ i ][ j ] = 0;
				val1 = mat[ i - 1 ][ j ]; 
				val2 = mat[ i ][ j - 1 ];
				if( OS1[ i - 1 ] == OS2[ j - 1 ] ){
					sum = mat[ i - 1 ][ j - 1 ] + v1[ i - 1 ] + v2[ j - 1 ];
					if( val1 > mat[ i ][ j ] || 
					  ( val1 == mat[ i ][ j ] && bridges[ i - 1 ][ j ] < bridges[ i ][ j ] ) ){
						mat[ i ][ j ] = val1; 
						bridges[ i ][ j ] = bridges[ i - 1 ][ j ];
					}
					if( val2 > mat[ i ][ j ] || 
					  ( mat[ i ][ j ] == val2 && bridges[ i ][ j - 1 ] < bridges[ i - 1 ][ j ] ) ){
						mat[ i ][ j ] = val2; 
						bridges[ i ][ j ] = bridges[ i ][ j - 1 ];
					}
					if( sum > mat[ i ][ j ] || 
					  ( sum == mat[ i ][ j ] && bridges[ i - 1 ][ j - 1 ] + 1 < bridges[ i ][ j ] ) ){
						mat[ i ][ j ] = sum; 
						bridges[ i ][ j ] = bridges[ i - 1 ][ j - 1 ] + 1;
					}
				}
				else{
					if( val1 > mat[ i ][ j ] || 
					  ( val1 == mat[ i ][ j ] && bridges[ i - 1 ][ j ] < bridges[ i ][ j ] ) ){
						mat[ i ][ j ] = val1; 
						bridges[ i ][ j ] = bridges[ i - 1 ][ j ];
					}
					if( val2 > mat[ i ][ j ] || 
					  ( mat[ i ][ j ] == val2 && bridges[ i ][ j - 1 ] < bridges[ i - 1 ][ j ] ) ){
						mat[ i ][ j ] = val2; 
						bridges[ i ][ j ] = bridges[ i ][ j - 1 ];
					}
				}
			}
		}
		cout << mat[ OS1.SL ][ OS2.SL ] << " " << ( bridges[ OS1.SL ][ OS2.SL ] ) << endl;
	}
}
