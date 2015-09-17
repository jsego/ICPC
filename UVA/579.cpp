/*
* Javier Segovia
* Accepted in 0.200
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
int main(){
	double h,m; char c;
	while (cin>>h>>c>>m && (h||m)) {
		h=(h*60+m)/720; if(h>=1.0) h-=1.0;
		m=(m/60);
		double dif;
		if (h>=m){
			dif = h-m;
			if (1.0+m-h <= dif)dif = 1.0+m-h;
		}
		else{
			dif = m-h;
			if(1.0+h-m <= dif)dif=1.0+h-m;
		}
		dif *= 360.0; 
		printf("%.3lf\n",dif);
	}
}