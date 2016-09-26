/*
*  Javier Segovia
*  Accepted in 0.796
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
#define MIN(a,b) ((a)<(b)?(a):(b))

typedef int V; // t ipo de c o s t e s
typedef pair<V,int> P; // par de ( co s t e , nodo )
typedef set<P> S; // conjunto de pa r e s
int N,M ; // numero de nodos
vector<P> A[100001] ; // l i s t a s adyacencia ( co s t e , nodo )
V B[12][12];
V C[12];
int stores;

void dijkstra(int s,int p) {
	S m; // c o l a de p r i o r i d a d
	vector<int> z (N,INF) ; // d i s t a n c i a s i n i c i a l e s
	z[s] = 0 ;//d i s t a n c i a a s e s 0
	m.insert(MP( 0 , s ) ) ; // i n s e r t a r ( 0 , s ) en m
	while(m.SL > size_t(0)) {
		P p = *m.begin(); // p=( co s t e , nodo ) con menor c o s t e
		m.erase(m.begin()) ; // e l imina e s t e par de m
		//if(p.Y == t ) return p.X; // cuando nodo e s t , acaba
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
	for (int i=0; i<=stores; i++) {
		B[p][i] = z[C[i]];
		//cout<<"C["<<i<<"]: "<<C[i]<<" z["<<C[i]<<"]: "<<z[C[i]]<<" B["<<p<<"]["<<i<<"]: "<<B[p][i]<<endl;
	}
}

int calc(vector<int> &p){
	int beg = 0,cost = 0;
	for (int i=0; i<int(p.SL); i++) {
		cost += B[beg][p[i]];
		beg = p[i];
	}
	cost += B[beg][0];
	return cost;
}

int main(){
	int kases; cin>>kases;
	while (kases--) {
		cin>>N>>M;
		int a,b,d;
		for (int i=0; i<N ; i++) {
			A[i].clear();
		}
		for (int i=0; i<M ; i++) {
			cin>>a>>b>>d;
			A[a].PB(MP(d,b));
			A[b].PB(MP(d,a));
		}
		cin>>stores;
		C[0] = 0;
		for(int i=1;i<=stores;i++){
			cin>>C[i];
		}
		for (int i=0; i<=stores; i++) {
			dijkstra(C[i],i);
		}
		
		
		
		vector<int> PE(stores);
		for (int i=1; i<=stores; i++) {
			PE[i-1] = i;
		}
		int val = INF;
		do {
			val = MIN(val,calc(PE));
		} while (next_permutation(PE.begin(),PE.end()));
		cout<<val<<endl;
	}
}