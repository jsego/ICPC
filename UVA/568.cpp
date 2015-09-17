/*
*	Javier Segovia
*	Accepted in 0.008
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
long long N[10001];
int main(){
	N[0] = N[1] = 1;
	for(int i=2;i<10001;i++){
		N[i] = (N[i-1]*i);
		while (N[i]%10==0) {
			N[i]/=10;
		}
		N[i] %= 1000000;
	}
	int num;
	while (cin>>num) {
		if(num < 10000)cout<<" ";
		if(num < 1000) cout<<" ";
		if(num < 100) cout<<" ";
		if(num < 10) cout<<" ";
		cout<<num<<" -> "<< N[num]%10 <<endl;
	}
}