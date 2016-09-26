/*
*  Javier Segovia
*  Accepted in 0.108
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

char A[105][105];
//N - E - S - W
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int main(){
	int N,M,I;
	while (cin>>N>>M>>I,N||M||I) {
		int x=-1,y=-1,nx,ny;
		for (int i=0; i<N ; i++) {
			for (int j=0; j<M ; j++) {
				cin>>A[i][j];
				if(A[i][j] != '*' && A[i][j] !='.' && A[i][j]!='#'){
					x = i; y = j;
				}
			}
		}
		char c,ac=A[x][y];
		A[x][y] = '.';
		int dir,count=0;
		if(ac == 'N') dir=0;
		else if(ac == 'L') dir = 1;
		else if(ac == 'S') dir = 2;
		else dir = 3;
		for (int q=0; q<I ; q++) {
			cin>>c;
			if(c=='F'){
				nx = x+dx[dir];
				ny = y+dy[dir];
				if(nx>=0 && nx<N && ny>=0&& ny<M &&A[nx][ny]!='#'){
					x = nx;
					y = ny;
					if(A[x][y] == '*'){A[x][y]='.'; count++;}
				}
					
			}
			else if(c == 'D'){
				dir++; if(dir==4)dir=0;
			}
			else {
				dir--; if(dir == -1) dir = 3;
			}
		}
		cout<<count<<endl;
	}
}