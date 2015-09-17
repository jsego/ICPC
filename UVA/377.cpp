/*
*  Javier Segovia
*  Accepted in 0.004
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

map<string,string > M;

void add(string &b,string &a){
	//cout<<a<<" "<<b<<endl;
	string res = b,ac;
	char carry = 'V',lastcarry='V',c1,c2,sumi;
	for (int i=int(a.LE)-1; i>=0; i--) {
		ac=a.substr(i,1) + b.substr(i,1);
		sumi = M[ac][0];
		carry = lastcarry;
		//cout<<"I: "<<i<<endl;
		//cout<<"AC: "<<a[i]<<"+"<<b[i]<<"+"<<carry<<endl;
		c1 = M[ac][1];
		ac[0] = sumi; 
		ac[1] = carry;
		res[i] = M[ac][0];
		c2 = M[ac][1];
		ac[0] = c1; ac[1] = c2;
		lastcarry = M[ac][0];
		//cout<<"I : "<<i<<" "<<a[i]<<"+"<<b[i]<<" = "<<res[i]<<" -> carry: "<<carry<<" sumi: "<<sumi<<endl;
	}
	b = res;
}

void move_left(string &b){
	b = b.substr(1)+"V";
	
}

void move_right(string &b){
	b = "V" + b.substr(0,int(b.LE)-1);
}

int main(){
	string a,b,res,op;
	int kases;
	cin>>kases;
	M["VV"] = "VV";
	M["VU"] = "UV";
	M["VC"] = "CV";
	M["VD"] = "DV";
	M["UV"] = "UV";
	M["UU"] = "CV";
	M["UC"] = "DV";
	M["UD"] = "VU";
	M["CV"] = "CV";
	M["CU"] = "DV";
	M["CC"] = "VU";
	M["CD"] = "UU";
	M["DV"] = "DV";
	M["DU"] = "VU";
	M["DC"] = "UU";
	M["DD"] = "CU";
	cout<<"COWCULATIONS OUTPUT"<<endl;
	while (kases--) {
		cin>>a>>b;
		a = string(8-int(a.LE),'V')+a;
		b = string(8-int(b.LE),'V')+b;
		for (int i=0; i<3; i++) {
			cin>>op;
			if(op == "A") add(b,a);
			else if(op == "R") move_right(b);
			else if(op == "L") move_left(b);
		}
		cin>>res;
		res = string(8-int(res.LE),'V') + res;
		//cout<<"A: "<<a<<" B: "<<b<<" RES: "<<res<<endl;
		if(b == res) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
}