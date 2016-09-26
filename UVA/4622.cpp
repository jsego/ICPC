#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int N,M;
int T[1001][1001];
int D[1000001][2];
bool seen[1001][1001];

void bfs(int i,int j){
	int ac=0,tot=1,x,y;
	D[ac][0] = i; D[ac][1] = j;
//	cout<<"I: "<<i<<" J: "<<j<<endl;
	while (ac<tot) {
		x=D[ac][0]; y=D[ac][1];
	//	cout<<"AC: "<<ac<<" Cor->"<<x<<" "<<y<<" T[x][y]:"<<T[x][y]<<endl;
		if (T[x][y] == 5) {
			if (x>0 && !seen[x-1][y] && (T[x-1][y] == 1 || T[x-1][y]==4 || T[x-1][y]==5) ) {
				seen[x-1][y] = true;
				D[tot][0] = x-1; D[tot++][1] = y;
			}
			if (x+1<N && !seen[x+1][y] && (T[x+1][y]==2 || T[x+1][y] == 3|| T[x+1][y]==5)) {
				seen[x+1][y] = true;
				D[tot][0] = x+1; D[tot++][1] = y;
			}
			if (y>0 && !seen[x][y-1] && (T[x][y-1]==3 || T[x][y-1]==4 || T[x][y-1]==5) ) {
				seen[x][y-1] = true;
				D[tot][0] = x; D[tot++][1] = y-1;
			}
			if (y+1<M && !seen[x][y+1] && (T[x][y+1]==1 || T[x][y+1]==2 || T[x][y+1]==5)) {
				seen[x][y+1] = true;
				D[tot][0] = x; D[tot++][1] = y+1;
			}
		}
		else if(T[x][y] == 4){
			if (x+1<N && !seen[x+1][y] && (T[x+1][y] == 2 || T[x+1][y] == 3 || T[x+1][y]==5)) {
				seen[x+1][y] = true;
				D[tot][0] = x+1; D[tot++][1] = y;
			}
			if (y+1<M && !seen[x][y+1] && (T[x][y+1] == 5 || T[x][y+1] == 1 || T[x][y+1]==2)) {
				seen[x][y+1] = true;
				D[tot][0] = x; D[tot++][1] = y+1;
			}
		}
		else if(T[x][y] == 3){
			if (x>0 && !seen[x-1][y] && (T[x-1][y] == 1 || T[x-1][y] == 4 || T[x-1][y]==5)) {
				seen[x-1][y] = true;
				D[tot][0] = x-1; D[tot++][1] = y;
			}
			if (y+1<M && !seen[x][y+1] && (T[x][y+1] == 5 || T[x][y+1] == 1 || T[x][y+1]==2)) {
				seen[x][y+1] = true;
				D[tot][0] = x; D[tot++][1] = y+1;
			}		
		}
		else if(T[x][y] == 2){
			if (x>0 && !seen[x-1][y] && (T[x-1][y] == 1 || T[x-1][y] == 4 || T[x-1][y]==5)) {
				seen[x-1][y] = true;
				D[tot][0] = x-1; D[tot++][1] = y;
			}
			if (y>0 && !seen[x][y-1] && (T[x][y-1] == 3 || T[x][y-1] == 4 || T[x][y-1]==5)) {
				seen[x][y-1] = true;
				D[tot][0] = x; D[tot++][1] = y-1;
			}			
		}
		else if(T[x][y] == 1){
			if (x+1<N && !seen[x+1][y] && (T[x+1][y] == 2 || T[x+1][y] == 3 || T[x+1][y]==5)) {
				seen[x+1][y] = true;
				D[tot][0] = x+1; D[tot++][1] = y;
			}
			if (y>0 && !seen[x][y-1] && (T[x][y-1] == 3 || T[x][y-1] == 4 || T[x][y-1]==5)) {
				seen[x][y-1] = true;
				D[tot][0] = x; D[tot++][1] = y-1;
			}			
		}
		ac++;
	}
}

int main(){
	int kases; cin>>kases;
	char c;
	while (kases--) {
		cin>>N>>M;
		for (int i=0; i<N ; i++) {
			for (int j=0; j<M; j++) {
				cin>>c; T[i][j] = c-'A'; //cout<<T[i][j]<<" ";
				seen[i][j] = false;
				if (!T[i][j]) {
					seen[i][j]=true;
				}
			}//cout<<endl;
		}//cout<<endl;
		int cont=0;
		for (int i=0; i<N ; i++) {
			for (int j=0; j<M; j++) {
				if (!seen[i][j]) {
					seen[i][j]=true;
					bfs(i,j);
					cont++;
					/*for (int k=0; k<N ; k++) {
						for (int q=0; q<M; q++) {
							cout<<seen[k][q]<<" ";
						}cout<<endl;
					}cout<<endl;*/
				}
			}
		}
		cout<<cont<<endl;
	}
}