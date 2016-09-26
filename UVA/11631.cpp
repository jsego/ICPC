/*
*  Javier Segovia
*  Accepted in 1.228
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
int N,M;
typedef vector<pair<long long,pair<int,int> > > V;
int mf[200001];

int set(int n){
	if(mf[n] == n) return n;
	return mf[n] = set(mf[n]);
}

long long kruskal(V &v){
	long long a,b,sum=0;
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++) mf[i] = i;
	for(int i=0;i<(int)v.SL;i++){
		a = set(v[i].Y.X), b = set(v[i].Y.Y);
		if (a!=b) {
			mf[b] = a;
			sum+=v[i].X;
		}
	}
	return sum;
}

int main(){
	while (cin>>N>>M && (N||M)) {
		V v; int A,B; long long cost,sum=0;
		for (int i=0; i<M; i++) {
			cin>>A>>B>>cost;
			v.PB(MP(cost,MP(A,B)));
			sum+=cost;
		}
		long long res = kruskal(v);
		cout<<sum-res<<endl;
	}
}