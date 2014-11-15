#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define PB push_back
#define MP make_pair
#define SZ size()
#define X first
#define Y second

typedef vector<pair<int,pair<int,int> > > V;

int N, mf[3005]; // numero de nodos N <= 3000
int R; 			 // numero de carreteras R <= 100000
V v;             // vector de aristas (coste, (nodo1, nodo2))
vector<pair<int,int> > adj[3005]; //adjacency list

int set(int n) { // conjunto conexo de n
	if (mf[n] == n) return n;
	else mf[n] = set(mf[n]); return mf[n];
}

int kruskal() {
	int a, b, sum = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i <= N; i++){
		mf[i] = i; // inicializar conjuntos conexos
		adj[i].clear();
	}

	for (int i = 0; i < (int)v.SZ; i++) {
		a = set(v[i].Y.X), b = set(v[i].Y.Y);
		if (a != b) { // si conjuntos son diferentes
			mf[b] = a;  // unificar los conjuntos
			sum += v[i].X; // agregar coste de arista	
			adj[v[i].Y.X].PB(MP(v[i].Y.Y,v[i].X));
			adj[v[i].Y.Y].PB(MP(v[i].Y.X,v[i].X));
			//cout<<"("<<v[i].Y.X<<","<<v[i].Y.Y<<") = "<<v[i].X<<endl;
    	}
  	}
  	return sum;
}

int dfs(int f,int t,int last){
    if(f == t) return 0;
    int sol=-1;
    for(vector<pair<int,int> >::iterator it = adj[f].begin(); it!=adj[f].end(); it++){
       if(it->first != last && ( (sol = dfs(it->first,t,f)) >=0) ){
          return max(sol,it->second);
       }
    }
    return -1;
}

int main(){
    int kases; cin>>kases;
	int from, to, len;
    for(int kase=1;kase<=kases;kase++){
        cin>>N>>R;
		v.clear();
        for(int r=1;r<=R;r++){
			cin>>from>>to>>len;
			v.PB(MP(len,MP(from,to)));
        }

		//Generar arbol
        kruskal();
		
        int Q; cin>>Q; //numero de queries Q <= 1000
        cout<<"Case "<<kase<<endl;
        for(int q=0;q<Q;q++){
                cin>>from>>to;
                cout<<dfs(from, to,-1)<<endl;
        }
        cout<<endl;
    }

}
