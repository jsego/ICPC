/*
*  Javier Segovia
*  Accepted in 0.000
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
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

long long gcd(long long a,long long b){
	if(b == 0) return a;
	return gcd(b,a%b);
}

int main(){
	long long n,k,km,KM;
	while (cin>>n>>k, n||k) {
		long long k1=n-k,k2=k,resU=1,resD=1,gres;
		km = MIN(k1,k2); KM = MAX(k1,k2);
		for (long long i=n ; i>KM ; i--) {
			if(km > 1){ 
				resU*=i; 
				resD*=km; 
				km--;
			}
			else {
				resU*=i;
			}
			gres = gcd(resU,resD);
			resU/=gres;
			resD/=gres;
		}
		cout<<resU/resD<<endl;
	}
}