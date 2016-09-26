/*
 *  Javier Segovia
 *  0.008
 */
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SQ(a) ((a)*(a))
#define TRI(a) ((a)*(a)*(a))
#define QUA(a) ((a)*(a)*(a)*(a))
long long S[101][5];
int main(){
	int N;
	long long r2,r3,r4;
	for(int i=0;i<101;i++)for(int j=0;j<5;j++) S[i][j] = 0;
	for (int i=1; i<101; i++) {
		S[i][2] = S[i-1][2] + i*i;
		S[i][3] = S[i-1][3] + i*i*i;
		S[i][4] = S[i-1][4] + i*i*i*i;
	}
	while (cin>>N ) {
		if(N){	
			r2 = N*N*(N+1)*(N+1)/4;
			r3 = r2*N*(N+1)/2;
			r4 = r3*N*(N+1)/2;
			cout<<S[N][2]<<" "<<r2-S[N][2]<<" ";
			cout<<S[N][3]<<" "<<r3-S[N][3]<<" ";
			cout<<S[N][4]<<" "<<r4-S[N][4]<<endl;
		}
		else{
			cout<<"0 0 0 0 0 0"<<endl;
		}
	}
}