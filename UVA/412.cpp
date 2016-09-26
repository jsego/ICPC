/*
*  Javier Segovia
*  Accepted in 0.100
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
int S[60];

int gcd(int a,int b){
	int t;
	while (b) {
		t=a;
		a=b;
		b=t%b;
	}
	return a;
	/*
	if (b==0) return a;
	return gcd(b,a%b);*/
}

int main(){
	int N;
	while (scanf("%d",&N ), N ) {
		for (int i=0; i<N ; i++) {
			scanf("%d",&S[i]);
		}
		int T = N*(N-1);T>>=1;
		int sum=0;
		for (int i=0; i<N ; i++) {
			for (int j=i+1; j<N ; j++) {
				if (gcd(S[i],S[j]) == 1) {
					sum++;
				}
			}
		}
		if(sum>0) printf("%.6lf\n", sqrt(6*(double)(T+0.000000001)/(double)(sum+0.000000001)));
		else {
			printf("No estimate for this data set.\n");
		}

	}
}