/*
*  Javier Segovia
*  Accepted in 0.012
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<iomanip>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int B[200000];
int T[51][51];
int J[51][51];
char C[51][51];
int N,M;

bool mini(char a,char b){
	if (a=='X') return true;
	if (a=='*') return false;
	if (a=='N') return false;
	else if(b=='N') return true;
	if(a=='W')return false;
	else if(b=='W')return true;
	if(a=='E')return false;
	else if(b=='E')return true;
	return false;
}

void BFS(){
	B[0] = 0; B[1] = 0; B[2] = 0;
	int ac=0,tot=3,i,j,jumps;
	while (ac<tot) {
		i = B[ac++]; j=B[ac++]; jumps = B[ac++];
		//cout<<"X: "<<i<<" Y: "<<j<<" jumps: "<<jumps<<endl;
		for (int x=i-1; x>=0; x--) {
			if (i==T[x][j]+x && (jumps+1 < J[x][j] || (jumps+1==J[x][j] && mini(C[x][j],'S') ) )) {
				B[tot++] = x; B[tot++] = j; B[tot++] = jumps+1;
				J[x][j] = jumps+1;
				C[x][j] = 'S';
			}
		}
		for (int x=i+1; x<N ; x++) {
			if (x==T[x][j]+i && (jumps+1 < J[x][j] || (jumps+1==J[x][j] && mini(C[x][j],'N') ) )) {
				B[tot++] = x; B[tot++] = j; B[tot++] = jumps+1;
				J[x][j] = jumps+1;
				C[x][j] = 'N';
			}
		}
		for (int y=j-1; y>=0; y--) {
			if (j==T[i][y]+y && (jumps+1 < J[i][y] || (jumps+1==J[i][y] && mini(C[i][y],'E') ) )) {
				B[tot++] = i; B[tot++] = y; B[tot++] = jumps+1;
				J[i][y] = jumps+1;
				C[i][y] = 'E';
			}
		}
		for (int y=j+1; y<M; y++) {
			if (y==T[i][y]+j && (jumps+1 < J[i][y] || (jumps+1==J[i][y] && mini(C[i][y],'W') ) )) {
				B[tot++] = i; B[tot++] = y; B[tot++] = jumps+1;
				J[i][y] = jumps+1;
				C[i][y] = 'W';
			}
		}
	}
}

int main(){
	while (cin>>N>>M && (N||M)) {
		for (int i=0; i<N ; i++) {
			for (int j=0; j<M; j++) {
				cin>>T[i][j]; J[i][j] = INT_MAX; C[i][j] = 'X';
			}
		}
		C[0][0] = '*'; J[0][0] = 0;
		BFS();
		for (int i=0; i<N ; i++) {
			for (int j=0; j<M; j++) {
				cout<<C[i][j];
			}cout<<endl;
		}cout<<endl;
	}
}