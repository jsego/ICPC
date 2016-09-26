#include<iostream>

using namespace std;

int K[31];

int main(){
	K[0] = 0; K[1] = 2;
	for(int i = 2; i < 31; i++){
		K[i] = K[i-1]*2;
		K[i-1]--;
	}
	K[30]--;
	int N, k;
	cin >> N;
	while( N-- ){
		cin >> k;
		cout << K[ k ] << endl;
	}
}
