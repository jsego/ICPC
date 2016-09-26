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
	int kases,N,last,ac; scanf("%d",&kases); kases++;
	for (int k=1; k<kases; k++) {
		scanf("%d",&N);
		int high=0,low=0;
		scanf("%d",&last);
		for (int i=1; i<N ; i++) {
			scanf("%d",&ac);
			if(ac>last) high++;
			else if(ac<last)low++;
			last = ac;
		}
		printf("Case %d: %d %d\n",k,high,low);
	}
}