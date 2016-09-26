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
int P[200000],tot;
void primes(){
	tot = 0; bool ok;
	P[tot++] = 2; P[tot++] = 3;
	for (int j=5; (j*j) < 1000000000; j+=2) {
		ok = true;
		for (int i=1; i<tot; i++) {
			if(j%P[i] == 0){ok=false; break;}
		}
		if(ok)P[tot++] = j;
	}
}

int phi(int n){
	int div=1,c;
	for (int j=0; j<tot && P[j]<n ; j++) {
		c=0;
		while ((n%P[j])==0) {
			n/=P[j]; c++;
		}
		div*=(c+1);
	}
	if(n>1) div*=2;
	return div;
}

void divisors(int A,int B){
	int max=0,n=0,c; B++;
	for (int j=A ; j<B ; j++) {
		c=phi(j);
		if(c>max){max=c; n=j;}
	}
	cout<<"Between "<<A<<" and "<<--B<<", "<<n<<" has a maximum of "<<max<<" divisors."<<endl;
}

int main(){
	primes();
	int T,A,B; cin>>T;
	while (T--) {
		cin>>A>>B;
		divisors(A,B);
	}
}