/*
*  Javier Segovia
*  Accepted in 0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MAX(a,b) ((a)>(b)?(a):(b))

int A[32][11];
int V[32];
int C[32];
int P[32];
int N,K;

bool op(int a,int b){
	if(a == b) return false;
	for (int i = 0; i<N ; i++) {
		if(A[a][i] > A[b][i]) 
			return false;
		else if(A[a][i] <A[b][i])
			return true;
	}
	return false;
}

bool fitin(int a,int b){
	for (int i=0; i<N ; i++) {
		if (A[a][i] >= A[b][i]) {
			return false;
		}
	}
	return true;
}


int main(){
	while (cin>>K>>N) {
		for (int i=0; i<K ; i++) {
			V[i] = P[i] = i;
			C[i] = 1;
		}
		
		for (int i=0; i<K ; i++) {
			for(int j=0;j<N ;j++){
				cin>>A[i][j];
			}
			sort(A[i],A[i]+N);
		}
		
		sort(V,V+K,op);
		
		int acBox,lBox,max=1,beg=0;
		for (int i=1; i<K ; i++) {
			acBox = V[i];
			for (int j=0; j<i ; j++) {
				lBox = V[j];
				if(fitin(lBox,acBox)){
					if(C[lBox] + 1 > C[acBox]){
						C[acBox] = C[lBox]+1;
						P[acBox] = lBox;
						if(C[acBox] > max){
							max = C[acBox];
							beg = acBox;
						}
					}
				}
			}
		}
		
		vector<int> vi;
		cout<<max<<endl;
		while (max--) {
			vi.PB(beg+1);
			beg = P[beg];
		}
		for (int i=int(vi.SL)-1; i>=0; i--) {
			cout<<(i+1<int(vi.SL) ? " ":"")<<vi[i];
		}cout<<endl;
		
	}
}