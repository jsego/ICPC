/*
*  Javier Segovia
*  Accepted in 0.092
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int main(){
	int N; scanf("%d",&N);
	while (N) {
		printf("f91(%d) = %d\n",N,(N>100?N-10:91));
		scanf("%d",&N );
	}
}