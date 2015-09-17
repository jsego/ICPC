/*
*  Javier Segovia
*  Accepted in 0.008
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
#define EPSILON 0.000000001
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int H,U,D,F,day,totfat,fatigue,height;
	while (scanf("%d %d %d %d",&H,&U,&D,&F), H ) {
		H*=100;
		U*=100;
		D*=100;
		totfat = U;
		fatigue = U*F/100;
		height = U;
		day = 1;
		bool ok=true;
		while (height<= H ) {
			//cout<<"DAY: "<<day<<" DIST HE: "<<height;
			height-=D;
			//cout<<" AFTER SLIDING DOWN: "<<height<<endl;
			if(height < 0){ ok=false; break;}
			totfat = MAX(0,totfat-fatigue);
			height += totfat;
			day++;
		}
		if(ok) printf("success on day %d\n",day);
		else printf("failure on day %d\n",day);
	}
}