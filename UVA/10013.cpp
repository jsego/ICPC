/*
*  Javier Segovia
*  Accepted in 2.064
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int N;
char A[1000005];
int main(){
	int kases; cin>>kases;
	for(int k=0;k<kases;k++) {
		if(k)cout<<endl;
		cin>>N; int a,b;
		for (int n=0; n<N ; n++) {
			cin>>a>>b;
			A[n] = a+b;
		}
		bool carry=false;
		for (int i=N-1; i>=0; i--) { A[i]+=carry;
			if(A[i]>9){A[i]-=10; carry=true;}
			else carry=false;
		}
		if (carry)cout<<1;
		for (int i=0; i<N ; i++) {
			cout << int(A[i]);
		}cout<<endl;
	}
}