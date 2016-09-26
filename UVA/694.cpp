/*
*	Javier Segovia
*	Accepted in 0.060
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
int main(){
	long long A,L,N,k=1,ini;
	while (cin>>A>>L && (A>=0 || L>=0) ) {
		N=0; ini = A;
		while(A>1 && A <= L){
			if(A&1) A =(A<<1)+A+1;
			else A>>=1;
			//if(N<10) cout<<"N: "<<N<<" A: "<<A<<endl;
			N++;
		}
		if(A==1)N++;
		cout<<"Case "<<k<<": A = "<<ini<<", limit = "<<L<<", number of terms = "<<N<<endl;
		k++;
	}
}