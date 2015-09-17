/*
*  Javier Segovia
*  Accepted in 0.740
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
#define INF 2000000000
typedef vector<pair<int,pair<int,int> > > V;
int N,M,mf[1000005]; // numero de nodos N <= 2000
V v; // v e c t o r de a r i s t a s
int cont,res=-1;
// ( co s t e , ( nodo1 , nodo2 ) )
int set(int n) { // conjunto conexo de n
	if (mf[n] == n) return n;
	return mf[n] = set(mf[n]);
}
int kruskal() {
	int a , b ;
	sort(v.begin(),v.end());
	for(int i = 0 ; i < N; i++)
		mf[i] = i ; // i n i c i a l i z a r conjunto s conexos
	for(int i = 0 ; i <(int)v.SL ; i++) {
		a = set(v[i].Y.X) ;
		b = set(v[i].Y.Y) ;
		if( a != b) { // s i conjunto s son d i f e r e n t e s
			mf[b] = a ; // u n i f i c a r l o s conjunto s
			cont++;
			if(cont+1 == N){return v[i].X;}
			//sum += v[i].X; // a g r eg a r c o s t e de a r i s t a
		}
	}
	return INF;
//	return sum;
}

int main(){
	while (scanf("%d %d",&N,&M),N||M) {
		v.clear();
		cont=0; res=-1;
		int a,b,c;
		for (int i=0; i<M ; i++) {
			scanf("%d %d %d",&a,&b,&c);
			v.PB(MP(c,MP(a,b)));
		}
		res = kruskal();
		if(res == INF) printf("IMPOSSIBLE\n");
		else printf("%d\n",res);
	}
}