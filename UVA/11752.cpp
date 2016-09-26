/*
*  Javier Segovia
*  Accepted in 0.036
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define UL unsigned long long
#define LIM 65536
#define EXP 64
UL C[10000000],tot=0;
int A[LIM];
bool B[LIM]; int P=0;
bool powers[EXP];
void primes(){
	for(int i=0;i<LIM;i++) B[i] = false;
	for (UL i=2; i<LIM; i++) {//cout<<i<<endl;
		if(B[i])continue;
		A[P++] = i;
		for (UL j=i*i ; j<LIM; j*=i) {
			B[j] = true;
		}
	}
}
void cribe(){
	powers[0] = powers[1] = false;
	for(int i=2;i<EXP;i++) powers[i]=true;
	for(int i=2;i<EXP;i++){
		if(!powers[i])continue;
		for (int j=i+i ; j<EXP; j+=i ) {
			powers[j] = false;
		}
	}
}
int main(){
	primes();
	cribe();
	cout<<1<<endl;
	for (int i=0; i<P ; i++) {
		UL n=1,last;
		bool ok=true; int cont=0;
		for (int j=2; j<EXP && ok; j++) {
			if(powers[j])continue;
			while (cont<j && ok) {
				last=n ;
				n*=A[i];
				ok&=(n/A[i]) == last;
				cont++;
			}
			if(ok)C[tot++] = n;
			else break;
		}
	}
	sort(C,C+tot);
	for (UL i=0; i<tot; i++) { 
		printf("%llu\n",C[i]);
	}
}