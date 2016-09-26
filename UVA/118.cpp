/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string.h>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

//N - E - S - W
int X[4] = {0,1,0,-1};
int Y[4] = {1,0,-1,0};
int C[4] = {'N','E','S','W'};
bool CO[51][51];

int main(){
	int lx,ly,ix,iy,d;
	char c,str[103];
	scanf("%d %d",&lx,&ly);
	for (int i=0; i<=ly; i++) {
		for (int j=0; j<=lx; j++) {
			CO[i][j] = true;
		}
	}
	while (scanf("%d %d %c[^\n]",&ix,&iy,&c)==3) {
		scanf("%s[^\n]",str);
		
		d = (c == 'N'?0: (c=='E'?1:(c=='S'?2:3)) );
		
		bool ok= true;
		
		for (int i=0; i<103 && ok; i++) {
			if(str[i] == 'F'){
				ix+=X[d];
				iy+=Y[d];
				if(ix < 0 || iy < 0 || ix > lx || iy > ly){
					ix-=X[d];
					iy-=Y[d];
					if(CO[iy][ix]){
						ok = false;
						CO[iy][ix] = false;
					}
				}
			}
			else if(str[i] == 'R'){
				d++;
				if(d == 4) d = 0;
			}
			else if(str[i] == 'L'){
				d--;
				if(d == -1) d = 3;
			}
			else {
				break;
			}
		}
		printf("%d %d %c",ix,iy,C[d]);
		if(!ok) printf(" LOST");
		printf("\n");
	}
}