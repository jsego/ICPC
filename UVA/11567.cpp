/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define UI unsigned int
#define MIN(a,b) ((a)<(b)?(a):(b))


UI ac1,ac2,c1,c2;

UI solve(UI N){
	//cout<<N<<endl;
	if(N < 4) return N;
	if(N&1){
		c1 = 0; ac1 = N-1; while(ac1 && ! (ac1&1)){ ac1>>=1; c1++;}
		c2 = 0; ac2 = N+1; while(ac2 && ! (ac2&1)){ ac2>>=1; c2++;}
		if(c1 >= c2)return 1+solve(N-1);
		else return 1+solve(N+1);
	}
	return 1+solve(N/2);
}

int main(){
	UI N;
	while (scanf("%d",&N) == 1) {//cout<<endl;
		printf("%d\n",solve(N));
	}
}