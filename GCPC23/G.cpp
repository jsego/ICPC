#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		int res = 0;
		// First 10 digits
		for(int i=0; i < 10; ++i)
			if(i <= n) ++res;
		// Extra 0s
		for(int i=1000000000; i >= 100; i/=10){
			if(i <= n) ++res;
		}
		// Each iiii... repetitions for i in [1,9]
		for(int i=1; i<10; ++i){
			int base = i*11;
			for(int j=0; j<8; j++){
				if(n < base) break;
				++res;
				base = (base*10) + i;
			}
		}
		cout << res << "\n";
	}

}
