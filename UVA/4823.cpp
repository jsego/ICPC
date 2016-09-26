/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

bool I[1005][1005];
bool F[1005][1005];
bool C[1005][1005];
bool W[1005][1005]; //1 gana, 0 pierde

int main(){
	int N;
	while (cin>>N ) {
		int ac;
		for (int i=0; i<N ; i++) {
			for (int j=0; j<N ; j++) {
				cin>>ac;
				I[i][j] = (ac&1); // 1 impar, 0 par
				
				if(i) F[i][j] = (F[i-1][j]!=I[i][j]);
				else F[i][j] = I[i][j];
				
				if(j) C[i][j] = (C[i][j-1]!=I[i][j]);
				else C[i][j] = I[i][j];
				
				if(i){ W[i][j] = (C[i][j] == 0)&& (W[i-1][j] == 0) ;}
				else{ W[i][j] = (C[i][j] == 0); }
				
				if(j){ W[i][j] = W[i][j] || ( (F[i][j] == 0) && (W[i][j-1] == 0) );}
				else W[i][j] = W[i][j] || (F[i][j] == 0);
			}
		}
		
		cout<<(W[N-1][N-1]?"W":"L")<<endl;
	}
}