/*
*  Javier Segovia
*  Accepted in 0.016
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

short P[45];
short T;
short A[45];

void primes(){
	T=0;
	P[T++] = 2;
	bool ok=true;
	for (int i=3; i*i<32768; i+=2) {
		ok=true;
		for (int j=0; j<T ; j++) {
			if(i%P[j] == 0){ ok=false; break;}
		}
		if(ok){
			P[T++] = i;
		}
	}
}

short expo(short b,short e){
	short res=1,base=b;
	while (e) {
		if(e&1){
			res*=base;
		}
		base = base*base;
		e>>=1;
	}
	return res;
}

int main(){
	primes();// cout<<T<<endl;
	short a,e,tot;
	string s;
	while (getline(cin,s),s!="0") {
		istringstream iss(s);
		tot=1;
		while (iss>>a>>e) {
			tot*=expo(a,e);
		}
		tot--; //cout<<"SEARCH: "<<tot<<endl;
		//factorize
		for (int i=0; i<T ; i++) {
			A[i] = 0;
			while (tot>1 && tot%P[i] == 0) {
				tot/=P[i];
				A[i]++;
			}
		}
		bool first=true;
		if(tot > 1){first=false; cout<<tot<<" "<<1;}
		for (int i=T-1; i>=0; i--) {
			if(A[i]){
				if(!first) cout<<" ";
				else first=false;
				cout<<P[i]<<" "<<A[i];
			}
		}cout<<endl;
	}
}