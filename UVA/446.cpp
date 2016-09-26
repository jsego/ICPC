/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<bitset>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	int N; cin>>N;
	while (N--) {
		int A,B;char c;
		cin>>hex>>A>>c>>hex>>B;
		if (c=='+') {
			cout<<bitset<13>(A)<<" "<<c<<" "<<bitset<13>(B)<<" = "<<A+B<<endl;
		}
		else {
			cout<<bitset<13>(A)<<" "<<c<<" "<<bitset<13>(B)<<" = "<<A-B<<endl;
		}

	}
}