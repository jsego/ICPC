/*
*  Javier Segovia
*  0.016
*/
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int A[1001][1001],B[1001][1001],C[1001],D[1001],a,b;
int N;

int main(){
	while (scanf("%d",&N ), N ) {
		for (int i=0; i<N ; i++) {
			for (int j=0; j<N ; j++) {
				scanf("%d",&A[i][j]);
			}
		}
		for (int i=0; i<N ; i++) {
			for (int j=0; j<N ; j++) {
				scanf("%d",&B[i][j]);
			}
		}
		
		for (int i=0; i<N ; i++) {
			C[i] = i+1;
			if(C[i] == 0) C[i]++;
		}
		for (int i=0; i<N ; i++) {
			D[i] = 0;
			for (int j=0; j<N ; j++) {
				D[i] += A[i][j]*C[j];
			}
		}
		bool ok=true;
		for (int i=0; i<N ; i++) {
			a = 0;
			b = 0;
			for (int j=0; j<N ; j++) {
				a += A[i][j]*D[j];
				b += B[i][j]*C[j];
			}
			if(a != b){ ok=false; break;}
		}
		
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
}