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

int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int lcm(int a,int b){
	return a*b/gcd(a,b);
}

int main(){
	int A;
	while (cin>>A,A) {
		int ac,res,last;
		cin>>ac; res=A-ac; last=ac;
		while (cin>>ac,ac) {
			res = gcd(res,last-ac);
			//res2 = lcm(res2,ac);
		}
		cout<<(res<0?-res:res)<<endl;
		//cout<<res<<" "<<res2<<endl;
	}
}