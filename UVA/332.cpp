/*
*  Javier Segovia
*  Accepted in 0.188
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

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main(){
	int kases=1;
	int j,k,v1,v2,val,div,d1,d2;
	string s,a,b;
	while (cin>>j , j!=-1) {
		cin>>s;
		v1=v2=0;
		d1=d2=1;
		for (int i=0; i<j; i++) {
			d1*=10;
		}
		k = int(s.LE)-2-j;
		for (int i=0; i<k ; i++) {
			d1*=10; d2*=10;
		}
		istringstream iss(s.substr(2)),iss2(s.substr(2,k));
		iss>>v1; iss2>>v2;
		if(j>0) val = v1-v2;
		else val = v2;
		if(j>0) div = d1-d2;
		else div = d2;
		//cout<<"VAL "<<val<<" DIV: "<<div<<endl;
		int res = gcd(val,div);
		if(res==0){val=0; res =div=1;}
		cout<<"Case "<<kases++<<": "<<val/res<<"/"<<div/res<<endl;
	}
}