/*
*  Javier Segovia
*  Accepted in 0.340
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int P[1001];
bool seen[1001];
int N;

void primes(){
	for (int i=0; i<1001; i++) {
		seen[i] = false;
	}
	N=0;
	for (int i=2; i<1001; i++) {
		if(seen[i])continue;
		P[N++] = i;
		for (int j=i+i ; j<1001; j+=i ) {
			seen[i] = true;
		}
	}
}

int NOD(int n){
	int res=1,ac;
	for (int i=0; i<N ; i++) {
		ac=1;
		while (n%P[i] == 0) {
			ac++;
			n/=P[i];
		}
		res*=ac;
	}
	if(n>1) res*=2;
	return res;
}

int search(int n,vector<int> &V){
	int a=0,b=int(V.SL),mid;
	while (a<b) {
		mid = (a+b) /2;
		if(V[mid]<n) a = mid+1;
		else b = mid;
	}
	return a;
}

int main(){
	primes();
	map<int,int> M;
	vector<int> V;
	int ni=1;
	while (ni<1000001) {
		V.PB(ni);
		ni = ni + NOD(ni);
	}
	int kases,A,B; scanf("%d",&kases);
	for(int k=1;k<=kases;k++){
		scanf("%d %d",&A,&B);
		A = search(A,V);
		int b = search(B,V);
		if(b==int(V.SL) || V[b]>B) b = b-1;
		printf("Case %d: %d\n",k,b + 1 - A);
	}
}