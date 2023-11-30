#include <bits/stdc++.h>

using namespace std;

int C[200001];

int main(){
	int N;
	while(cin >> N){
		for(int n=0; n<N; ++n){
			cin >> C[n];
		}
		sort(C, C+N);
		bool impossible=false;
		long double min_f = 1.0;
		
		for(int n=0;n<N; ++n){
			if(n+1 < C[n]){impossible=true; break;}
			min_f = min(min_f, (long double)(C[n])/(long double)(n+1));
		}
		if(impossible) cout << -1 << "\n";
		else{
			cout << min_f << "\n";
		}
	}
}
