/*
*  Javier Segovia
*  Accepted in 0.020
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
#define ULL unsigned long long

ULL D[21];
ULL W[10001][21];
ULL H[10001];

int main(){
	for (int i=0;i<21; i++) {
		D[i] = i+1;
		D[i] = D[i]*D[i]*D[i];
	}
	for (int i=0; i<10001; i++) {
		H[i] = 0;
		for (int j=0; j<21; j++) {
			if(i)W[i][j] = 0;
		}
	}
	W[0][20] = 1;
	
	for (ULL i=1; i<10001; i++) {
		for (int j=0; j<21; j++) {
			if(D[j]>i)break;
			int v = i-D[j];
			for (int k=j; k<21; k++) { //if(i<25)cout<<"I: "<<i<<" J: "<<j<<" K: "<<k<<" W[v][k]: "<<W[v][k]<<endl;
				W[i][j] += W[v][k];
				H[i] += W[v][k];
			}
		}
		//if(i<100) cout<<i<<" "<<H[i]<<endl;
	}
	int a;
	while (scanf("%d",&a)==1) {
		printf("%lld\n",H[a]);
	}
}