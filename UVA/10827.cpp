#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int T[ 150 ][ 150 ];
int N;

// Ineficient Algorithm O(N^2) instead of O(N)
int kadane( vector< int > & v){
	int res = v[ 0 ], aux = v[ 0 ];
	for(int i = 1; i < int( v.size() );i++){
		aux = v[ i ];
		res = max( res, aux );
		for(int j = i - 1; j >= max( 0 , i - N + 1 ); j-- ){
			aux += v[ j ];
			res = max( res, aux );
			if( aux < 0 )
				aux = 0;
		} 
	}
	return res;
}

int main(){
	int kases; 
	cin >> kases;
	while( kases-- ){
		cin >> N;
		for( int i = 0; i < N; i++ ){			
			for( int j = 0; j < N; j++ ){
				cin >> T[ i ][ j ];
				T[ i + N ][ j ] = T[ i ][ j + N ] = T[ i + N ][ j + N ] = T[ i ][ j ];
			} 
		}
		int res = T[ 0 ][ 0] ; 
		for(int l = 0; l < N; l++){
			vector < int > aux( 2 * N - 1, 0 );
			for(int r = l; r < l + N; r++){
				for(int row = 0; row + 1 < 2 * N; row++){
					aux[ row ] += T[ row ][ r ];
				} 
				res = max( res, kadane( aux ) );
			}
		}
		cout << res <<endl;
		
	}
}
