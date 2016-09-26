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
int M[1000000];
int main(){
	int cant=0,i; M[0] = 0;
	for (i=1; cant<=10000000; i++) {
		cant+=i;
		M[i] = cant;
		//cout<<"I: "<<i<<" M: "<<M[i]<<endl;
	}
	int N;
	while(cin>>N){
		int j=0;
		for (j=1; j<i ; j++) {
			if(M[j]>=N) break;
		}
		//cout<<"J: "<<j<<endl;
		int a,b;
		if (j&1) {//N -> 1
			a = M[j]-N+1;
			b=(N-M[j-1]);
		}
		else {//1 -> N
			b = M[j]-N+1;
			a=(N-M[j-1]);
		}
		cout<<"TERM "<<N<<" IS "<<a<<"/"<<b<<endl;
	}
}