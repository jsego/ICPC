/*
*  Javier Segovia
*  Accepted in 0.212
*/
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define ULL unsigned long long

char C[22];
char RES[22];
ULL S[21];
bool seen[21];

int main(){
	S[0] = S[1] = 1;
	for (ULL i=2; i<21; i++) {
		S[i] = S[i-1]*i;
	}
	int N,val; 
	ULL V,rest;
	
	scanf("%d",&N );
	while (N--) {
		string a,b="";
		cin>>a>>V;
		sort(a.begin(),a.end());
		V%=S[int(a.LE)];
		while (int(a.LE) > 2) {
			val = V/S[int(a.LE)-1];
			rest = V%S[int(a.LE)-1];
			V = rest;
			b.PB(a[val]);
			a.erase(a.begin()+val);
		}
		if(int(a.LE) == 2){
			if(V){ b.PB(a[1]); b.PB(a[0]);}
			else{b.PB(a[0]); b.PB(a[1]);}
		}
		else if(int(a.LE) == 1){
			b.PB(a[0]);
		}
		cout<<b<<endl;
	}
}