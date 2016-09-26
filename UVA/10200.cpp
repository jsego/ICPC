/*
*  Javier Segovia
*  Accepted in 0.040
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
#define EPS 0.000000001

int P[2000];
bool seen[10000];
int A[10001];
int T;

void primes(){
	for(int i=0;i<10000;i++) seen[i] = false;
	T=0;
	for (int i=2; i<10000; i++) {
		if(seen[i]) continue;
		P[T++] = i;
		for (int j=i+i; j<10000; j+=i ) {
			seen[j] = true;
		}
	}
}

bool isPrime(int n){
	for (int i=0; i<T && P[i]<n ; i++) {
		if(n%P[i] == 0) return false;
	}
	return true;
}

int main(){
	/*cout.setf(ios::fixed);
	cout.precision(2);
	cout.precision(8);*/
	primes();
	A[0] = 1;
	for (int i=1; i<=10000; i++) {
		A[i] = A[i-1] +(isPrime(i*i+i+41)?1:0);
	}
	int a,b;
	while (cin>>a>>b) {
		int ca=0,tot=b+1-a;
		ca = A[b] - (a>0?A[a-1]:0);
		ca*=100000; //cout<<ca<<" "<<tot<<endl;
		ca/=tot;
		ca+=5;
		printf("%d.%02d\n",ca/1000,(ca%1000)/10);
		//cout<<ca/1000<<"."<<(ca%1000)/10<<endl;
	}
}