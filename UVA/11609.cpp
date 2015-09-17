/*
*  Javier Segovia
*  Accepted in 0.016
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
#define MOD 1000000007

long long power(int n){
	long long r = 1,exp=2;
	while (n) {
		if (n&1) {
			r=(r*exp)%MOD;
		}
		exp=(exp*exp)%MOD;
		n>>=1;
		//cout<<"R: "<<r<<" EXP: "<<exp<<" N: "<<n<<endl;
	}
	return r;
}

int main(){
	int T; cin>>T;
	for (int t=1; t<=T; t++) {
		int N;
		cin>>N;
		long long res = (N*power(N-1))%MOD;
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
}