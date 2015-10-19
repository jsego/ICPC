#include<iostream>
#include<set>

using namespace std;

int K[10001];
int N;

int main(){
	while( cin >> N ){
		set< int > S;

		for(int n = 0; n < N; n++){
			cin >> K[n];
			if( K[n] < 0 )
				S.insert( n );
		}	

		set< int >::iterator best_it;
		int n, kn, res = 0;

		while( !S.empty() ){
			best_it = (--S.end());
			n = *best_it; 
			kn = K[n];

			res++;
			if( n > 0 ){
				K[n-1] += kn;
				if( K[n-1] < 0 )
					S.insert( n-1 );
			}
			else if( N > 1 ){
				K[N-1] += kn;
				if( K[N-1] < 0 )
					S.insert( N-1 );
			}
			if( n + 1 < N ){
				K[n+1] += kn;
				if( K[n+1] < 0 )
					S.insert( n+1 );
			}
			else if( N > 1 ){
				K[0] += kn;
				if( K[0] < 0 )
					S.insert( 0 );
			}
			K[n] = (-K[n]);
			S.erase( best_it );
		}
		cout << res << endl;
	}	
}
