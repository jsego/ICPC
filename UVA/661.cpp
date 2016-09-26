/*
*  Javier Segovia
*  Accepted in 0.008
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
#define EPSILON 0.000000001
#define MAX(a,b) ((a)>(b)?(a):(b))

int A[22];
bool B[22];
bool used[22];

int main(){
	int N,M,C,kases=1,maxi,ac,consumption;
	while (scanf("%d %d %d",&N,&M,&C),N||M||C) {
		maxi = consumption = 0;
		for (int i=1; i<=N ; i++) {
			B[i] = used[i] = false;
			scanf("%d",&A[i]);
		}
		for (int i=0; i<M ; i++) {
			scanf("%d",&ac);
			B[ac] = !B[ac];
			if(B[ac]){
				used[ac] = true;
				consumption += A[ac];
				maxi = MAX(maxi,consumption);
			}
			else {
				consumption -= A[ac];
			}
		}
		printf("Sequence %d\n",kases++);
		if(maxi > C){
			printf("Fuse was blown.\n\n");
		}
		else {
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n\n",maxi);
		}
	}
}