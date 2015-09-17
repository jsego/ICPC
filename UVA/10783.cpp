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
	int kases; cin>>kases;
	for (int k=1; k<=kases; k++) {
		int a,b;
		cin>>a>>b; 
		if((a&1) == 0)a++;
		if((b&1) == 0) b--;
		int n=(b-a); 
		n>>=1; 
		n++;
		int res = (a+b)*(n/2);
		if(n&1)res+=((a+b)/2);
		cout<<"Case "<<k<<": "<<res<<endl;
	}
}