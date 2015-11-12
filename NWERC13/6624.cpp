#include<iostream>

using namespace std;

long double R[1300];
int V[1300];
int C[101];

int convertToVal( string &s ){
	if( s == "10" || s == "J" || s == "Q" || s == "K" )
		return 10;
	if( s == "A" )
		return 11;
	return int(s[0]-'0');
}

int main(){
	cout.setf(ios::fixed);
	cout.precision( 25 );
	int N, M;
	while( cin >> N >> M ){
		for(int i = 0; i < 1300;i++){
			V[i] = 0;			
			R[i] = 0.0;
		}

		string card;
		for(int i = 0; i < N; i++){
			cin >> card;
			C[ i ] = convertToVal( card );
		}

		M--;

		for(int i = 0; i + 1< N; i++){
			V[ M ] = C[ i ];
			M += C[ i ];
		}

		for(int j = 0; j < 10; j++)
			R[j] = 0.1;

		long double p10 = 4.0/13.0, pOther = 1.0/13.0;
		for(int i = 0; i <= M; i++){
			if( V[ i ] > 0 ){
				if( V[ i ] + i <= M )
					R[ V[ i ] + i ] += R[ i ];
				continue;
			}
			for(int c = 2; c < 12; c++){
				if( i + c > M ) break;
				if( c != 10 )
					R[ i + c ] += R[ i ] * pOther;
				else
					R[ i + c ] += R[ i ] * p10;
			}
		}		
		cout << R[ M ] << endl;
	}
}
