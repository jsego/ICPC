/*
*  Javier Segovia
*  Accepted in 0.072
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
int A[2005][2];
int mx[5]={-1,0,0,0,1};
int my[5]={0,-1,0,1,0};
int main(){
	int R,C,M,kases=1;
	while (cin>>R>>C>>M && (R||C||M)) {
		bool final = false;
		for (int i=0; i<M; i++) {
			cin>>A[i][0]>>A[i][1];
		}
		int bx,by,nx,ny; cin>>bx>>by;
		for (int i=0; i<5 && !final; i++) {
			nx = bx+mx[i]; ny = by+my[i];
			if(nx<0 || ny<0 || nx+1>R || ny+1>C) continue;
			bool ok=true;
			for (int j=0; j<M; j++) {
				if(nx==A[j][0] || ny==A[j][1]){
					ok=false; break;
				}
			}
			final|=ok;
		}
		if(final){
			cout<<"Case "<<kases++<<": Escaped again! More 2D grid problems!\n";
		}
		else {
			cout<<"Case "<<kases++<<": Party time! Let's find a restaurant!\n";
		}

	}
}