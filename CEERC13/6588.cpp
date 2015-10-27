#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int A[100002];

void swapA( int o, int d ){
	int mid = (d+o+1)/2;
	int cant = (d+1-o)/2;
	for(int i = 0; i < cant; i++){
		swap( A[i+o] , A[i+mid] );
	}
}

int main(){
	int T; cin >> T;
	while( T-- ){
		int N; cin >> N;
		vector<pair<int,int> > res;
		for(int n = 1; n <= N; n++)
			cin >> A[n];
		
		for(int o = 1; o < N; o++){
			if( A[o] == o ) 
				continue;
			int d = o;
			for(; d <= N; d++){
				if( A[d] == o )
					break;
			}
			do{
				if( (d+1-o)&1 ){
					swapA( o+1 , d );
					res.push_back( make_pair( o+1 , d ) );	
					d = o + ((d-o)/2);
				}
				else{
					swapA( o , d );
					res.push_back( make_pair( o , d ) );
					d = o + (d+1-o)/2 - 1;
				}
			}while( A[o] != o );
		}

		cout << res.size() << endl;
		for(int i = 0; i < int(res.size()); i++){
			cout << res[i].first << " " << res[i].second << endl;
		}
	}
}
