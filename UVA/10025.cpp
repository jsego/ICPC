/*
*  Javier Segovia
*  Accepted in 0.012
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

int search(int n){
	int lm = 1,LM = 44725,lmid;
	while (lm<LM) {		
		lmid = (lm+LM)/2;
		
		if( lmid*(lmid+1) > 2*n) LM = lmid;
		else if(lmid*(lmid+1) == 2*n) return lmid;
		else lm = lmid+1;
	}
	
	while ( ( (lm*(lm+1)/2) - n) & 1) lm++;
	return lm;
}

int main(){
	int N,V;
	bool first = false;
	scanf("%d",&V);
	while (V--) {
		if(first)printf("\n");
		else first=true;
		scanf("%d",&N);
		N = (N<0?-N:N);
		printf("%d\n",search(N));
	}
}