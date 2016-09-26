/*
*  Javier Segovia
*  Accepted in 0.008
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
int A[32];

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int calc(string &a){
	int pos=0,res=0;
	for (int i=int(a.LE)-1; i>=0; i--,pos++) {
		if(a[i] == '1'){res+=A[pos];}
	}
	return res;
}

int main(){
	A[0] = 1;
	for (int i=1; i<30; i++) {
		A[i] = A[i-1]<<1;
	}
	int N; cin>>N;
	for (int i=1; i<= N ; i++) {
		string a,b;
		cin>>a>>b;
		int va=0,vb=0;
		va = calc(a);
		vb = calc(b);
		//cout<<"VA: "<<va<<" VB: "<<vb<<endl;
		if(gcd(va,vb) < 2) cout<<"Pair #"<<i<<": Love is not all you need!"<<endl;
		else cout<<"Pair #"<<i<<": All you need is love!"<<endl;
	}
}