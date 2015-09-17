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
	for (int k=1; k<=kases; k++) {
		int mid,ac,n,nm;
		scanf("%d",&n);
		nm = n/2;
		for (int i=0; i<n ; i++) {
			scanf("%d",&ac);
			if(i == nm) mid=ac;
		}
		printf("Case %d: %d\n",k,mid);
	}
}