/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	int N;
	cout<<"PERFECTION OUTPUT"<<endl;
	while (cin>>N && N ) {
		int res=1,mid=N>>1;
		if(N==1 || N==-1){res = 0;}
		for (int i=2;i<=mid; i++) {
			if(N%i==0) res+=i;
		}
		string s;
		if(res==N) s = "PERFECT";
		else if(res>N) s="ABUNDANT";
		else s="DEFICIENT";
		printf("%5d  ",N);
		cout<<s<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
}