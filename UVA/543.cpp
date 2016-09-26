/*
*  Javier Segovia
*  Accepted in 0.232
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
int P[50000],tot;
void primes(){
	tot=1; P[0] = 3; bool ok;
	for (int i=5; i<500000; i+=2) {
		ok=true;
		for (int j=0; j<tot; j++) {
			if (i%P[j]==0) {
				ok=false; break;
			}
			if(P[j]>1000) break;
		}
		if (ok) {
			P[tot++] = i;
		}
	}
	
	
}

bool isPrime(int n ){
	for (int i=0; i<tot; i++) {
		if(n == P[i] || P[i]>1000)return true;
		if((n % P[i]) == 0) return false;
	}
	return true;
}
int main(){
	primes();
	int N;
	while (cin>>N && N ) {
		int mid = N>>1;
		int a=-1,b=-1;
		for (int j=0;P[j]<=mid; j++) {
			if(isPrime(N-P[j])){
				a = P[j]; b = N-P[j]; break;
			}
		}
		if(a!=-1) cout<<N<<" = "<<a<<" + "<<b<<endl;
		else cout<<"Goldbach's conjecture is wrong."<<endl;
	}
}