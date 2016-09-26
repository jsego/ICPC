/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int gcd(int a,int b){
	while(b>0){
		a %= b;
		swap(a,b);
	}
	return a;
}

int main(){
	int step,mod;
	while (cin>>step>>mod) {
		bool ok=gcd(step,mod)==1;
		printf("%10d%10d    %s\n\n",step,mod,(ok?"Good Choice":"Bad Choice"));
	}
}