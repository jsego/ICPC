/*
*  Javier Segovia
*  Accepted in 3.456
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

int A[1000005];
int B[1000005];

int main(){
	int N,M;
	while (cin>>N>>M,N||M) {
		for (int i=0; i<N;i++) {
			cin>>A[i];
		}
		for (int i=0; i<M ;i++) {
			cin>>B[i];
		}
		int a=0,b=0,res=0;
		while (a<N && b<M ) {
			if(A[a]<B[b]) a++;
			else if(A[a]>B[b])b++;
			else {
				a++; b++; res++;
			}
		}
		cout<<res<<endl;
	}
}