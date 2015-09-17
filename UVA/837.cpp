/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define EPSILON 0.000000001
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define X first
#define Y second

int main(){
	cout.setf(ios::fixed);
	cout.precision(3);
	int kases; cin>>kases;
	double x1,y1,x2,y2,r;
	bool first= false;
	while (kases--) {
		if(first)cout<<endl;
		else first= true;
		int N; cin>>N;
		vector<pair<pair<double,double>,double > > V;
		set<double> x;
		for (int i=0; i<N ; i++) {
			cin>>x1>>y1>>x2>>y2>>r;
			V.PB(MP(MP(MIN(x1,x2),MAX(x1,x2)),r));
			x.insert(x1); x.insert(x2);
		}
		
		set<double>::iterator it = x.begin();
		cout<<int(x.SL)+1<<endl;
		cout<<"-inf "<<(*it)<<" 1.000"<<endl;
		double last = (*it),ac,fact; it++;
		while (it!=x.end()) {
			ac = (*it);
			fact = 1.0;
			for (int i=0; i<int(V.SL); i++) {
				if(V[i].X.X < ac && ac<=V[i].X.Y)
					fact *= V[i].Y;
			}
			cout<<last<<" "<<ac<<" "<<fact<<endl;
			last = ac;
			it++;
		}
		cout<<last<<" +inf 1.000"<<endl;
	}
}