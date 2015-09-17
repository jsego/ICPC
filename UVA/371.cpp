/*
*  Javier Segovia
*  Accepted in 0.028
*/
#include<iostream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define UI unsigned int
#define ULL unsigned long long
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))


UI A[1000000];

UI calc(ULL i){
	if(i<1000000) {
		if(A[i]) return A[i];
		if(i&1) A[i] = 1+ calc(3*i+1);
		else A[i] = 1+ calc(i/2);
		return A[i];
	}
	else {
		if(i&1) return 1+calc(3*i+1);
		else return 1+calc(i/2);
	}
}


int main(){
	UI L,H;
	for (int i=0; i<1000000; i++) {
		A[i] = 0;
	}A[1] = 1;
	while (scanf("%d %d",&L,&H), L||H) {
		UI V,m=0,ac;
		V = ac = MIN(L,H); 
		H = MAX(L,H);
		L = ac;
		for (UI i=L ; i<=H ; i++) {
			ac = calc(i);
			if(ac > m){
				V = i;
				m = ac;
			}
		}
		if(L<=1 && H>=1 && m<=3){
			V = 1; m = 4;
		}
		printf("Between %d and %d, %d generates the longest sequence of %d values.\n",L,H,V,m-1);
	}
}