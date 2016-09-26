/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int A[2000000],B[2000000];
int main(){
	string AA,BB;
	while (getline(cin,AA)) {
		getline(cin,BB);
		stringstream a(AA),b(BB);
		int na=0,nb=0,ca=0,cb=0,equals=0;
		while (a>>A[na++]) {}na--;
		while(b>>B[nb++]){}nb--;
		sort(A,A+na);
		sort(B,B+nb);
		bool ok=false; 
		while (ca<na && cb<nb) {
			if(A[ca] == B[cb]){ca++;cb++;ok=true; equals++;}
			else if(A[ca]<B[cb]){ca++;}
			else {cb++;}
		}
		if(ok){
			if(equals==na && na == nb){printf("A equals B\n");}
			else if(equals==na && na<nb){printf("A is a proper subset of B\n");}
			else if(equals==nb && nb<na){printf("B is a proper subset of A\n");}
			else{printf("I'm confused!\n");}
		}
		else {
			printf("A and B are disjoint\n");
		}

	}
}