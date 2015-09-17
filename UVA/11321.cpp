/*
*  Javier Segovia
*  Accepted in 0.236
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

pair<int,pair<int,int> > A[10005];
int N,M;

int modu(int a,int m){
	if(a<0){
		a*=-1;
		a%=m;
		return a*=-1;
	}
	return a%m;	
}
int main(){
	while (scanf("%d %d",&N,&M), (N||M)) {
		printf("%d %d\n",N,M); 
		int ac,modi,nonodd;
		for (int m=0; m<N ; m++) {
			cin>>ac;
			modi = modu(ac,M);
			nonodd = (ac&1);
			if(nonodd) ac*=-1;
			nonodd=!nonodd;
			A[m] = MP(modi,MP(nonodd,ac));
		}
		sort(A,A+N);
		for (int i=0; i<N ; i++) {
			printf("%d\n",(A[i].second.second)*((A[i].second.first)?1:-1));
		}
	}
	printf("0 0\n");
}