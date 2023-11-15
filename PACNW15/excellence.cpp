#include<bits/stdc++.h>

using namespace std;

int S[100001];

int main(){
	int N;
	while(cin >> N){
		for(int i=0; i < N; i++) cin >> S[i];
		sort(S, S+N);
		int maxi = 4000000;
		for(int i=0; i*2 < N; i++){
			maxi = min(maxi, S[i]+S[N-1-i]);
		}
		cout << maxi << "\n";
	}
}

