/*
*  Javier Segovia
*  Accepted in 0.104
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define MAX(a,b) ((a)>(b)?(a):(b))
int main(){
	int N,kases=1;
	while (cin>>N && N!=-1) {
		int a,b;
		vector<pair<int,int> > v;
		for (int i=0; i<N ; i++) {
			cin>>a>>b;
			v.PB(MP(a,b));
		}
		sort(v.begin(),v.end());
		int max=0,cont;
		for (int i=0; i<N; i++) {
			cont=1;
			for(int j=0;j<i;j++){
				if(v[i].X <= v[j].Y) cont++;
			}
			max=MAX(cont,max);
		}
		cout<<"Case "<<kases++<<": "<<max<<endl;
	}
}