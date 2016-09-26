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
int A[100];
int N;
int swapis(int I,int S){
	if(I+1 >= S){
		if(A[I]>A[S]){int aux=A[S]; A[S] = A[I]; A[I] = aux; return 1;}
		return 0;
	}
	int mid = I + (I+S)/2;
	return swapis(I,mid)+swapis(mid + 1, S);
}
int main(){
	int kases; cin>>kases;
	while (kases--) {
		cin>>N;
		for(int n=0;n<N;n++) cin>>A[n];
		int res = 0;
		for(int n=1;n<N;n++){
			for (int k=0; k<n; k++) {
				if (A[k] > A[n]) {
					res++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",res);
	}
}