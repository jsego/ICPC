/*
*  Javier Segovia
*  Accepted in 0.016
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
#define NC 5

ULL D[NC] = {1,5,10,25,50};
ULL W[30001][NC];
ULL H[30001];

int main(){
	for (int i=0; i<30001; i+=5) {
		H[i] = 0;
		for (int j=0; j<6; j++) {
			if(i)W[i][j] = 0;
		}
	}
	W[0][NC-1] = 1;
	
	for (ULL i=1; i<30001; i++) {
		for (int j=0; j<NC; j++) {
			if(D[j]>i)break;
			int v = i-D[j];
			for (int k=j; k<NC; k++) {
				W[i][j] += W[v][k];
				H[i] += W[v][k];
			}
		}
	}
	H[0] = 1;
	int a;
	while (scanf("%d",&a)==1) {
		if(H[a] == 1) printf("There is only 1 way to produce %d cents change.\n",a);
		else printf("There are %lld ways to produce %d cents change.\n",H[a],a);
	}
}