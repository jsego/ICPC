/*
*  Javier Segovia
*  Accepted in 0.104
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
#define MIN(a,b) ((a)<(b)?(a):(b))

int main(){
	int N,start,kases=1;
	while (scanf("%d",&N), N ) {
		scanf("%d",&start);
		map<int,vector<int> > E;
		map<int,int> D;
		map<int,vector<int> >::iterator et;
		int a,b;
		while (scanf("%d %d",&a,&b), a||b) {
			E[a].PB(b); E[b];
			D[a] = 0;
			D[b] = 0;
		}
		
		map<int,int> next,next2;
		map<int,int>::iterator it;
		int ac,dest,node=1000000,dist=0,maxdist=0;
		next[start] = 0;
		
		while (int(next.SL)) {
			for (it = next.begin(); it != next.end(); it++) {
				ac = it->first;
				dist = (it->second) +1;
				et = E.find(ac);
				for (int i=0; i<int((et->second).SL); i++) {
					dest = (et->second)[i];
					if(D[dest] < dist){
						D[dest] = dist;
						next2[dest] = dist;
						if(dist > maxdist){maxdist = dist; node = dest;}
						else if(dist == maxdist){node = MIN(dest,node);}
					}
				}
			}
			swap(next,next2);
			next2.clear();
		}
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",kases++,start,D[node],node);
	}
}