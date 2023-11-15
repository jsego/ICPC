#include<bits/stdc++.h>

using namespace std;


int main(){
	int A[3], B[3];
	while(cin >> A[0] >> A[1] >> A[2]){
		cin >> B[0] >> B[1] >> B[2];
		sort(A, A+3);
		sort(B, B+3);
		if((A[0]==B[0]) && (A[1]==B[1]) && (A[2]==B[2]) && ((A[0]*A[0]+A[1]*A[1])==(A[2]*A[2])))
			cout << "YES\n";
		else cout << "NO\n";
	}
}

