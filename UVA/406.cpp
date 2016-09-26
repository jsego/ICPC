/*
*  Javier Segovia
*  Accepted in 0.064
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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int A[1005],C[1005],tot;
bool B[1005];

void primes(){
	for(int i=0;i<1001;i++) B[i] = false;
	tot=0; C[0] = 0; C[1] = 1;
	A[tot++] = 1; 
	for (int i=2; i<1001; i++) {
		if(B[i]){C[i] = tot; continue;}
		A[tot++] = i;
		C[i] = tot;
		for (int j=i+i; j<1001; j+=i ) {
			B[j] = true;
		}
	}
}

int main(){
	int N,Q,ac,lmin,lmax;
	primes();
	while (scanf("%d %d",&N,&Q) == 2) {
		printf("%d %d:",N,Q);
		ac = C[N];
		if(ac&1){
			lmin = MAX((ac>>1)-Q+1,0);
			lmax = MIN(lmin+Q*2-1,ac);
		}
		else {
			lmin = MAX((ac>>1)-Q , 0);// 5 >>1 = 2 ; Q = (2) ; 2-2,0
			lmax = MIN(lmin+Q*2,ac); //   0 1 | 2 | 3 4  --->  2
		}
		for (int i=lmin; i<lmax; i++) {
			printf(" %d",A[i]);
		}printf("\n\n");

	}
}