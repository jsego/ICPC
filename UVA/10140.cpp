/*
*  Javier Segovia
*  Accepted in 0.016
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
#define INF 2000000000

unsigned int P[5000];
bool seen[46341];
bool V[1000002];
unsigned int T;

void primes(){
	for(int i=0;i<46341;i++) seen[i] = false;
	T=0;
	for (unsigned int i=2; i<46341; i++) {
		if(seen[i]) continue;
		P[T++] = i;
		for (unsigned int j=i+i; j<46341; j+=i ) {
			seen[j] = true;
		}
	}
}

bool isPrime(unsigned int n){
	for (unsigned int i=0; i<T && P[i]<n ; i++) {
		if(n%P[i] == 0) return false;
	}
	return true;
}

int main(){
	primes(); //cout<<T<<endl;
	unsigned int a,b;
	while (cin>>a>>b ) {
		unsigned int ma=-1,mb=-1,mA=-1,mB=-1,dist;
		unsigned int mini=INF,maxi=0,last=0;
		if(a<2) a=2;
		for (int i=0; i+a<b+1; i++) {
			V[i] = false;
		}
		for (unsigned int j=0; j<T ; j++) {
			if(P[j]>b) break;
			if(P[j]<a ) dist = ((a/P[j])+(a%P[j]?1:0))*P[j] - a;//dist = P[j] - a%P[j];
			else dist = (P[j]-a)+P[j];
			while (dist+a <= b) {
				//cout<<"D: "<<dist+a<<" FROM: "<<dist<<" P: "<<P[j]<<endl;
				V[dist] = true;
				dist+=P[j];
			}
		}
		for (unsigned int i=0; i+a<b+1 ; i++) {
			//cout<<"I: "<<i<<" V: "<<V[i]<<endl;
			if (!V[i]) {
				if(last!=0){
					if(i+a<mini+last){mini = a+i-last; ma = last; mb = a+i;}
					if(i+a>maxi+last){maxi = a+i-last; mA = last; mB = a+i;}
				}
				last = a+i;
			}
		}
		if(mini == INF) cout<<"There are no adjacent primes."<<endl;
		else cout<<ma<<","<<mb<<" are closest, "<<mA<<","<<mB<<" are most distant."<<endl;
	}
}