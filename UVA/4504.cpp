#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define X first
#define Y second
int N;
double P[50005][2];

pair<double,double> ternaria(double l1,double l2){
	double a,b,c,x=l1,dist=-1000000.0,maxA,maxB;
	while (l1+0.000000001<l2) {
		c=(l2-l1)/3;
		a = l1+c; b = a+c;// l1 --- a(x1) --- b(x2) --- l2
		maxA = -1000000.0; maxB = -1000000.0;
		for (int i=0; i<N ; i++) {
			maxA = MAX(maxA,sqrt((P[i][0]-a)*(P[i][0]-a) + P[i][1]*P[i][1]));
			maxB = MAX(maxB,sqrt((P[i][0]-b)*(P[i][0]-b) + P[i][1]*P[i][1]));
		}
		if (maxA>maxB) {
			l1 = a;
		}
		else {
			l2 = b;
		}

	}
	x = l1;
	for (int i=0; i<N ; i++) {
		dist = MAX(dist,sqrt((P[i][0]-x)*(P[i][0]-x) + P[i][1]*P[i][1]));
	}
	return MP(x,dist);
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(9);
	while (cin>>N && N ) {
		double min=200001.0,max=-200001.0;
		for (int i=0; i<N ; i++) {
			cin>>P[i][0]>>P[i][1];
			min = MIN(min,P[i][0]);
			max = MAX(max,P[i][0]);
		}
		pair<double,double> res = ternaria(min,max);
		cout<<res.X<<" "<<res.Y<<endl;
	}
}