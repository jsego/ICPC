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
	int kases; scanf("%d",&kases);
	while (kases--) {
		int sc,diff;
		scanf("%d %d",&sc,&diff);
		//x+y = sc ; x-y = diff;
		//-> sc-y = diff+y; sc-diff = 2y;
		sc-=diff;
		if (sc<0 || sc&1) {
			printf("impossible\n");
		}
		else {
			sc>>=1;
			printf("%d %d\n",sc+diff,sc);
		}

	}
}