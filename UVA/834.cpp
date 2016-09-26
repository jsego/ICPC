/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int main(){
	int A,B,aux;
	while (scanf("%d %d",&A,&B)==2) { 
		printf("[%d;",A/B);
		aux = A; 
		A = B; 
		B = aux%B; 
		printf("%d",A/B);
		while (B>1) {
			aux = A; A = B; B = aux%B;
			printf(",%d",A/B);
		}
		printf("]\n");
	}
}