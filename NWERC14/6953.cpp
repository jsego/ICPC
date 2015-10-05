#include<iostream>
#include<vector>
#include<stack>

using namespace std;

char c[500005];
int L[500005];
int R[500005];
int inbound[500005];
unsigned long long visits[500005];
vector<int> fo; // final order

void topsort( int M ) {
	stack<int> order;
	int current;

	// Search for roots
	for(int m = 1; m <= M; m++){
		if( inbound[m] == 0 )
			order.push( m ) ;
	}

	// Start topsort from roots
	while( !order.empty() ){
		// Pop from stack 
		current = order.top();
		order.pop();
		// Save order in fo
		fo.push_back( current );
		// Add childs only if inbound is 0
		if( L[current] != 0){
			inbound[ L[current] ]--;
			if( inbound[ L[current] ] == 0)
				order.push( L[current] );
		}
		if( R[current] != 0){
			inbound[ R[current] ]--;
			if( inbound[ R[current] ] == 0 )
				order.push( R[current] );
		}
	}
}

int main(){
	unsigned long long N;
	int M;
	while( cin >> N >> M ){
		fo.clear();
		for(int m = 0; m <= M; m++){
			inbound[m] = 0;
			visits[m] = 0;
		} 
		for(int m = 1; m <= M ; m++){
			cin >> c[m] >> L[m] >> R[m];
			inbound[ L[m] ]++;
			inbound[ R[m] ]++;
		}

		visits[1] = N;

		topsort( M ) ;

		int ac;
		unsigned long long tl, tr;
		for(int i = 0; i < int(fo.size()); i++ ){
			ac = fo[i];
			tl = 0; tr = 0;		
			if( c[ac] == 'L' ){
				tl = (visits[ac]+1)/2;
				tr = (visits[ac])/2;
			}
			else{
				tl = (visits[ac])/2;
				tr = (visits[ac]+1)/2;
			}

			if( L[ac] != 0 ) visits[ L[ac] ] += tl;
			if( R[ac] != 0 ) visits[ R[ac] ] += tr;
			
			if(visits[ac]&1)
				c[ac] = ( c[ac] == 'L' ? 'R' : 'L' );	
		}	

		for(int m = 1; m <= M; m++){
			cout << c[m] ;
		}	
		cout << endl;
	}
}
