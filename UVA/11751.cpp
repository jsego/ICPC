/*
*  Javier Segovia
*  Accepted in 0.044
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
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef vector<pair<int,pair<int,int> > > V;
typedef vector<pair<int,int> > VP;
int N,M,mf[2000]; // numero de nodos N <= 2000
char R[1005];
//V v; // v e c t o r de a r i s t a s
// ( co s t e , ( nodo1 , nodo2 ) )
int set(int n) { // conjunto conexo de n
	if (mf[n] == n) return n;
	return mf[n] = set(mf[n]);
}
void kruskal ( VP &v) {
	//int a , b;// , sum = 0 ;
	sort(v.rbegin(),v.rend());
	for(int i = 0 ; i < N; i++){
		R[i] = '0';
		//mf[i] = i ; // i n i c i a l i z a r conjunto s conexos
	}
	for(int i = 0 ; i <(int)v.SL ; i++) {
	/*	a = set(v[i].Y.X) , b = set(v[i].Y.Y) ;
		if( a != b) { // s i conjunto s son d i f e r e n t e s
			mf[b] = a ; // u n i f i c a r l o s conjunto s			
			//sum += v[i].X; // a g r eg a r c o s t e de a r i s t a
		}*/
		if(R[v[i].Y] == '0') 
			R[v[i].X] = '1';
	}
	//return sum;
}

int main(){
	while (cin>>N>>M && (N||M) ) {
		VP v; int a,b;
		for (int m=0; m<M ; m++) {
			cin>>a>>b;
			v.PB(MP(MIN(a,b),MAX(a,b)));
		}
		kruskal(v);
		for (int i=0; i<N ; i++) {
			cout<<R[i];
		}cout<<endl;
	}
}