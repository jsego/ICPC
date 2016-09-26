/*
*  Javier Segovia
*  Accepted in 0.008
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

int A[1500];

int main(){
	int N;
	while (cin>>N,N) {
		for (int i=0; i<N ; i++) {
			cin>>A[i];
		}
		sort(A,A+N);
		bool ok=true;
		for (int i=1; i<N && ok; i++) {
			if(A[i] > 200+A[i-1]) ok=false;
		}
		ok=ok&&((1422-A[N-1])*2<=200);
		if(ok)cout<<"POSSIBLE"<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}
}