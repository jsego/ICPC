#include<iostream>
#include<set>
using namespace std;

int P, K;
int T[1001];
int C[101];
int S[1001];

int isWinnerPile( int s ){ // s is the state
	if( s < 0 )
		return -1;
	if( S[ s ] != -1 )
		return S[ s ];
	S[ s ] = 0;
	set< int > si;
	int ac;
	for(int m = 0; m <= K && m < s; m++){
		ac = isWinnerPile( s - m - T[ s - m - 1] );
		if( ac != -1 )
			si.insert( ac );
	}
	for(int i = 0; ; i++){
		if( si.find( i ) == si.end() ){
			return (S[ s ] = i);
		}
	}
	return -1;
}

int main(){
	while( cin >> P >> K ){
		int win = 0, res = 0;
		for(int p = 0; p < P; p++){
			cin >> C[ p ];
			for(int c = 0; c < C[ p ]; c++){
				cin >> T[ c ];
				S[ c ] = -1;
			}
			S[ C[ p ] ] = -1;
			S[ 0 ] = 0;
			win = isWinnerPile( C[ p ] );
			res = res ^ win;
			//cout << win << " " << res << endl;
		}
		cout << (res!=0?"Alice can win.":"Bob will win.") << endl;
	}
}
