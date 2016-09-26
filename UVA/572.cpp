/*
*  Javier Segovia
*  Accepted in 0.012
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
bool seen[105][105];
int B[30000],F,C,cont;
int Mx[8] = {-1,-1,-1,0,0,1,1,1};
int My[8] = {-1,0,1,-1,1,-1,0,1};
void bfs(int i,int j){ cont++;
	int ac=0,tot=0,ai,aj,ni,nj;
	B[tot++] = i; B[tot++] = j; seen[i][j] = true;
	while (ac<tot) {
		ai = B[ac++]; aj = B[ac++];
		for(int i=0;i<8;i++){
			ni = ai + Mx[i]; nj = aj + My[i];
			if(ni>=0 && ni<F && nj>=0 && nj<C && !seen[ni][nj]){
				seen[ni][nj] = true;
				B[tot++] = ni; B[tot++] = nj;
			}
		}
	}
}


int main(){
	char c;
	while (cin>>F>>C && (F||C)) { cont=0;
		for (int i=0; i<F ; i++) {
			for (int j=0; j<C ; j++) {
				cin>>c;
				if(c=='*'){ seen[i][j] = true; }
				else{ seen[i][j] = false;}
			}
		}
		for (int i=0; i<F ; i++) {
			for (int j=0; j<C ; j++) {
				if(seen[i][j])continue;
				bfs(i,j);
			}
		}
		cout<<cont<<endl;
	}
}