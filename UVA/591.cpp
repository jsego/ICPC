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
int A[55];
int main(){
	int kases=1;
	int n; scanf("%d",&n);
	while (n) {
		int tot=0,moves=0;
		for(int i=0;i<n;i++) {scanf("%d",&A[i]); tot+=A[i];}
		tot/=n;
		for(int i=0;i<n;i++) if(A[i]>tot) moves += A[i]-tot;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",kases++,moves);
		scanf("%d",&n);
	}
}