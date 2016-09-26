/*
*  Javier Segovia
*  Accepted in 0.016
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
long long A[100];
int mini,maxi,n;
int main(){
	A[0] = A[1] = 1;
	long long lim = 622702080; lim*=10;
	for (int i=2; i<100; i++) {
		if (A[i-1]*i > lim) {
			maxi = i; break;
		}
		else if(A[i-1]*i<10000){
			mini = i;
		}
		A[i] = A[i-1]*i;
	}
	mini++; maxi--;
	while (scanf("%d",&n) == 1) {
		if(n&1 && n<0) printf("Overflow!\n");
		else if(n<0) printf("Underflow!\n");
		else if (n<mini) {
			printf("Underflow!\n");
		}
		else if(n>maxi){
			printf("Overflow!\n");
		}
		else {
			printf("%lld\n",A[n]);
		}

	}
}