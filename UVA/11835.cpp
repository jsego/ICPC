/*
 *  Javier Segovia
 *  Accepted in 0.024
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
#define MAX(a,b) ((a)>(b)?(a):(b))

int A[101][101];
int V[101];
int R[101];
int main(){
	int G,P;
	while (cin>>G>>P,G||P) {
		for (int i=0; i<G ; i++) {
			for (int j=0; j<P ; j++) {
				cin>>A[i][j];
			}
		}
		int S; cin>>S;
		for (int s=0; s<S ; s++) {
			int Q; cin>>Q;
			for (int i=0; i<P ; i++) {
				R[i] =V[i]= 0;
			}
			for (int i=0; i<Q ; i++) {
				cin>>V[i];
			}
			int pos,val,maxi=0;
			for (int i=0; i<G; i++) {
				for (int j=0; j<P; j++) {
					pos = A[i][j]-1;
					val = V[pos];
					R[j]+=val;
					maxi = MAX(maxi,R[j]);
				}
			}
			bool first=false;
			for (int j=0; j<P; j++) {
				if(R[j] == maxi){if(first)cout<<" ";first=true; cout<<j+1;}
			}cout<<endl;
		}
	}
}