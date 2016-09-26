#include<iostream>
#include<vector>

using namespace std;

int T[ 101 ][ 101 ];
bool V[ 101 ][ 101 ];
int R, C;
int mx[ 4 ] = {-1,1,0,0};
int my[ 4 ] = {0,0,-1,1};

int main(){
	while( cin >> R >> C ){
		for( int r = 0; r < R; r++ ){
			for( int c = 0; c < C; c++ ){
				cin >> T[ r ][ c ]; 
				V[ r ][ c ] = false;
			}
		}
		int res = 5, nr, nc;
		int min_bound = 2000000000, max_bound = 0;
		for( int r = 1; r < R; r++ ){
			min_bound = 2000000000; max_bound = 0;
			for( int c = 0; c < C; c++ ){
				if( T[ r ][ c ] > T[ r - 1 ][ c ] ){
					if( T[ r ][ c ] > min_bound && T[ r - 1 ][ c ] < max_bound ){
						min_bound = T[ r - 1 ][ c ];
						max_bound = T[ r ][ c ];
					}
					else{
						min_bound = T[ r - 1 ][ c ];
						max_bound = T[ r ][ c ];
						res++;
					}
				}
				else{
					min_bound = 2000000000; max_bound = 0;
				}
			}
		}//cout<< "N: " << res << endl;
		for( int r = R-2; r >= 0; r-- ){
			min_bound = 2000000000; max_bound = 0;
			for( int c = 0; c < C; c++ ){
				if( T[ r ][ c ] > T[ r + 1 ][ c ] ){
					if( T[ r ][ c ] > min_bound && T[ r + 1 ][ c ] < max_bound ){
						min_bound = T[ r + 1 ][ c ];
						max_bound = T[ r ][ c ];
					}
					else{
						min_bound = T[ r + 1 ][ c ];
						max_bound = T[ r ][ c ];
						res++;
					}
				}
				else{
					min_bound = 2000000000; max_bound = 0;
				}
			}
		}//cout<< "S: " << res << endl;
		for( int c = 1; c < C; c++ ){
			min_bound = 2000000000; max_bound = 0;
			for( int r = 0; r < R; r++ ){
				if( T[ r ][ c ] > T[ r ][ c - 1 ] ){
					if( T[ r ][ c ] > min_bound && T[ r ][ c - 1 ] < max_bound ){
						min_bound = T[ r ][ c - 1 ];
						max_bound = T[ r ][ c ];
					}
					else{
						min_bound = T[ r ][ c - 1 ];
						max_bound = T[ r ][ c ];
						res++;
					}
				}
				else{
					min_bound = 2000000000; max_bound = 0;
				}
			}
		}//cout<< "W: " << res << endl;
		for( int c = C-2; c >= 0; c-- ){
			min_bound = 2000000000; max_bound = 0;
			for( int r = 0; r < R; r++ ){
				if( T[ r ][ c ] > T[ r ][ c + 1 ] ){
					if( T[ r ][ c ] > min_bound && T[ r ][ c + 1 ] < max_bound ){
						min_bound = T[ r ][ c + 1 ];
						max_bound = T[ r ][ c ];
					}
					else{
						min_bound = T[ r ][ c + 1 ];
						max_bound = T[ r ][ c ];
						res++;
					}
				}
				else{
					min_bound = 2000000000; max_bound = 0;
				}
				//cout << r << " " << c << " " << min_bound << " " << max_bound << " " << res << endl;
			}
		}//cout<< "E: " << res << endl;

		for( int r = 0; r < R; r++ ){
			for( int c = 0; c < C; c++ ){
				if( V[ r ][ c ] ) continue;
				res++;
				V[ r ][ c ] = true;
				vector< int > v;
				v.push_back( r );
				v.push_back( c );
				int ac, ar, a = 0;
				while( a < int(v.size()) ){
					ar = v[ a++ ]; ac = v[ a++ ];
					for( int i = 0; i < 4; i++ ){
						nr = ar + mx[ i ];
						nc = ac + my[ i ];
						if( nr >= 0 && nr < R && nc >= 0 && nc < C && !V[ nr ][ nc ] && T[ nr ][ nc ] == T[ r ][ c ] ){
							V[ nr ][ nc ] = true;
							v.push_back( nr );
							v.push_back( nc );
						}
					}
				}
			}
		}
		cout << res << endl;
	}
}
