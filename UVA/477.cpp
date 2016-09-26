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
#define SQ(a) ((a)*(a))
double F[11][4];
char T[11];
int main(){
	int fig=0; cin>>T[fig];
	while (T[fig]!='*') {
		if(T[fig] == 'r') for(int i=0;i<4;i++) cin>>F[fig][i];
		else if(T[fig] == 'c') for(int i=0;i<3;i++) cin>>F[fig][i];
		fig++;
		cin>>T[fig];
	}
	double x,y; int point=1; cin>>x>>y;
	while (x!=9999.9||y!=9999.9) {
		bool cont=false;
		for (int i=0; i<fig; i++) {
			if (T[i]=='r' && x>F[i][0] && x<F[i][2] && y<F[i][1] && y>F[i][3]) {
				cout<<"Point "<<point<<" is contained in figure "<<i+1<<endl;
				cont=true;
			}
			else if(T[i]=='c' && (SQ(x-F[i][0])+SQ(y-F[i][1]) <= SQ(F[i][2]))){
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