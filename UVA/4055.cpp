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
	int B,S,kases=1;
	while (scanf("%d %d",&B,&S), (S||B) ) {
		if(B<=1) printf("Case %d: :-\\\n",kases++);
		else if(S>=B) printf("Case %d: :-|\n",kases++);
		else {
			printf("Case %d: :-(\n",kases++);
		}

	}
}