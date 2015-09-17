/*
*  Javier Segovia
*  Accepted in 0.240
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
bool seen[65001],A[65001];
void primes(){
	for(int j=0;j<65001;j++) A[j] = seen[j] = false;
	for (int j=2; j<65001; j++) {
		if(seen[j])continue;
		A[j] = true;
		for (int k=j; k<65001; k+=j) {
			seen[k] = true;
		}
	}
}

int expo(int a,int n){
	long long res=1,base=a;
	int mod=n;
	while (n ) {
		if (n&1) {
			res=(res*base)%mod;
		}
		base=(base*base)%mod;
		n>>=1;
	}
	return (int)res;
}

bool isCar(int n){
	for (int i=2; i<10; i++) {
		int a=rand()%n; //if(a<2)a=2;
		if (expo(a,n)!=a) {
			return false;
		}
	}
	return true;
}

int main(){
	primes();
	int N;
	while (cin>>N && N ) {
		bool b=isCar(N);		
		if (b) {
			if (A[N]) {
				cout<<N<<" is normal."<<endl;
			}
			else {
				cout<<"The number "<<N<<" is a Carmichael number."<<endl;
			}
		}
		else {
			cout<<N<<" is normal."<<endl;
		}
		//N++;
	}
}