/*
*  Javier Segovia
*  Accepted in 0.020
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int D,F,C;
bool seen[50][50][50];
int B[1000000];
int MZ[6] = {-1,1,0,0,0,0};
int MX[6] = {0,0,-1,1,0,0};
int MY[6] = {0,0,0,0,-1,1};
int bfs(int xi,int yi,int zi,int xf,int yf,int zf){
	int ac=0,tot=0,x,y,z,move,nx,ny,nz;
	B[tot++] = zi; B[tot++] = xi; B[tot++] = yi; B[tot++] = 0;
	seen[zi][xi][yi] = true; //A[zi][xi][yi] = 0;
	while (ac<tot) { //cout<<
		z = B[ac++]; x = B[ac++]; y = B[ac++]; move = B[ac++];
		for (int i=0; i<6; i++) {
			nz = z+MZ[i]; ny = y+MY[i]; nx = x+MX[i];
			if (nz>=0 && nz<D && nx>=0 && nx<F && ny>=0 && ny<C && !seen[nz][nx][ny]) {
				seen[nz][nx][ny] = true;
				//A[nz][nx][ny] = move+1; 
				if(nz == zf && ny == yf && nx == xf) return move+1;
				B[tot++] = nz; B[tot++] = nx; B[tot++] = ny; B[tot++] = move+1;
			}
		}
	}
	return -1;
}

int main(){
	while (cin>>D>>F>>C && (D||F||C) ) {
		int zs,xs,ys,ze,xe,ye; char ca;
		for (int d=0; d<D; d++) {
			for (int f=0; f<F ; f++) {
				for (int c=0; c<C; c++) {
					cin>>ca; seen[d][f][c] = false;
					if (ca=='#') { 
						seen[d][f][c] = true;
					}
					else if(ca == '.'){
					}
					else if(ca == 'S'){
						zs = d; xs = f; ys=c;
					}
					else {
						ze = d; xe = f; ye = c;
					}
				}
			}
		}
		int res = bfs(xs,ys,zs,xe,ye,ze);
		if(res == -1) {
			cout<<"Trapped!"<<endl;
		}
		else {
			cout<<"Escaped in "<<res<<" minute(s)."<<endl;
		}

	}
}