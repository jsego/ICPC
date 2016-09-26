/*
*  Javier Segovia
*  Accepted in 0.600
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
//46340
int P[10000],tot=0;

void primes(){
	P[tot++] = 2; bool ok;
	for (int i=3; i<46340; i+=2) {
		ok=true;
		for(int j=0;j<tot;j++){
			if (i%P[j] == 0) {
				ok=false; break;
			}
		}
		if (ok) {
			P[tot++] = i;
		}
	}
}

int main(){
	int N;
	primes(); scanf("%d",&N);
	while (N ) {
		printf("%d = ",N);
		bool first=true;
		if(N<0){ printf("-1"); first=false; N*=-1;}
		for (int j=0; j<tot; j++) {
			while (N>P[j] && N%P[j]==0) {
				if(!first){printf(" x %d",P[j]);}
				else {printf("%d",P[j]); first=false;}
				N/=P[j];
			}
		}
		if(N>1){
			if(!first) printf(" x %d",N);
			else printf("%d",N);
		}
		printf("\n");
		scanf("%d",&N);
	}
}