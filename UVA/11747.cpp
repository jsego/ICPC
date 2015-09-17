/*
*  Javier Segovia
*  Accepted in 0.012
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
int N,M,mf[1005]; // numero de nodos N <= 1005
//V v; // v e c t o r de a r i s t a s
bool first=true;
// ( co s t e , ( nodo1 , nodo2 ) )
int set(int n) { // conjunto conexo de n
	if (mf[n] == n) return n;
	return mf[n] = set(mf[n]);
}
void kruskal (V &v ) {
	int a , b ;//, sum = 0 ;
	sort(v.begin(),v.end());
	for(int i = 0 ; i <= N; i++)
		mf[i] = i ; // i n i c i a l i z a r conjunto s conexos
	for(int i = 0 ; i <(int)v.SL ; i++) {
		a = set(v[i].Y.X) , b = set(v[i].Y.Y) ;
		if( a != b) { // s i conjunto s son d i f e r e n t e s
			mf[b] = a ; // u n i f i c a r l o s conjunto s
			//sum += v[i].X; // a g r eg a r c o s t e de a r i s t a
		}
		else {
			if(!first) cout<<" "<<v[i].X;
			else {
				first=false; 
				cout<<v[i].X;
			}

		}

	}
	//return sum;
}

int main(){
	while (cin>>N>>M && (N||M)) {
		V vi; first=true; int u,v,w;
		for (int i=0; i<M ; i++) {
			cin>>u>>v>>w; vi.PB(MP(w,MP(u,v)));
		}
		kruskal(vi);
		if(first)cout<<"forest"<<endl;
		else cout<<endl;
	}
}