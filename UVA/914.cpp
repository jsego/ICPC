/*
*  Javier Segovia
*  Accepted in 0.388
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))

int P[400];
int T;

void primes(){
	T = 1;
	P[0] = 2;
	bool ok=true;
	for (int i=3; i*i<1000000; i+=2) {
		ok=true;
		for (int j=0; j<T ; j++) {
			if(i%P[j] == 0){ ok=false;  break;}
		}
		if(ok){
			P[T++] = i;
		}
	}
}

bool isPrime(int n){
	for (int j=0; j<T && P[j]<n ; j++) {
		if(n%P[j] == 0) 
			return false;
	}
	//cout<<"Prime: "<<n<<endl;
	return true;
}

int main(){
	primes(); //cout<<T<<endl;
	int kases; cin>>kases;
	while (kases--) {
		int a,b,last=-1; 
		cin>>a>>b;
		map<int,int> M;
		for (int i=MAX(a,2); i<=b ; i++) {
			if(isPrime(i)){
				if(last != -1){
					//cout<<"I: "<<i<<" LAST: "<<last<<endl;
					M[i-last]++; 
				}
				last = i;
			}
		}
		int maxi = -1,pos=-1;
		bool ok=false;
		for (map<int,int>::iterator it = M.begin(); it!=M.end(); it++) {
			//cout<<it->first<<" "<<it->second<<" "<<maxi<<endl;
			if(it->second > maxi){ok=true; maxi = it->second; pos = it->first;}
			else if(it->second == maxi){ok=false; }
		}
		if(!ok) cout<<"No jumping champion"<<endl;
		else cout<<"The jumping champion is "<<pos<<endl;
	}
}