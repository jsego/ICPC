#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector< int > T[ 5005 ];
int inbound[ 5005 ];
int ancestors[ 5005 ];
int successors[ 5005 ];
int visited[ 5005 ];
int bfs[ 5005 ];
vector< int > fo;

void toposort( int M ){
	stack< int > order;
	int current;
	
	for( int m = 0; m < M; m++ ){
		if( inbound[ m ] == 0 )
			order.push( m );
	}
	
	while( !order.empty() ){
		current = order.top();
		order.pop();
		fo.push_back( current );
		for( int i = 0; i < int(T[ current ].size()); i++ ){
			inbound[ T[ current ][ i ] ]--;
			if( inbound[ T[ current ][ i ] ] == 0 )
				order.push( T[ current ][ i ] );
		}
	}
}

int main(){
	int A, B, E, P;
	while( cin >> A >> B >> E >> P ){
		fo.clear();
		for(int i = 0; i < E; i++){
			T[ i ].clear();	
			inbound[ i ] = 0;
			ancestors[ i ] = 0;
			successors[ i ] = 0;
			visited[ i ] = -1;
		}
		int x, y;
		for( int p = 0; p < P; p++ ){
			cin >> x >> y;
			inbound[ y ]++;
			T[ x ].push_back( y );
		}
		
		toposort( E );
		
		int a = 0, b = 0, c = 0;

		for( int i = 0; i < E; i++ ){
			int n = fo[ i ];
			if( ancestors[ n ] >= B )
				c++;
			int ac = 0, t = 0;
			bfs[ t++ ] = n;
			visited[ n ] = i;
			while( ac < t ) {
				n = bfs[ ac++ ];
				for( int j = 0; j < int( T[ n ].size() ); j++){
					if( visited[ T[ n ][ j ] ] < i ){
						visited[ T[ n ][ j ] ] = i;
						bfs[ t++ ] = T[ n ][ j ];
						ancestors[ T[ n ][ j ] ]++;
					}
				}
			}
			successors[ fo[ i ] ] = t-1;
			if( E - successors[ fo[ i ] ] <= A )
				a++;
			if( E - successors[ fo[ i ] ] <= B )
				b++;
		}
		cout << a << endl << b << endl << c << endl;
	}
}
