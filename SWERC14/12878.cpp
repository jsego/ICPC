#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

typedef int V; // tipo de costes
typedef pair<V,int> P; // par de (coste,nodo)
typedef set<P> S; // conjunto de pares

#define SZ size()
#define MP make_pair
#define X first
#define Y second
#define INF 1000000000
#define PB push_back

int N; // numero de nodos
int T; // number of trails
vector<int> edges;
vector<pair<V,pair<int,int> > > A[10005]; // listas adyacencia (coste, (nodo, edge id) )
vector<P> prec[10005]; // predecesores (edge id, nodo)
bool seen[10005]; 
//bool seenT[250005];

V dijkstra(int s, int t) {
	S m; // cola de prioridad
	vector<V> z(N, INF); // distancias iniciales
	z[s] = 0; // distancia a s es 0
	m.insert(MP(0, s)); // insertar (0,s) en m
	while (m.SZ > 0) {
		P p = *m.begin(); // p=(coste,nodo) con menor coste
		m.erase(m.begin()); // elimina este par de m
		/*
		if (p.Y == t) 
			return p.X; // cuando nodo es t, acaba
		*/
		// para cada nodo adjacente al nodo p.Y
		for (int i = 0; i < (int)A[p.Y].SZ; i++) {
			// q = (coste hasta nodo adjacente, nodo adjacente)
			P q(p.X + A[p.Y][i].X, A[p.Y][i].Y.X);
			int edge_id = A[p.Y][i].Y.Y;
			// si q.X es la menor distancia hasta q.Y
			if (q.X < z[q.Y]) {
				m.erase(MP(z[q.Y], q.Y)); // borrar anterior
				m.insert(q); // insertar q
				z[q.Y] = q.X; // actualizar distancia
				prec[q.Y].clear(); // borrar predecesores
				prec[q.Y].PB(MP(edge_id, p.Y)); // añadir mejor predecesor
			}
			else if(q.X == z[q.Y]){
				prec[q.Y].PB(MP(edge_id, p.Y)); //añadir otro predecesor
			}
		}
	}
	if(z[t] != INF) return z[t];
	return -1;
}

int bfs(int t){
	seen[t] = true;
	vector<int> b;	b.PB(t);
	int ac, p=0, res = 0;
	while(p < int(b.SZ)){
		ac = b[p++]; //cout<<ac<<endl;
		for(int i=0;i<int(prec[ac].SZ);i++){
			res += edges[prec[ac][i].X];
			//cout<<"("<<ac<<","<<prec[ac][i].Y<<"): "<<prec[ac][i].X<<endl;
			if(!seen[prec[ac][i].Y]){
				seen[prec[ac][i].Y] = true;
				b.PB(prec[ac][i].Y);
			}
		}
	}
	return res;
}

int main(){
	while(cin>>N>>T){
		for(int i=0;i<=N;i++){ 
			A[i].clear(); 
			prec[i].clear();
			seen[i] = false; 
			edges.clear();
		}
		//for(int t = 0; t <=T;t++) seenT[t] = false;
		int p1, p2, l;
		for(int t=0;t<T;t++){
			cin>>p1>>p2>>l;
			A[p1].PB(MP(l, MP(p2,t)));
			A[p2].PB(MP(l, MP(p1,t)));
			edges.PB(l);
		}		
		//cout<<dijkstra(0, N-1)<<endl;
		if(dijkstra(0, N-1) == -1) cout<<0<<endl;
		else cout<<bfs(N-1)*2<<endl;
	}
}
