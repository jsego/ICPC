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
	unsigned int N;
	//odd sum -> sum(2n-1) = n^2
	while (scanf("%u",&N)==1) {
		long long n=N+1; n>>=1; n*=n;
		n<<=1; n--;
		n+=(n-2)+(n-4);
		printf("%lld\n",n);
	}
}