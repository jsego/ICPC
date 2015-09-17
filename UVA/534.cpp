/*
*  Javier Segovia
*  Accepted in 0.060
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
#define X first
#define Y second
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
typedef vector<pair<int,pair<int,int> > > V;
int N,nodes[205][2]; // numero de nodos N <= 200
int M[205][205];

int main(){
	int kases=1;
	while(scanf("%d",&N), N){
		for(int i=0;i<N;i++){scanf("%d %d",&nodes[i][0],&nodes[i][1]); }
		//V v; 
		int sq1,sq2;
		for (int i=0; i<N ; i++) { M[i][i] = 0;
			for (int j=i+1;j<N ; j++) {
				sq1 = nodes[i][0]-nodes[j][0];
				sq2 = nodes[i][1]-nodes[j][1];
				sq1 = sq1*sq1; sq2 = sq2*sq2;
				M[i][j] = M[j][i] = sq1+sq2;
				//v.PB(MP( sq1+sq2,MP(i,j)));
			}
		}
		for (int k=0; k<N ; k++) {
			for (int j=0; j<N ; j++) {
				for (int i=0; i<N ; i++) {
					M[i][j] = MIN(M[i][j],MAX(M[i][k],M[k][j]));
				}
			}
		}
		
		//double res = kruskal(v);
		printf("Scenario #%d\nFrog Distance = %.3f\n\n",kases++,sqrt(M[0][1]));
	}	
}