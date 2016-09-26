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
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
int main(){
	int N;
	scanf("%d",&N);
	for (int i=0; i<N ; i++) {
		if(i)printf("\n");
		int a,b,c,d,A,B,C,D,x,y,X,Y;
		scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&A,&B,&C,&D );
		x = MAX(a,A);
		y = MAX(b,B);
		X = MIN(c,C);
		Y = MIN(d,D);
		if(a>=C || A>=c || b>=D || B>=d) printf("No Overlap\n");
		else {
			printf("%d %d %d %d\n",x,y,X,Y);
		}

	}
}