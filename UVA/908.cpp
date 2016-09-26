/*
*  Javier Segovia
*  Accepted in 0.008
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
typedef vector<pair<int,pair<int,int> > > V;
int N,K,M,mf[1000005]; // numero de nodos N <= 2000
V v; // v e c t o r de a r i s t a s
// ( co s t e , ( nodo1 , nodo2 ) )
int set(int n) { // conjunto conexo de n
	if (mf[n] == n) return n;
	return mf[n] = set(mf[n]);
}
int kruskal ( ) {
	int a , b , sum = 0 ;
	sort(v.begin(),v.end());
	for(int i = 0 ; i < N; i++)
		mf[i] = i ; // i n i c i a l i z a r conjunto s conexos
	for(int i = 0 ; i <(int)v.SL ; i++) {
		a = set(v[i].Y.X);
		b = set(v[i].Y.Y);
		if( a != b) { // s i conjunto s son d i f e r e n t e s
			mf[b] = a ; // u n i f i c a r l o s conjunto s
			sum += v[i].X; // a g r eg a r c o s t e de a r i s t a
		}
	}
	return sum;
}

int main(){
	bool first=true;
	while (scanf("%d",&N) == 1 ) {
		v.clear();
		if(first)first=false;
		else printf("\n");
		int a,b,c,T=0;
		for (int i=1; i<N ; i++) {
			scanf("%d %d %d",&a,&b,&c);
			T+=c;
		}
		printf("%d\n",T);
		scanf("%d",&K);
		for (int i=0; i<K ; i++) {
			scanf("%d %d %d",&a,&b,&c); a--; b--;
			v.PB(MP(c,MP(a,b)));
			//cout<<"("<<a<<","<<b<<") -> "<<c<<endl;
		}
		scanf("%d",&M);
		for (int i=0; i<M ; i++) {
			scanf("%d %d %d",&a,&b,&c); a--; b--;
			v.PB(MP(c,MP(a,b)));
			//cout<<"("<<a<<","<<b<<") -> "<<c<<endl;
		}
		//cout<<"SIZE: "<<v.SL<<endl;
		T = kruskal();
		printf("%d\n",T);
	}
}