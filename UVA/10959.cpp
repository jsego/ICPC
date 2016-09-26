/*
*  Javier Segovia
*  Accepted in 0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define INF 1000000000
int B[3000];
void bfs(int b,vector<int> &d,vector<vector<int> > &V){
	int ac=0,tot=2,val,st; B[0] = b; B[1] = 0;
	while (ac<tot) {
		st = B[ac++]; val = B[ac++];
		for (int i=0; i<(int)V[st].SL; i++) {
			if (d[V[st][i]]==INF) {
				d[V[st][i]] = val+1;
				B[tot++] = V[st][i];
				B[tot++] = d[V[st][i]];
			}
		}
	}
}
int main(){
	int kases; scanf("%d",&kases);
	for (int i=0; i<kases; i++) {
		if(i)printf("\n");
		int P,D,orig,dest; scanf("%d %d",&P,&D);		
		vector<vector<int> > V(P+1,vector<int>());
		for (int k=0; k<D; k++) {
			scanf("%d %d",&orig,&dest);
			V[orig].PB(dest);
			V[dest].PB(orig);
		}
		vector<int> Dist(P+1,INF);
		Dist[0] = 0;
		bfs(0,Dist,V);
		for (int k=1; k<P; k++) {
			printf("%d\n",Dist[k]);
		}
	}
}