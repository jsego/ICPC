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

int main(){
	int L,C,R1,R2;
	while (cin>>L>>C>>R1>>R2,L||C||R1||R2) {
		int h1,h2;
		h1 = R1*2;
		h2 = R2*2;
		int l = L-R1-R2,c=C-R1-R2;
		int H = 0;
		if(l>0 && c>0) H = l*l+c*c;
		//cout<<"H: "<<h<<" H1: "<<h1<<" H2: "<<h2<<endl;
		if(L>=h1 && L>=h2 && C>=h1 && C>=h2 && (C>=h1+h2 || L>=h1+h2 || H>=(R1+R2)*(R1+R2) ) ) cout<<"S"<<endl;
		else cout<<"N"<<endl;
	}
}