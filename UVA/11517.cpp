/*
*  Javier Segovia
*  Accepted in 0.040
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
#define MIN(a,b) ((a)<(b)?(a):(b))
#define INF 1000000000

int B[101];
int C[20005];
bool D[20005][101];

int main(){
	int N,M; scanf("%d",&N);
	while (N--) {
		int A;
		scanf("%d",&A);
		scanf("%d",&M);
		for (int i=0; i<M ; i++) {
			scanf("%d",&B[i]);
		}
		sort(B,B+M);
		C[0] = 0;
		int last=0;
		if(A)
		for (int i=1;i<20005 ; i++) {
			C[i] = INF;
			for (int j=0; j<M ; j++) {
				D[i][j] = false;
			}
			bool ok=false;
			for (int j=0; j<M ; j++) {
				if(B[j] > i) break;
				if(C[i-B[j]]!=INF && !D[i-B[j]][j]){
					ok = true;
					if(C[i-B[j]]+1<C[i]){
						C[i] = C[i-B[j]]+1;
						for (int k=0; k<M ; k++) {
							D[i][k] = D[i-B[j]][k];
						}
						D[i][j] = true;
					}
				}
			}
			if (ok && i>=A) {
				last = i;
				break;
			}
		}
		printf("%d %d\n",last,C[last]);
	}
}