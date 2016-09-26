/*
*  Javier Segovia
*  Accepted in 0.032
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
int mx[8]={-2,-2,-1,-1,1,1,2,2};
int my[8]={-1,1,-2,2,-2,2,-1,1};
int bfs(int ix,int iy,int fx,int fy){
	int A[400],tot=3,mov=0,ac=0,x,y,nx,ny; A[0] = ix; A[1] = iy; A[2] = 0;
	bool seen[8][8];
	if(ix == fx && iy == fy)return 0;
	for(int i=0;i<8;i++) for(int j=0;j<8;j++) seen[i][j] = false;
	seen[ix][iy] = true;
	while (ac<tot) {
		x = A[ac++]; y = A[ac++]; mov=A[ac++];
		for (int i=0; i<8; i++) {
			nx = x+mx[i]; ny = y+my[i];
			if(nx>=0 && nx<8 && ny>=0 && ny<8 && !seen[nx][ny]){
				if(nx == fx && ny == fy) return mov+1;
				seen[nx][ny] = true;
				A[tot++] = nx; A[tot++] = ny; A[tot++] = mov+1;
			}
		}
	}
	return -1;
}

int main(){
	string a,b;
	while (cin>>a>>b ) {
		int x1,x2,y1,y2;
		x1 = a[1]-'1';
		y1 = a[0]-'a';
		x2 = b[1]-'1';
		y2 = b[0]-'a';
		int moves = bfs(x1,y1,x2,y2);
		cout<<"To get from "<<a<<" to "<<b<<" takes "<<moves<<" knight moves.\n";
	}
}