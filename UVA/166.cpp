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
#define INF 1000000000
#define MIN(a,b) ((a)<(b)?(a):(b))
int A[6] = {5,10,20,50,100,200};
int B[6] = {0,0,0,0,0,0};
int T[10002];
int tt[10002][6];
int D[10001];
int tot,a,b;
char c;

bool check(){
	for (int i=0; i<6; i++) {
		if(B[i]) return true;
	}
	return false;
}

bool input(){
	for (int i=0; i<6; i++) {
		scanf("%d",&B[i]);
	}
	if(!check()) return false;
	scanf("%d%c%d",&a,&c,&b);
	tot = a*100 + b;
	return true;
}

void memoization(int t){
	T[0] = 0;
	for (int i=0; i<6; i++) {
		tt[0][i] = 0;
	}
	for (int i=5; i<=t ; i++) {
		for (int j=0; j<6; j++) {
			if(A[j]<=i && tt[i-A[j]][j]<B[j] && T[i]>=1+T[i-A[j]]){
				T[i] = 1+T[i-A[j]];
				for(int k=0;k<6;k++) 
					tt[i][k] = tt[i-A[j]][k];
				tt[i][j]++;
			}
		}
	}
}

int main(){
	D[0] = 0;
	
	for (int i=5; i<10001; i+=5) {
		D[i] = INF;
		for (int j=0; j<6; j++) {
			if(A[j] > i) break;
			D[i] = MIN(D[i],1+D[i-A[j]]);
		}
	}
	
	while (input()) {
		int sum = 0;
		for (int i=0; i<6; i++) {
			sum += B[i]*A[i];
		}
		for (int i=5;i<=sum; i+=5) {
			T[i] = INF;
		}
		memoization(sum);
		/*for (int i=5;i<=sum; i+=5) {
			cout<<"T["<<i<<"]: "<<T[i]<<" D["<<i<<"]: "<<D[i];
			for (int j=0; j<6; j++) {
				cout<<"\t"<<tt[i][j];
			}cout<<endl;
		}*/
		int bet = INF;
		for (int i=tot; i<=sum; i+=5) {
			if (T[i]!=INF) {
				bet = MIN(bet,T[i]+D[i-tot]);
			}
		}
		printf("%3d\n",bet);
	}
}