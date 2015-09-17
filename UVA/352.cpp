/*
*  Javier Segovia
*  Accepted in 0.008
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

bool A[27][27];
bool seen[27][27];
int bfs[729];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int main(){
	int N,kases=1;
	while (scanf("%d",&N )==1) {
		string s;
		//cout<<"N: "<<N<<endl;
		for(int i=0;i<N;i++) {
			cin>>s;
			for(int j=0;j<N;j++){
				if(s[j] == '1') A[i][j] = true;
				else A[i][j] = false;
				seen[i][j] = !A[i][j];
			//cout<<seen[i][j]<<" ";
			}//cout<<endl;
		}
		int ac,tot,nx,ny,ni,nj,count=0;
		for (int i=0; i<N ; i++) {
			for (int j=0;j<N ; j++) {
				if(seen[i][j]) continue;
				count++;
				seen[i][j] = true;
			//	cout<<"I: "<<i<<" J: "<<j<<endl;
				ac = tot = 0;
				bfs[tot++] = i;
				bfs[tot++] = j;
				while (ac<tot) {
					ni = bfs[ac++];
					nj = bfs[ac++];
					for (int k=0; k<8 ; k++) {
						nx = ni+dx[k];
						ny = nj+dy[k];
						if(nx>=0 && nx<N && ny>=0 && ny<N && !seen[nx][ny]){
							seen[nx][ny] = true;
							bfs[tot++] = nx;
							bfs[tot++] = ny;
						}
					}
				}
			}
		}
		printf("Image number %d contains %d war eagles.\n",kases++,count);
	}
}