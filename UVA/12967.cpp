#include<iostream>

using namespace std;

int A[32][32];
int R[32];
int main(){
	for(int i=0;i<32;i++) for(int j=0;j<32;j++) A[i][j] = 0;
	for(int i=0;i<32;i++) A[i][0] = 1;
	A[2][1] = 1;
	R[0] = R[1] = 1; R[2] = 4;
	for(int i = 3; i < 31; i++){
		R[i] = 0;
		for(int j = 1; j < i; j++){
			A[i][j] = A[i-1][j-1] + A[i-1][j];
			if( j + 1 < i ) 
				R[i] += A[i][j];
			//if( i < 6 ) cout << " " << A[i][j];
		} //if( i < 6 ) cout << endl;
		R[i] = (R[i]*4+4);
		//cout << R[i] << endl;
	}
	int kases; cin >> kases;
	while( kases-- ){
		int N; cin >> N;
		cout << R[N] << endl;	
	}
}
