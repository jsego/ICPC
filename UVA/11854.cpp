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

int main(){
	int A[3];
	while (scanf("%d %d %d",&A[0],&A[1],&A[2]), A[0]||A[1]||A[2]) {
		sort(A,A+3);
		if((A[0]*A[0] + A[1]*A[1]) == A[2]*A[2]) printf("right\n");
		else printf("wrong\n");
	}
}