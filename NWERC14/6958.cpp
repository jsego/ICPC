#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

#define MAX_ITERS 100
#define MAX_UPDATES 10
typedef long long LL;

int N;
LL L;
LL T[15][15];

LL calc( vector< int > &a ){
	LL res = 0;
	for(int i = 1; i < int( a.size() ); i++){
		res += T[ a[i-1] ][ a[i] ];
	}
	return res;
}

LL calc2( vector<int> & a ) {
	do{
		if( calc( a ) + T[ a[int(a.size())-1] ][ a[0] ] == L ){
			return true;
		}
	}while(next_permutation( a.begin(), a.end() ) );

	return false;
}

int main(){
	while( cin >> N >> L ){
		for( int i = 0; i < N ; i++){
			for( int j = 0; j < N; j++){
				cin >> T[ i ][ j ];
			}
		}
		vector< int > A;
		for(int i = 0; i < N ; i++) 
			A.push_back( i );
		bool res = false;
		if( N < 4 ){
			res = calc2( A ) ;
		}
		else{
			for(int mid_pivot = 1; mid_pivot < N ; mid_pivot++){
				vector<bool> sv(N-2, false);
				for(int i = (N-2)/2; i < N-2; i++) 
					sv[i] = true;
				do{
					vector<int> B, C;
					for(int num = 1, cont = 0; num < N; num++){
						if( num == mid_pivot) continue;
						if( sv[ cont ] ) C.push_back( num );
						else B.push_back( num );
						cont++;
					} 
					set<LL> combos;
					LL value;

					do{
						value = T[ 0 ][ B[0] ] + calc( B ) + T[ B[ int(B.size()) - 1 ] ][ mid_pivot ];
						if( value < L )
							combos.insert( value );
					}while(next_permutation( B.begin() , B.end() ) );

					do{
						value = T[ mid_pivot ][ C[0] ] + calc( C ) + T[ C[ int(C.size())-1 ] ][ 0 ];
						if( value < L && combos.find( L - value ) != combos.end() ){
							res = true; break;
						 }
					}while(next_permutation( C.begin() , C.end() ) );
				}while(next_permutation( sv.begin() , sv.end() ) );
			}
		}
		cout << ( res ? "possible" : "impossible" ) << endl;
	}
}
