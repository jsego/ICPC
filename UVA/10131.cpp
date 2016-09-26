/*
*  Javier Segovia
*  Accepted in 0.020
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

int A[1001][2];
int V[1001];
int C[1001];
int P[1001];
int N,K;

bool op(int a,int b){
	if(a == b) return false;
	if(A[a][0] < A[b][0]) return true;
	else if(A[a][0] == A[b][0] && A[a][1] > A[b][1]) return true;
	return false;
}

bool fitin(int a,int b){
	if(A[a][0] < A[b][0] && A[a][1]>A[b][1]) return true;
	return false;
}


int main(){
	N = 2;
	K = 0;
	
	while (cin>>A[K][0]>>A[K][1]) {
		K++; //cout<<K<<endl;
	}
	//cout<<"K:" <<K<<endl;
	for (int i=0; i<K ; i++) {
		V[i] = P[i] = i;
		C[i] = 1;
	}
		
	sort(V,V+K,op);
	
	/*for (int i=0; i<K ; i++) {
		cout<<V[i]<<" ";
	}cout<<endl;*/
	
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
		cout<<vi[i]<<endl;
	}
	
}