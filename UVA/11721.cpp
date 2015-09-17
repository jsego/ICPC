/*
*  Javier Segovia
*  Accepted in 0.392
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
#define INF 1000000000
#define MIN(a,b) ((a)<(b)?(a):(b))
vector<int> V[1005],VR[1005];
int nI[1005],nL[1005];//index; lowlink
//int c1,c2;
int bfs[2000],ST[2000];//stack
int inde = 0,tot;
int T[1005][1005];
vector<vector<int> > SCC;//Array list node

bool contains(int a){
	for (int q=0;q<tot; q++) {
		if (bfs[q] == a) {
			return true;
		}
	}
	return false;
}

void TARJAN(int node){
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
	//return SSC;
}

bool bellman(vector<int> &vc){
	vector<int> times(1005,INF);
	times[vc[0]] = 0;
	for (int i=0; i<(int)vc.SL; i++) {
		for (int j=0; j<(int)vc.SL; j++) {
			for (int k=0; k<(int)V[vc[j]].SL; k++) {
				if (times[vc[j]]!=INF && times[vc[j]]+T[vc[j]][ V[vc[j]][k] ] < times[V[vc[j]][k]]) {
					times[V[vc[j]][k]] = times[vc[j]]+T[vc[j]][ V[vc[j]][k] ];
				}
			}
		}
	}
	for (int j=0; j<(int)vc.SL; j++) {
		for (int k=0; k<(int)V[vc[j]].SL; k++) {
			if (times[vc[j]]!=INF && times[vc[j]]+T[vc[j]][ V[vc[j]][k] ] < times[V[vc[j]][k]]) {
				return true;
			}
		}
	}
	return false;
}

int main(){
	int kases; cin>>kases;
	for(int kas=1;kas<=kases;kas++) {
		inde = 0; SCC.clear();tot=0;
		int N, M; cin>>N>>M;
		int x,y,t;
		for (int i=0; i<=N ; i++) {
			nI[i] = nL[i] = -1;
			V[i].clear();
			VR[i].clear();
		}
		for(int i=0;i<M;i++){
			cin>>x>>y>>t;
			V[x].PB(y);
			VR[y].PB(x);
			T[x][y] = t;
		}
		for(int i=0;i<=N ;i++){
			if (nI[i]==-1) {
				TARJAN(i);
			}
		}
		int tStack=0,acSt=0;
		vector<bool> seen(N+5,false);
		for (int i=0; i<(int)SCC.SL; i++) {
			if (bellman(SCC[i])) {
				for(int j=0;j<(int)SCC[i].SL;j++) {
					ST[tStack++] = SCC[i][j];
					seen[SCC[i][j]] = true;
				}
			}
		}
		int nodeAC;
		while (acSt<tStack) {
			nodeAC = ST[acSt];
			for (int i=0; i<(int)VR[nodeAC].SL; i++) {
				if (!seen[VR[nodeAC][i]]) {
					seen[VR[nodeAC][i]] = true;
					ST[tStack++] = VR[nodeAC][i];
				}
			}
			acSt++;
		}		
		cout<<"Case "<<kas<<":";
		if (tStack==0) {
			cout<<" impossible"<<endl;
		}
		else {
			for (int k=0; k<N ; k++) {
				if(seen[k]) cout<<" "<<k;
			}cout<<endl;
		}

	}
}