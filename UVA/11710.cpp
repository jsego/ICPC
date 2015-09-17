/*
*  Javier Segovia
*  Accepted in 1.188
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define X first
#define Y second

int N,M;//numero de nodos y enlaces
typedef vector<pair<int , pair<int , int> > > V;
int mf[401] ; // numero de nodos N <= 2000
//V v ; // v e c t o r de a r i s t a s
// ( co s t e , ( nodo1 , nodo2 ) )
int set( int n) { // conjunto conexo de n
	if (mf[n]==n)return n;
	else mf[n]=set(mf[n]);return mf[n];
}
int kruskal(V &v){
	int a , b , sum = 0 ;
	sort(v.begin(),v.end());
	for(int i = 0 ; i < N; i++)
	mf[i]=i; // i n i c i a l i z a r conjunto s conexos
	for(int i = 0 ; i < (int) v.SL; i++) {
		a = set(v[i].Y.X) ,b=set(v[i].Y.Y) ;
		if(a!= b) { // s i conjunto s son d i f e r e n t e s
			mf[b]= a ; // u n i f i c a r l o s conjunto s
			sum+=v[i].X; // a g r eg a r c o s t e de a r i s t a
		}
	}
	a=set(0);
	for (int i=1; i<N; i++) {
		b=set(i); 
		if (a!=b) {
			return -1;
		}
	}
	return sum;
}

int main(){
	while (cin>>N>>M && (N||M)) {
		map<string,int> MS;
		map<string,int>::iterator it1,it2;
		string city,Aa,Bb;
		V v;
		int cost;
		for (int i=0; i<N ; i++) {
			cin>>city; MS[city]=i; //A[i].clear();
		}
		for (int i=0; i<M; i++) {
			cin>>Aa>>Bb>>cost;
			it1 = MS.find(Aa); it2=MS.find(Bb);
			v.PB(MP(cost,MP(it1->Y,it2->Y)));
			//A[it2->Y].PB(MP(cost,it1->Y));
		}
		cin>>Aa; it1 = MS.find(Aa);
		long long res=kruskal(v);
		if (res<0) {
			printf("Impossible\n");
		}
		else {
			//cout<<res<<endl;
			printf("%lld\n",res);
		}
	}
}