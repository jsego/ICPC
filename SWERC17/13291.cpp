#include <bits/stdc++.h>

using namespace std;

long long A[3], B[3];

int main(){
	int N;
	while(cin >> N){
		for(int i = 0; i < 3; i++) A[i] = B[i] = 0;
		int a, b;
		for(int i = 0; i < N; i++){
			cin >> a;
			A[i%3] += a;
		}
		for(int i = 0; i < N; i++){
			cin >> b;
			B[i%3] += b;
		}
		long long white = 0, yellow = 0, pink = 0;
		white += (B[0]*A[0]) + (B[1]*A[2]) + (B[2]*A[1]);
		yellow += (B[1]*A[0]) + (B[0]*A[1]) + (B[2]*A[2]);
		pink += (B[2]*A[0]) + (B[1]*A[1]) + (B[0]*A[2]);
		cout << yellow << " " << pink << " " << white << "\n";
	}
}

