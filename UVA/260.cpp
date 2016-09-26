/*
*  Javier Segovia
*  Accepted in 0.072
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

bool A[201][201];
bool seen[201][201];
int bfs[90000];
int dx[6] = {-1,-1,0,0,1,1};
int dy[6] = {-1,0,-1,1,0,1};

int main(){
	int N,kases=1;
	while (scanf("%d",&N ),N ) {
		string s;
		for(int i=0;i<N;i++) {
			cin>>s;
			for(int j=0;j<N;j++){
				if(s[j] == 'b') A[i][j] = true;
				else A[i][j] = false;
				seen[i][j] = false;
			//cout<<seen[i][j]<<" ";
			}//cout<<endl;
		}
		int ac,tot,nx,ny,ni,nj;
		bool whites=false,blacks=false;
		for (int i=0; i<N && !whites && !blacks; i++) {
			//from j's [0,N] -> whites
			if(!seen[i][0] && !A[i][0]){
				seen[i][0] = true;
				ac = tot = 0;
				bfs[tot++] = i;
				bfs[tot++] = 0;
				while (ac<tot && !whites) {
					nx = bfs[ac++];
					ny = bfs[ac++];
					for (int k=0;k<6; k++) {
						ni = nx + dx[k];
						nj = ny + dy[k];
						if(ni>=0 && ni<N && nj>=0 && nj<N && !seen[ni][nj] && !A[ni][nj]){
							seen[ni][nj] = true;
							bfs[tot++] = ni;
							bfs[tot++] = nj;
							whites = (nj == N-1);
						}
					}
				}
			}
			//from i's [0,N] -> blacks
			if(!seen[0][i] && A[0][i]){
				seen[0][i] = true;
				ac = tot = 0;
				bfs[tot++] = 0;
				bfs[tot++] = i;
				while (ac<tot && !blacks) {
					nx = bfs[ac++];
					ny = bfs[ac++];
					for (int k=0;k<6; k++) {
						ni = nx + dx[k];
						nj = ny + dy[k];
						if(ni>=0 && ni<N && nj>=0 && nj<N && !seen[ni][nj] && A[ni][nj]){
							seen[ni][nj] = true;
							bfs[tot++] = ni;
							bfs[tot++] = nj;
							blacks = (ni == N-1);
						}
					}
				}
			}
		}
		printf("%d %c\n",kases++,(whites?'W':'B'));
	}
}