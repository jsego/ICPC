#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int T[10000];
int tot=1;
void primes(){
	T[0] = 2;
	for (int i=3; i<10000; i+=2) {
		bool ok=true;
		for (int j=0; j<tot; j++) {
			if (i%T[j]==0) {
				ok=false; break;
			}
		}
		if(ok) T[tot++]=i;
	}
}

bool isPrime(int n){
	if(n<2)return false;
	for (int i=0; i<tot; i++) {
		if (n==T[i]) {
			return true;
		}
		if (n%T[i]==0) {
			return false;
		}
	}
	return true;
}

int main(){
	int kases; cin>>kases;
	primes();
	while (kases--) {
		string s; int A=0,n;
		cin>>s;
		sort(s.begin(),s.end());
		set<int> SS; 
		set<int>::iterator it;
		do{
			for (int i=0; i<(int)s.LE; i++) {
				for (int j=0; j+i<(int)s.LE; j++) {
					string a = s.substr(j,i+1);
					istringstream is(a);
					is>>n;
					it = SS.find(n);
					if (it!=SS.end()) {
						continue;
					}
					SS.insert(n);
					A+=isPrime(n);
				}
			}
		}while (next_permutation(s.begin(),s.end()));
		cout<<A<<endl;
	}
}