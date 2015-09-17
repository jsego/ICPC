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
int B,P,M,R;
void expo(){
	int base=B; if(B==0){R=0; return;}
	while (P) {
		if(P&1)R =(R*base)%M;
		base=(base*base)%M;
		P>>=1;
	}
}
int main(){
	while (cin>>B>>P>>M ) {
		B%=M; 
		R = 1;
		expo();
		cout<<R<<endl;
	}
}