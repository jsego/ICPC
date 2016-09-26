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

int main(){
	int K,N,M;
	while (scanf("%d",&K),K) {
		int a,b;
		scanf("%d %d",&N,&M);
		while (K--) {
			scanf("%d %d",&a,&b);
			if(a == N || b == M) printf("divisa\n");
			else if(a < N){
				if(b < M){
					printf("SO\n");
				}
				else {
					printf("NO\n");
				}
			}
			else{
				if(b<M){
					printf("SE\n");
				}
				else {
					printf("NE\n");
				}
			}
		}
	}
}