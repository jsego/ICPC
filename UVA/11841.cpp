/*
*  Javier Segovia
*  Accepted in 0.020
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

bool A[22][22][22];
int B[300][3];
bool C[22][22][22];
int Q[6][3]={
	{0,-1,1},{-1,0,1},{1,-1,0},
	{-1,1,0},{1,0,-1},{0,1,-1}
};

int bfs[2000];

int main(){
	int N,M;
	while (cin>>N>>M,N||M) {
		
		for (int i=0; i<N+1; i++) {
			for (int j=0;j<N+1; j++) {
				for (int k=0; k<N+1; k++) {
					A[i][j][k] =false ;
				}
			}
		}
		
		for (int i=0; i<M ; i++) {
			cin>>B[i][0]>>B[i][1]>>B[i][2];
			A[B[i][0]][B[i][1]][B[i][2]] = true;
			C[B[i][0]][B[i][1]][B[i][2]] = false;
		}
		
		bool benny=false;
		int dx,dy,dz,x,y,z;
		for (int i=0; i<M && !benny; i++) {
			x = B[i][0]; 
			y = B[i][1]; 
			z = B[i][2];
			
			if(C[x][y][z]) continue;
			
		//	cout<<"USING: ("<<x<<","<<y<<","<<z<<")"<<endl;
			int ac=0,tot=0;
			C[x][y][z] = true;
			bfs[tot++] = x; bfs[tot++]=y; bfs[tot++] = z; 
			bool a=false,b=false,c=false;
			while (ac<tot) {
				x = bfs[ac++]; y = bfs[ac++]; z = bfs[ac++];
			//	cout<<"("<<x<<","<<y<<","<<z<<") -> "<<a<<" "<<b<<" "<<c<<endl;
				a = (a||!x); b = (b||!y); c = (c||!z);
				for (int j=0; j<6; j++) {
					dx = x + Q[j][0]; dy = y + Q[j][1]; dz = z + Q[j][2];
					if(dx>=0 && dx<=N && dy>=0 && dy<=N && dz>=0 && dz<=N && A[dx][dy][dz] && !C[dx][dy][dz]){
						C[dx][dy][dz] = true;
						bfs[tot++] = dx; bfs[tot++] = dy; bfs[tot++] = dz;
					}
				}
			}
			benny = a&&b&&c;
		}
		if(benny) cout<<"Benny"<<endl;
		else cout<<"Willy"<<endl;
	}
}