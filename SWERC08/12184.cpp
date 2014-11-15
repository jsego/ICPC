#include<iostream>
#include<algorithm>
using namespace std;

unsigned gcd(unsigned a, unsigned b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	int kases; cin>>kases;
	while(kases--){
		int C; cin>>C;
		unsigned N = 0, maxi = 0;
		while(C--){
			unsigned sum = 0, a, t;
			for(int i=0;i<9;i++){
				cin>>a; sum+=a;
			}cin>>t; 
			if(N == 1) continue;
			if(sum < t){ N = 1; continue; }
			sum -= t;
			maxi = max(maxi, t);
			N = gcd(N, sum);			
		}
		if(N < 2 || maxi >= N) cout<<"impossible"<<endl;
		else cout<<N<<endl;
	}
}
