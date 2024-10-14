// C - Shopping Malls

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<set>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define INF 1000000000.0
#define X first
#define Y second
#define SQ(a) ((a)*(a))

typedef double V; // t ipo de c o s t e s
typedef pair<V,int> P; // par de ( co s t e , nodo )
typedef set<P> S; // conjunto de pa r e s

vector<P> A[205] ; // listas adyacencia ( co s t e , nodo )
int N,M,Q;
int T[205][3];

void printV(vector<int> &v){
	for(int i=0;i<int(v.size());i++){
		if(i) cout<<" ";
		cout<<v[i];	
	}cout<<endl;
}

V dijkstra(int s ,int t ) {
	S m; //priority queue
	vector<V> z (N,INF) ; //distancias iniciales
	z[s] = 0 ;//distancia a s es 0
	m.insert(MP( 0 , s ) ) ; //insertar(0,s) en m
	vector<int> rec(N,-1);
	rec[s] = s;
	while(m.SL > size_t(0)) {
		P p = *m.begin(); // p=( coste , nodo ) con menor coste
		m.erase(m.begin()) ; // elimina este par de m
		if(p.Y == t ){
			vector<int> res;
			while(rec[t] != t){
				res.PB(t);
				t = rec[t];			
			}
			res.PB(s);
			reverse(res.begin(),res.end());
			printV(res);
			return p.X; // cuando nodo es t, acaba
		}
		// para cada nodo adjacente al nodo p.Y
		for(int i = 0 ; i <(int)A[p.Y].SL ; i++) {
			// q = (coste hasta nodo adjacente , nodo adjacente )
			P q (p.X + A[p.Y][i].X,A[p.Y][i].Y) ;
			// si q.X es la menor distancia hasta q.Y
			if(q.X < z[q.Y] ) {
				rec[A[p.Y][i].Y] = p.Y;
				m.erase(MP(z[q.Y],q.Y) ) ; // borrar anterior
				m.insert(q) ; // insertar q
				z[q.Y] = q.X; // actualizar distancia
			}
		}
	}
	return -1;
}



double euclid(int a,int b){
	return sqrt(SQ(T[a][0]-T[b][0]) + SQ(T[a][1]-T[b][1]) + SQ(T[a][2]-T[b][2]) );
}

int main(){
	bool first = true;
	while(cin>>N>>M){
		for(int i=0;i<N;i++){ cin>>T[i][0]>>T[i][1]>>T[i][2]; T[i][0]*=5; A[i].clear();}
		if(first) first=false;
		else cout<<endl;
		int a,b;
		string s;
		double ecl;
		for(int i=0;i<M;i++){
			cin>>a>>b>>s;
			if(s == "stairs"){
				ecl = euclid(a,b);
				A[a].PB(MP(ecl,b)); A[b].PB(MP(ecl,a));		
			}
			else if( s == "walking"){
				ecl = euclid(a,b);
				A[a].PB(MP(ecl,b)); A[b].PB(MP(ecl,a));
		
			}
			else if(s == "lift"){
				A[a].PB(MP(1,b)); A[b].PB(MP(1,a));
			}
			else if(s == "escalator"){
				ecl = euclid(a,b);
				A[a].PB(MP(1,b)); A[b].PB(MP(ecl*3,a));
			}
		}
	
		cin>>Q;
		for(int i=0;i<Q;i++){
			cin>>a>>b;
			dijkstra(a,b);	
		}
	}
}
