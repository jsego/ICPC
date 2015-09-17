/*
*  Javier Segovia
*  Accepted in 0.088
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define MIN(a,b) ((a)<(b)?(a):(b))

int C,NU[5005],D[5005],T,N,K,DP[5005];

int calc(){
	DP[0] = 0;
	for (int i=1; i<=K; i++) {
		int lim = i,ac=(N-3*(K-i)-1); lim<<=1;
		//j == chopstick max index
		//lim == number of pairs used
		for (int j=ac;j>=lim;j--) {
			DP[j] = DP[j-2]+D[j];
		}
		//assign and find every minimum pair until J
		for (int j=lim+1; j<=ac; j++) {
			DP[j] = MIN(DP[j],DP[j-1]);
		}
		//assign the pair found to the third element
		DP[ac+1] = DP[ac];
	}
	return DP[N];
}

int main(){
	scanf("%d",&T);
	while (T--) {
		scanf("%d %d",&K,&N);
		K+=8;
		for (int i=0; i<N ; i++) {
			scanf("%d",&NU[i+1]);
			DP[i+1]=0;
		}
		D[0] = 0;
		//badness
		for (int i=1; i<N ; i++) {
			D[i] = NU[i]-NU[i-1];
			D[i] *= D[i];
		}
		printf("%d\n",calc());
	}
}