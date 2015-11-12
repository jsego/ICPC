#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define ULL unsigned long long

ULL A[100001];
int N;

ULL GCD( ULL a, ULL b ){
	if( b == 0 ) return a;
	return GCD( b , a%b );
}

int main(){
	int T; cin >> T; 
	while( T-- ){
		cin >> N;
		ULL res = 0;
		map< ULL , int > vres;
		for( int n = 0; n < N; n++){
			cin >> A[n];
			map< ULL , int > acres;
			for(map< ULL , int >::iterator it = vres.begin(); it != vres.end() ; it++){
				ULL gcd = GCD( A[n] , (it->first) );
				if( acres.find( gcd ) == acres.end() ){
					acres[ gcd ] = it->second;
					res = max( res , gcd * (n+1 - (it->second)) );
				}
			}
			if( acres.find( A[n] ) == acres.end() ){
				acres[ A[n] ] = n;
				res = max( res , A[n] );
			}
			swap( vres , acres );
		}
		cout << res << endl;
		
	}
}
