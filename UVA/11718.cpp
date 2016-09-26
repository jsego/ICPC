/*
*  Javier Segovia
*  Accepted in 0.048
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

long long power(long long b,long long e,long long mod){
	long long res=1;
	while (e) {
		if (e&1) {
			res = (res*b)%mod;
		}
		b = (b*b)%mod;
		e>>=1;
	}
	return res;
}

int main(){
	int kases; cin>>kases;
	for (int i=1; i<=kases; i++) {
		long long N,K,MOD,tot=0,ac; 
		cin>>N>>K>>MOD;
		for (int q=0; q<N ; q++) {
			cin>>ac; tot+=ac;
		}
		tot %= MOD;
		tot = (tot*K)%MOD;
		tot = (tot * power(N,K-1,MOD))%MOD;
		cout<<"Case "<<i<<": "<<tot<<endl;
	}
	
}