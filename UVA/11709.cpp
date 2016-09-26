/*
*  Javier Segovia
*  Accepted in 1.876
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MIN(a,b) ((a)<(b)?(a):(b))
int P,T;
vector<int> V[1001];
int nI[1001],nL[1001];//index; lowlink
//int c1,c2;
int bfs[2000];//stack
map<string,int> M;
int inde = 0,tot;
vector<vector<int> > SCC;//Array list node

bool contains(int a){
	for (int q=0;q<tot; q++) {
		if (bfs[q] == a) {
			return true;
		}
	}
	return false;
}

int TARJAN(int node){
	nI[node] = inde;
	nL[node] = inde;
	inde++;
	bfs[tot++] = node;
	int to;
	for (int i=0; i<(int)V[node].SL; i++) {
		to = V[node][i];
		if (nI[to]==-1) {
			TARJAN(to);
			nL[node] = MIN(nL[node],nL[to]);
		}
		else if(contains(to)){
			nL[node] = MIN(nL[node],nL[to]);
		}
	}
	if(nL[node] == nI[node]){
		vector<int> component;
		do{
			to = bfs[--tot];
			component.PB(to);
		}while(node!=to && tot);
		SCC.PB(component);
	}
	return (int)SCC.SL;
}

int main(){
	string su1,na1,su2,na2;	
	int c1,c2;
	while (cin>>P>>T && (P||T)) {
		M.clear(); inde = 0; SCC.clear();tot=0;
		for(int i=0;i<P;i++){
			cin>>su1>>na1;
			su1+=na1;
			M[su1] = i; nI[i] = nL[i] = -1;
			V[i].clear(); 
		}
		for (int i=0; i<T; i++) {
			cin>>su1>>na1>>su2>>na2;
			su1+=na1; su2+=na2;
			c1 = M[su1]; c2 = M[su2];
			V[c1].PB(c2);
		}
		for(int i=0;i<P;i++){
			if (nI[i]==-1) {
				TARJAN(i);
			}
		}
		cout<<(int)SCC.SL<<endl;
	}
}