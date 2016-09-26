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
string T[21];
int SS[2000][4];
int RES[21][21];
bool V[21][21][4];
int A[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int BFS(int xs,int ys,int xf,int yf,int tot){
	int ac=0,px,py,dir,steps;
	while (ac<tot) {
		px = SS[ac][0];
		py = SS[ac][1];
		dir = SS[ac][2];
		steps = SS[ac][3];
		if (!V[px+A[dir][0]][py+A[dir][1]][dir]) {
			V[px+A[dir][0]][py+A[dir][1]][dir] = true;
			if (px+A[dir][0] == xf && py+A[dir][1] == yf) {
				return steps+1;
			}
			SS[tot][0] = px + A[dir][0];
			SS[tot][1] = py + A[dir][1];
			SS[tot][2] = dir;
			SS[tot++][3] = steps+1;
			RES[px+A[dir][0]][py+A[dir][1]] = MIN(RES[px+A[dir][0]][py+A[dir][1]],steps+1);
		}
		dir=(dir+1)%4;
		if (!V[px+A[dir][0]][py+A[dir][1]][dir]) {
			V[px+A[dir][0]][py+A[dir][1]][dir] = true;
			if (px+A[dir][0] == xf && py+A[dir][1] == yf) {
				return steps+1;
			}
			SS[tot][0] = px + A[dir][0];
			SS[tot][1] = py + A[dir][1];
			SS[tot][2] = dir;
			SS[tot++][3] = steps+1;
			RES[px+A[dir][0]][py+A[dir][1]] = MIN(RES[px+A[dir][0]][py+A[dir][1]],steps+1);
		}		
		ac++;
	}
	return 1000;
}

int main(){
	int kases; cin>>kases; getline(cin,T[0]);
	while (kases--) {
		int lines,cols,xs,ys,xf,yf,tot=0;
		cin>>lines>>cols; getline(cin,T[0]);
		for (int l=0; l<lines; l++) {
			getline(cin,T[l]);
			for (int i=0; i<cols; i++) {
				RES[l][i] = 1000;
				for(int j=0;j<4;j++){
					V[l][i][j] = false; 
				}
				if (T[l][i] == 'F') {
					xf = l; yf = i;
				}
				else if(T[l][i] == 'S'){
					xs = l; ys = i;
				}
				else if(T[l][i] == 'X'){
					for(int j=0;j<4;j++) V[l][i][j] = true;
				}
			}
		}
		for(int j=0;j<4;j++){V[xs][ys][j] = true;}
		RES[xs][ys] = 0;
		char cc;
		for (int i=0; i<4; i++) {
			cc = T[xs+A[i][0]][ys+A[i][1]];
			if (cc=='F') {
				cout<<1<<endl; continue;
			}
			else if(cc!='X'){
				V[xs+A[i][0]][ys+A[i][1]][i] = true;
				SS[tot][0] = xs + A[i][0];
				SS[tot][1] = ys + A[i][1];
				SS[tot][2] = i;
				SS[tot++][3] = 1;
				RES[xs+A[i][0]][ys+A[i][1]] = 1;
			}
		}
		int res = BFS(xs,ys,xf,yf,tot);
		cout<<res<<endl;
	}
}