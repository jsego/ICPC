/*
*  Javier Segovia
*  Accepted in 0.512
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
#define INF 1000000000
#define X first
#define Y second
typedef int V; // t ipo de c o s t e s
typedef pair<V,int> P; // par de ( co s t e , nodo )
typedef set<P> S; // conjunto de pa r e s
int N,M; // numero de nodos y numero de enlaces
vector<P> A[20001] ; // l i s t a s adyacencia ( co s t e , nodo )

V dijkstra(int s ,int t ) {
	S m; // c o l a de p r i o r i d a d
	vector<int> z (N,INF) ; // d i s t a n c i a s i n i c i a l e s
	z[s] = 0 ;//d i s t a n c i a a s e s 0
	m.insert(MP( 0 , s ) ) ; // i n s e r t a r ( 0 , s ) en m
	while(m.SL > size_t(0)) {
		P p = *m.begin(); // p=( co s t e , nodo ) con menor c o s t e
		m.erase(m.begin()) ; // e l imina e s t e par de m
		if(p.Y == t ) return p.X; // cuando nodo e s t , acaba
		// para cada nodo adja c ent e a l nodo p .Y
		for(int i = 0 ; i <(int)A[p.Y].SL ; i++) {
			// q = ( c o s t e has ta nodo adja c ent e , nodo adja c ent e )
			P q (p.X + A[p.Y][i].X,A[p.Y][i].Y) ;
			// s i q .X e s l a menor d i s t a n c i a has ta q .Y
			if(q.X < z[q.Y] ) {
				m.erase(MP(z[q.Y],q.Y) ) ; // bo r r a r a n t e r i o r
				m.insert(q) ; // i n s e r t a r q
				z[q.Y] = q.X; // a c t u a l i z a r d i s t a n c i a
			}
		}
	}
	return -1;
}

int main(){
	int kases; cin>>kases;
	for (int k=1; k<=kases; k++) {
		int s,t,from,to,cost; //origen destino
		cin>>N>>M>>s>>t;
		for (int i=0; i<N ; i++) {
			A[i].clear();
		}
		for (int i=0; i<M ; i++) {
			cin>>from>>to>>cost;
			A[from].PB(MP(cost,to));
			A[to].PB(MP(cost,from));
		}
		int res= dijkstra(s,t);
		if(res == -1) cout<<"Case #"<<k<<": unreachable"<<endl;
		else cout<<"Case #"<<k<<": "<<res<<endl;
	}
}