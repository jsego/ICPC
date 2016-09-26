/*
*  Javier Segovia
*  Accepted in 0.012
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
#define MAX(a,b) ((a)>(b)?(a):(b))
int A[22],N,B[22][22],C[22];
int subs(){
	for(int i=0;i<N;i++) B[i][0] = B[0][i] = 0;
	for (int i=1; i<=N ; i++) {
		for (int j=1; j<=N ; j++) {
			B[i][j] = MAX(B[i-1][j],B[i][j-1]);
			if(A[i] == C[j]) B[i][j] = MAX(B[i][j],B[i-1][j-1]+1);
		}
	}
	return B[N][N];
}
int main(){
	cin>>N; int x;
	//for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1;i<=N;i++){cin>>x; A[x] = i;}
	while (cin>>x) {
		C[x] = 1; for(int i=2;i<=N;i++){cin>>x; C[x] = i;}
		//for (int i=2; i<=N ; i++) {
	//		cin>>C[i];
	//	}
		cout<<subs()<<endl;
	}
}