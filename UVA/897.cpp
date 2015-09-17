/*
*  Javier Segovia
*  Accepted in 0.004
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

int A[22] = {2,3,5,7,11,13,17,31,37,71,73,79,97,113,131,199,311,337,373,733,919,991};
int T = 22;

int main(){
	int N;
	while (scanf("%d",&N),N) {
		if(N>=991) printf("0\n");
		else {
			int p=1;
			while (p<=N ) {
				p*=10;
			}
			int res=0;
			for (int j=0; j<T ; j++) {
				if(A[j] > N){ res = A[j]; break;}
			}
			if(res > p) res=0;
			printf("%d\n",res);
		}
	}
}