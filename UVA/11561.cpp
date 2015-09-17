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
char T[51][51];
bool seen[51][51];
int B[6000];

int bfs(int x,int y){
	int ac=0,tot=2,coins=0; B[0] = x; B[1] = y;
	while (ac<tot) {
		x = B[ac++]; y = B[ac++];
		if(T[x-1][y]=='T' || T[x+1][y]=='T' || T[x][y-1]=='T' || T[x][y+1]=='T')continue;
		if (!seen[x-1][y]) {
			seen[x-1][y] = true;
			if (T[x-1][y]=='.') {B[tot++]=x-1;B[tot++]=y;}
			if (T[x-1][y]=='G') {B[tot++]=x-1;B[tot++]=y; coins++;}
		}
		if (!seen[x+1][y]) {
			seen[x+1][y] = true;
			if (T[x+1][y]=='.') {B[tot++]=x+1;B[tot++]=y;}
			if (T[x+1][y]=='G') {B[tot++]=x+1;B[tot++]=y; coins++;}
		}
		if (!seen[x][y-1]) {
			seen[x][y-1] = true;
			if (T[x][y-1]=='.') {B[tot++]=x;B[tot++]=y-1;}
			if (T[x][y-1]=='G') {B[tot++]=x;B[tot++]=y-1; coins++;}
		}
		if (!seen[x][y+1]) {
			seen[x][y+1] = true;
			if (T[x][y+1]=='.') {B[tot++]=x;B[tot++]=y+1;}
			if (T[x][y+1]=='G') {B[tot++]=x;B[tot++]=y+1; coins++;}
		}
	}
	return coins;
}

int main(){
	int col,fil;
	while (cin>>col>>fil) {
		int posX,posY;
		for (int i=0; i<fil; i++) {
			for(int j=0;j<col;j++){
				cin>>T[i][j];
				seen[i][j] = false;
				if(T[i][j]=='P'){ posX=i;posY=j;}
			}
		}
		cout<<bfs(posX,posY)<<endl;
	}
}