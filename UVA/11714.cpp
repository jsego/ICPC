/*
*  Javier Segovia
*  Accepted in 0.052
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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int main(){
	int N;
	while (scanf("%d",&N) && N ) {
		int a=0,prof=-1,ext=0;
		while (N ) {
			if(ext)N++;
			ext=N&1;
			prof++;
			N>>=1;
			a+=N;
		}
		if (prof) {
			prof--;
		}
		printf("%d\n",a+prof);
	}
}