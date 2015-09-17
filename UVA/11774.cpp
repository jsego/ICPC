/*
*  Javier Segovia
*  Accepted in 0.052
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

unsigned long long GCD(unsigned long long A,unsigned long long B){
	if(B==0) return A;
	return GCD(B,A%B);
}
int main(){
	int kases; cin>>kases; kases++;
	for (int i=1;i<kases; i++) {
		unsigned long long n,m;
		cin>>n>>m;
		if(n==0 || m==0) cout<<"Case "<<i<<": "<<0<<endl;
		else cout<<"Case "<<i<<": "<<(n==m?2:(n+m)/GCD(n,m))<<endl;
	}
}