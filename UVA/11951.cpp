#include<iostream>
#include<vector>

using namespace std;

int T[ 101 ][ 101 ];

pair< int , int > kadane( vector< int > &s , int factor, int lim){
	int area = 0, price = 0, aux_area = 0, aux_price = 0;
	int last = 0;
	for( int i = 0; i < int( s.size() ); i++){
		aux_area++;
		aux_price += s[ i ];
		while( last <= i && aux_price > lim ){
			aux_price -= s[ last++ ];
			aux_area--;
		}
		if( aux_area > area ){
			area = aux_area ;
			price = aux_price ;
		}
		else if( aux_area == area && aux_price < price ){
			price = aux_price ;
		}
	}
	return make_pair( area * factor , price );
}

int main(){
	int kases; cin>>kases;
	for(int kas = 1; kas <= kases; kas++){
		int N, M, K;
		cin >> N >> M >> K;
		for(int i = 0; i < N ; i++){
			for(int j = 0; j < M ; j++){
				cin >> T[ i ][ j ];
			}
		}	
		int area = 0, price = 0;
		for(int l = 0; l < M; l++){
			vector< int > sum( N, 0 );
			for(int r = l; r < M; r++ ){
				for(int row = 0; row < N; row++){
					sum[ row ] += T[ row ][ r ];
				}
				pair<int,int> ac = kadane( sum, (r-l+1) , K);
				if( ac.first > area ){
					area = ac.first;
					price = ac.second;
				}
				else if( ac.first == area && ac.second < price )
					price = ac.second;
			}
		}
		cout << "Case #" << kas << ": " << area << " " << price << endl;
	}
}
