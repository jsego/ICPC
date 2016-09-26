#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int A[101][101];
bool seen[101][101][4];
int mini,maxi;
int N,M;
int bfs[20010];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool bfsf(int xi,int yj){
	int x,y;
	
	for (int k=0; k<4; k++) {
		int ac=0,tot=0;
		x = xi+dx[k];
		y = yj+dy[k];
		if(x < 0 || y<0 || x >=N || y>=M || A[x][y] == mini || ((maxi-mini)%(A[x][y]-mini) != 0) ) continue;
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				seen[i][j][k] = false;
		seen[xi][yj][k] = true;
		seen[x][y][k] = true;
		int val = A[x][y]-mini,nx,ny;
		if(A[x][y] == maxi) return true;
		bfs[tot++] = x; bfs[tot++] = y;
		while (ac<tot) {
			x = bfs[ac++];
			y = bfs[ac++];
			for (int q=0; q<4; q++) {
				nx = x+dx[q];
				ny = y+dy[q];
				if(nx < 0 || nx>=N || ny<0 || ny>=M || seen[nx][ny][k] || (A[nx][ny]-A[x][y])!=val)
					continue;
				if(A[nx][ny] == maxi) 
					return true;
				seen[nx][ny][k] = true;
				bfs[tot++] = nx;
				bfs[tot++] = ny;
			}
		}
	}
	return false;
}

int main(){
	while (cin>>N>>M, (N!=-1 && M!=-1) ) {
		mini = 100000000;
		maxi = -100000000;
		for (int i=0; i<N ; i++) {
			for (int j=0;j<M ; j++) {
				cin>>A[i][j];
				mini = MIN(mini,A[i][j]);
				maxi = MAX(maxi,A[i][j]);
			}
		}
		bool ok=(mini == maxi );
		for(int i=0;i<N&&!ok ;i++){ 
			for(int j=0;j<M &&!ok;j++){
				if(A[i][j]==mini){
					ok = bfsf(i,j);
				}
			}
		}
		if(ok) cout<<"At least one pattern exists."<<endl;
		else cout<<"No pattern can be found."<<endl;
	}
	
}