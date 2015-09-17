/*
*  Javier Segovia
*  0.012
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

int main(){
	int kases=0,N,K,P; scanf("%d",&kases);kases++;
	for (int k=1; k<kases; k++) {
		scanf("%d %d %d",&N,&K,&P);
		printf("Case %d: %d\n",k,(K-1+P)%N + 1);
	}
}