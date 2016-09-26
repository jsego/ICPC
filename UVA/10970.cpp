/*
 *  Javier Segovia
 *  0.532
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
	int N,M;
	while (cin>>N>>M) {
		int maxi,mini,cuts=0;
		maxi = MAX(N,M);
		mini = MIN(N,M);
		cuts = (maxi-1) + maxi*(mini-1);
		cout<<cuts<<endl;
	}
}