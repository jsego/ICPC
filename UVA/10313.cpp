/*
*  Javier Segovia
*  Accepted in 0.288
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define ULL unsigned long long
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))


ULL W[301][301];


int main(){
	
	for (int i=0; i<301; i++) {
		for (int j=0; j<301; j++) {
			W[i][j] = 0;
		}
		W[0][i] = 1;
	}
	for (ULL i=1; i<301; i++) {
		for (int j=1; j<301; j++) {
			if(j>i) W[i][j] = W[i][j-1];
			else W[i][j] = W[i-j][j] + W[i][j-1];
		}
	}
	string s;
	int A[3];
	
	while (getline(cin,s)) {
		istringstream iss(s);
		int n=0;
		while (iss>>A[n]) {n++;}
		int lim1 = -1,lim2 = 300;
		if(n == 2){
			lim2 = MIN(A[1],300);
		}
		else if(n == 3){
			lim1 = MIN(A[1],A[2])-1;
			lim2 = MIN(MAX(A[1],A[2]),300);
		}
		if(lim1 < 0) cout<<W[A[0]][lim2]<<endl;
		else cout<<W[A[0]][lim2]-W[A[0]][lim1]<<endl;
	}
}