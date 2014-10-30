#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define eps 0.000000001
#define SQ(a) ((a)*(a))
int N;
double x[50005],y[50005];

double calc(double p){
	double res = 0.0;
	for(int i=0;i<N;i++){
		res = max(res,sqrt( SQ(x[i]-p)+SQ(y[i]) ));
	}
	return res;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(9);
	while(cin>>N,N){
		double mi= 1000000000.0;
		double ma=-1000000000.0;
		for(int i=0;i<N;i++){
			cin>>x[i]>>y[i];
			mi = min(mi,x[i]);
			ma = max(ma,x[i]);
		}
		double t1, t2, x1, x2, d;
		while(mi+eps < ma){
			d = (ma-mi)/3; //ternary search
			x1 = mi + d; x2 = mi + 2*d;
			t1 = calc(x1); t2 = calc(x2);
			if(t1 < t2){
				ma = x2;
			}
			else{
				mi = x1;
			}
		}
		cout<<ma<<" "<<calc(ma)<<endl;
	}
}
