/*
*  Javier Segovia
*  Accepted in 0.020
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define X first
#define Y second

char A[101][101];
int B[101][101];
int C[20005];
bool seen[101][101];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[9] = {-1,0,1,-1,1,-1,0,1};
int N,M;

void bfs(){
	int x,y,nx,ny;
	for (int i=0; i<N ; i++) {
		for (int j=0; j<M ; j++) {
			if(seen[i][j])continue;
			vector<pair<int,int> > V;
			int ac=0,tot=0;
			C[tot++] = i;
			C[tot++] = j;
			seen[i][j] = true;
			V.PB(MP(i,j));
			while (ac<tot) {
				x = C[ac++];
				y = C[ac++];
				for (int k=0; k<8; k++) {
					nx = x+dx[k];
					ny = y+dy[k];
					if(nx>= 0 && nx<N && ny>=0 && ny<M && !seen[nx][ny]){
						seen[nx][ny] = true;
						V.PB(MP(nx,ny));
						C[tot++] = nx; C[tot++] = ny;
					}
				}
			}
			int val = int(V.SL);
			for(int k=0;k<val;k++){
				B[V[k].X][V[k].Y] = val;
			}
		}
	}
}

int main(){
	int kases;
	string s;
	scanf("%d",&kases);
	getline(cin,s);
	getline(cin,s);
	bool first=false;
	while (kases--) {
		if(first){ printf("\n");}
		else{ first = true;}
		N=0;
		while (getline(cin,s), s[0] == 'L' || s[0]=='W') {
			for (int i=0; i<int(s.LE); i++) {
				A[N][i] = s[i];
				if(s[i] == 'L'){ 
					seen[N][i] = true; 
					B[N][i] = 0;
				}
				else{ seen[N][i] = false;}
			}
			M=int(s.LE);
			N++;
		}
		
		bfs();
		
		int a,b;
		while (int(s.LE)>0) {
			istringstream iss(s);
			iss>>a>>b;
			printf("%d\n",B[a-1][b-1]);
			getline(cin,s);
		}
	}
}