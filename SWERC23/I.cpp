#include <bits/stdc++.h>

using namespace std;

int main(){
	int M, N;
	while(cin >> M >> N){
		unsigned long long sumA=0, A, sumB=0, B;
		for(int i=0; i<M; i++){ cin >> A; sumA += (A+1);}
		for(int i=0; i<N; i++){ cin >> B; sumB += (B+1);}
		if(sumA > sumB) cout << "ALICE\n";
		else if(sumA == sumB) cout << "TIED\n";
		else cout << "BOB\n";
	}
}
