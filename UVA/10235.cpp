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
bool P[1000001];
void primes(){
	P[0] = P[1] = false;
	for (int i=2; i<1000001; i++) {
		P[i] = true;
	}
	//int last=0;
	for (int j=2; j<1000001; j++) {
		if(!P[j]) continue;
	//	last = j;
		for (int k=j+j; k<1000001; k+=j) {
			P[k] = false;
		}
	}
	//cout<<last<<endl;
}

bool isEmirp(int n){
	int ini=n;
	int N=0;
	while (n ) {
		N =(N*10)+(n%10); n/=10;
	}
	
	return P[N] && (ini!=N );
}

int main(){
	primes();
	int N;
	while (scanf("%d",&N)==1) {
		if (!P[N]) {
			printf("%d is not prime.\n",N);
		}
		else{
			if(isEmirp(N)) printf("%d is emirp.\n",N);
			else printf("%d is prime.\n",N);
		}
	}
}