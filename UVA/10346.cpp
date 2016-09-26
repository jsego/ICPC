/*
*  Javier Segovia
*  Accepted in 0.068
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
	int n,k;
	while (cin>>n>>k) {
		int remain=n%k,total=n,ac=n/k;
		while (ac) {
			total+=ac;
			remain+=ac;
			ac=remain/k;
			remain%=k;
		}
		cout<<total<<endl;
	}
}