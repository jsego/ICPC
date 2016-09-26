/*
*  Javier Segovia
*  Accepted in 0.008
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

int main(){
	int N,cant,pe;
	string s,a;
	bool first = false;
	while (cin>>N ) {
		if(first)cout<<endl;
		else first = true;
		map<string,pair<int,int> >  M;
		vector<string> V;
		for (int i=0; i<N ; i++) {
			cin>>s;
			M[s] = MP(0,0);
			V.PB(s);
		}
		for (int i=0; i<N ; i++) {
			cin>>s>>cant>>pe;
			if(pe){
				cant/=pe;
				M[s].Y += cant*pe;
				for (int j=0; j<pe ; j++) {
					cin>>a;
					M[a].X += cant;
				}
			}
		}
		for (int i=0; i<int(V.SL); i++) {
			cout<<V[i]<<" "<<M[V[i]].X-M[V[i]].Y<<endl;
		}
		
	}
}