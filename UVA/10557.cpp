/*
*  Javier Segovia
*  Accepted in 0.020
*/

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define X first
#define Y second
typedef pair<pair<int,int>,int> P; // par de nodos + c o s t e
int N; // numero de nodos
vector<vector<int> > links;
vector<int> costi;
int LIM=INT_MAX;
vector<P> v ; // r e p r e s e n t a c i o n a r i s t a s
int bfs[105];
bool seen[105];

bool bellmanford (int a ,int b) {
	vector<int> d(b+1,0) ;
	d[a] = -100 ; //cout<<a<<" "<<b;
	for(int i = 0 ; i < N; i++)
		for(int j = 0 ; j < (int)v.SL;j++)
			if(d[v[j].X.X]!=0 && (d[v[j].X.X]+v[j].Y<d[v[j].X.Y]) ) {
				//cout << v[j].X.X << "," << v[j].X.Y << "," << v[j].Y << "," << d[v[j].X.X] << "," << d[v[j].X.Y] << "\n";
				d[v[j].X.Y]=d[v[j].X.X]+v[j].Y;
			}
	int ac=0,tot=0,pos;
	for (int i=0; i<=b ; i++) {
		seen[i] = false;
	}
	
	for(int j = 0 ; j < (int)v.SL ; j++)
		if(d[v[j].X.X]<0 && (d[v[j].X.X] + v[j].Y <d[v[j].X.Y] ) ){ //existe ciclo negativo
			bfs[tot++] = v[j].X.Y;
			seen[v[j].X.Y] = true;
		}
	if(d[b]<0) return true;
	
	while (ac<tot) {
		pos = bfs[ac++];
		//cout<<pos<<endl;
		for (int j=0; j<int(links[pos].SL); j++) {
			if(!seen[links[pos][j]]){
				seen[links[pos][j]] = true;
				bfs[tot++] = links[pos][j];
			}
		}
	}
	
	return seen[b];
}

int main(){
	while (cin>>N, N!=-1) {
		int cost,rooms,next,cont=0;
		links.clear(); costi.clear(); v.clear();
		links.resize(N,vector<int>());
		costi.resize(N,0);
		
		for (int i=0; i<N ; i++) {
			cin>>cost>>rooms;
			costi[cont] = -cost;
			for (int i=0; i<rooms; i++) {
				cin>>next; 
				next--;
				links[cont].PB(next);
			}
			cont++;
		}
		
		for (int i=0; i<N ; i++) {
			for (int j=0; j<int(links[i].SL); j++) {
				v.PB(MP(MP(i,links[i][j]),costi[links[i][j]]));
			//	cout << v[v.size()-1].first.first << "," << v[v.size()-1].first.second << "," << v[v.size()-1].second << "\n";
			}
		}
		cout<<(bellmanford(0,N-1) ? "winnable":"hopeless")<<endl;
	}
}