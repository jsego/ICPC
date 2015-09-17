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
#define MAX(a,b) ((a)>(b)?(a):(b))
int T[8][8];
bool seen[8][8];
int total=0,x,y;
void compute(int nqueens, int score){
	if (nqueens==8) {
		total=MAX(total,score);
		return;
	}
	for (int j=0; j<8; j++) {
		if (!seen[nqueens][j]) {
			vector<int> p;
			for (int k=0; k<8; k++) {
				if (!seen[k][j]) {
					p.PB(k); p.PB(j);
					seen[k][j] = true;
				}
			}
			for(int i=nqueens,k=j;i>=0&&k>=0;i--,k--){
				if (!seen[i][k]) {
					p.PB(i); p.PB(k);
					seen[i][k] = true;
				}
			}
			for(int i=nqueens,k=j;i>=0&&k<8;i--,k++){
				if (!seen[i][k]) {
					p.PB(i); p.PB(k);
					seen[i][k] = true;
				}
			}
			for(int i=nqueens,k=j;i<8&&k>=0;i++,k--){
				if (!seen[i][k]) {
					p.PB(i); p.PB(k);
					seen[i][k] = true;
				}
			}
			for(int i=nqueens,k=j;i<8&&k<8;i++,k++){
				if (!seen[i][k]) {
					p.PB(i); p.PB(k);
					seen[i][k] = true;
				}
			}
			compute(nqueens+1,score+T[nqueens][j]);
			for (int i=0; i<(int)p.SL; i+=2) {
				x = p[i]; y = p[i+1];
				seen[x][y] = false;
			}
		}
	}
	return;
}
int main(){
	int kases; cin>>kases;
	while (kases--) {
		total=0;
		for (int i=0; i<8; i++) {
			for (int j=0; j<8; j++) {
				cin>>T[i][j];
				seen[i][j] = false;
			}
		}
		compute(0,0);
		printf("%5d\n",total);
	}
}