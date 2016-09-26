#include<iostream>

using namespace std;

int main(){
	int P; cin >> P;
	while( P-- ){
		int K, N; 
		cin >> K >> N;
		int sum = N * (N+1) / 2;
		int even = 2 * sum;
		int odd = 2 * (N * (N-1) / 2 ) + N;
		cout << K << " " << sum << " " << odd << " " << even << endl;
	}
}
