#include<iostream>
#include<algorithm>
using namespace std;

#define INF 1000000000

int P[101][51];
int C[101][101];
int R[101][51];

int main(){
	int N; cin >> N;
	while(N--){
		int s, c;
		int res = -INF;
		cin >> s >> c;
		for(int i = 0; i < s ; i++){
			for(int j = 0; j < c; j++){
				cin >> P[i][j];
				R[i][j] = -INF;
			}
			R[i][0] = P[i][0];	
			if( c == 1 )	
				res = max( res, R[i][0] );	
		}
		for(int i = 0; i < s; i++){
			for(int j = 0; j < s; j++){
				cin >> C[i][j];
			}
		}
		for(int j = 1; j < c; j++){
			for(int i = 0; i < s; i++){
				for(int k = 0; k < s; k++){
					R[i][j] = max( R[i][j], R[k][j-1] + P[i][j] - C[k][i] );
				}
				if( j + 1 == c )
					res = max( res, R[i][j] );
			}
		}
		cout << res << endl;
	}
}
