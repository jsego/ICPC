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
#define INF 1000000000
#define MIN(a,b) ((a)<(b)?(a):(b))
int A[40][2];
int B[301][301];

int main(){
	int N,S,M,lim;
	scanf("%d",&N);
	while (N--) {
		scanf("%d %d",&M,&S);
		for (int i=0; i<M ; i++) {
			scanf("%d %d",&A[i][0],&A[i][1]);
		}
		B[0][0] = 0;
		lim = S*S;
		int mini = INF;
		for (int i=0; i<=S ; i++) {
			for (int j=0;j<=S ; j++) {
				if(i||j && (i*i + j*j <= lim) ){
					B[i][j] = INF;
					for (int k=0; k<M ; k++) {
						if(A[k][0]<=i && A[k][1]<=j)
							B[i][j] = MIN(B[i][j],1+B[i-A[k][0]][j-A[k][1]]);
					}
					if( (i*i+j*j) == lim )
						mini = MIN(mini,B[i][j]);
				}
			}
		}
		if(mini<INF) printf("%d\n",mini);
		else printf("not possible\n");
	}
}