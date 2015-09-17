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
#define X first
#define Y second
int main(){
	//cout.setf(ios::fixed);
	//cout.precision(3);
	pair<double,double> p[4];
	while (cin>>p[0].X>>p[0].Y) {
		for (int i=1; i<4; i++) {
			cin>>p[i].X>>p[i].Y;
		}
		sort(p,p+4);
		double A[2],B[2],C[2];
		int pos=-1;
		for (int i=1; i<4; i++) {
			if (p[i].X == p[i-1].X && p[i].Y == p[i-1].Y) {
				A[0] = p[i].X; A[1] = p[i].Y; pos=i; break;
			}
		}
		if(pos==1){B[0] = p[2].X; B[1] = p[2].Y; C[0] = p[3].X; C[1]= p[3].Y;}
		else if(pos==2){B[0] = p[0].X; B[1] = p[0].Y; C[0] = p[3].X; C[1]= p[3].Y;}
		else {
			B[0] = p[0].X; B[1] = p[0].Y; C[0] = p[1].X; C[1]= p[1].Y;
		}
		double x,y;
		x = C[0] + B[0] - A[0];
		y = C[1] + B[1] - A[1];
		
		//printf("%.3f %.3f",x,y);
		cout<<x<<" "<<y<<endl;
	}
}