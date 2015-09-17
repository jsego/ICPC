/*
*  Javier Segovia
*  Accepted in 0.064
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
double R[11][4];
int main(){
	char c; int rec=0; cin>>c;
	while (c!='*') {
		for(int i=0;i<4;i++) cin>>R[rec][i];
		rec++;
		cin>>c;
	}
	double x,y; int point=1; cin>>x>>y;
	while (x!=9999.9||y!=9999.9) {
		bool cont=false;
		for (int i=0; i<rec; i++) {
			if (x>R[i][0] && x<R[i][2] && y<R[i][1] && y>R[i][3]) {
				cout<<"Point "<<point<<" is contained in figure "<<i+1<<endl;
				cont=true;
			}
		}
		if (!cont) {
			cout<<"Point "<<point<<" is not contained in any figure"<<endl;
		}
		point++;
		cin>>x>>y;
	}
}