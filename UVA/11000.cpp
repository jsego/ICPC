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
unsigned int res[45][2];
int main(){
	int N; scanf("%d",&N );
	res[0][0] = 0; res[0][1] = 1;
	res[1][0] = 1; res[1][1] = 2;
	for (int i=2; i<45; i++) {
		res[i][0] = res[i-1][1];
		res[i][1] = res[i][0]+res[i-1][0]+1;
		//if(res[i][1]+res[i][0] < res[i-1][1]+res[i-1][0]) {cout<<"I: "<<i<<endl; break;}
	}
	while (N>-1) {
		printf("%u %u\n",res[N][0],res[N][1]);
		scanf("%d",&N);
	}
}