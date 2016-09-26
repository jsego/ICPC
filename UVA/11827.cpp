/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))

int V[105],T;

long long gcd(long long a,long long b){
	if(b == 0) return a;
	return gcd(b,a%b);
}


int main(){
	int kases; cin>>kases;
	string s; getline(cin,s);
	while (kases--) {
		T=0;
		getline(cin,s);
		istringstream iss(s);
		while (iss>>V[T]) {T++; }//cout<<"V["<<T-1<<"]: "<<V[T-1]<<endl;}
		long long maxi = 1,val;
		for (int i=0; i<T ; i++) {
			for (int j=i+1; j<T ; j++) {
				val = gcd(V[i],V[j]); //cout<<"GCD: ("<<V[i]<<","<<V[j]<<") "<<val<<endl;
				maxi = MAX(maxi,gcd(V[i],V[j]));
			}
		}
		cout<<maxi<<endl;
	}
}