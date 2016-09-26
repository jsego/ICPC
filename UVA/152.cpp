/*
*  Javier Segovia
*  Accepted in 0.100
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
#define SR(a) ((a)*(a))
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
	int A[5005],B[5005],C[5005],T=0;
	int SQ[10] = {1,4,9,16,25,36,49,64,81,100};
	scanf("%d %d %d",&A[T],&B[T],&C[T]);
	while (A[T] || B[T] || C[T]) {
		T++;
		scanf("%d %d %d",&A[T],&B[T],&C[T]);
	}
	int R[10]; for(int j=0;j<10;j++) R[j] =0;
	for(int i=0;i<T;i++){
		int val=101;
		for (int j=0; j<T; j++) {
			if(i==j) continue;
			val = MIN(val,SR(A[i]-A[j])+SR(B[i]-B[j])+SR(C[i]-C[j]));
		}
		if (val<101) {
			for (int j=0; j<10; j++) {
				if (val<SQ[j]) {
					R[j]++; break;
				}
			}
		}
	}
	for (int i=0; i<10; i++) {
		printf("%4d",R[i]);
	}printf("\n");
}