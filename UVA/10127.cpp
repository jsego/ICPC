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
	short mod;
	while (cin>>mod) {
		int n=1,count=1; n%=mod;
		while (n) {
			count++;
			n=(n*10)+1;
			n%=mod;
		}
		cout<<count<<endl;
	}
}