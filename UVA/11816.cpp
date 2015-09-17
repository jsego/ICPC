/*
*  Javier Segovia
*  Accepted in 0.744
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define LL long long

int main(){
	int kases; cin>>kases;
	while (kases--) {
		int N,M;
		string s;
		char c;
		LL a,b,p1,p2,p3,total=0;
		cin>>N>>M;
		map<string,pair<LL,pair<LL,LL> > > V;
		for (int i=0; i<N ; i++) {
			cin>>s>>a>>c; b=0;
			if(c == '.') cin>>b>>c;
			p1 = a*100 + b;
			cin>>a>>c; b=0;
			if(c == '.') cin>>b>>c;
			p2 = a*100 + b;
			cin>>a>>c; b=0;
			if(c == '.') cin>>b>>c;
			p3 = a*100 + b;
			V[s] = MP(p3,MP(p1,p2));
		}
		for (int i=0; i<M ; i++) {
			cin>>s>>c>>a>>c>>b;
			a = (a*1000 + b*10);
			pair<LL,pair<LL,LL> > P = V[s];
			
			P.X = (a*P.X)/10000;
			P.X+=5; P.X/=10;
			
			P.Y.X = (a*P.Y.X)/10000;
			P.Y.X+=5; P.Y.X/=10;
			
			P.Y.Y = (a*P.Y.Y)/10000;
			P.Y.Y+=5; P.Y.Y/=10;
			
			total = total +P.X - P.Y.X - P.Y.Y; //probably sum without the previously division by 10
		}
		//cout<<total<<endl;
		if(total<0){ total*=-1; printf("-");}
		
		printf("%lld.%02lld\n",total/100,total%100);
		
	}
}