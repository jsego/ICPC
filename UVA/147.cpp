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

ULL D[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ULL W[30001][11];
ULL H[30001];

int main(){
	for (int i=0; i<30001; i+=5) {
		H[i] = 0;
		for (int j=0; j<11; j++) {
			if(i)W[i][j] = 0;
		}
	}
	W[0][10] = 1;
	
	for (ULL i=5; i<30001; i+=5) {
		for (int j=0; j<11; j++) {
			if(D[j]>i)break;
			int v = i-D[j];
			for (int k=j; k<11; k++) { //if(i<25)cout<<"I: "<<i<<" J: "<<j<<" K: "<<k<<" W[v][k]: "<<W[v][k]<<endl;
				W[i][j] += W[v][k];
				H[i] += W[v][k];
			}
		}
		//if(i<100) cout<<i<<" "<<H[i]<<endl;
	}
	int a,b,sum;
	char c;
	while (scanf("%d%c%d",&a,&c,&b), a || b) {
		sum = a*100 + b;
		printf("%3d.%02d%17lld\n",a,b,H[sum]);
	}
}