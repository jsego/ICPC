/*
 *  Javier Segovia
 *  Accepted in 0.200
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
vector<int> A[2005];
int bfs[2005];
bool seen[2005];
int main(){
	int N,M;
	while (cin>>N>>M,N||M) {
		for (int i=0; i<=N ; i++) {
			A[i].clear();
		}
		int a,b,c;
		for (int i=0; i<M ; i++) {
			cin>>a>>b>>c;
			A[a].PB(b);
			if(c == 2){A[b].PB(a);}
		}
		int cit;
		bool ok=true;
		for (int j=0; j<=N ; j++) {
			seen[j] = false;
		}
		for (int i=1; i<=N ; i++) {
			int ac=0,tot=0;
			bfs[tot++] = i;
			seen[i] = true;
			while (ac<tot) {
				cit = bfs[ac++];
				for (int j=0; j<int(A[cit].SL); j++) {
					//cout<<"I: "<<cit<<" J: "<<j<<" A: "<<A[cit][j]<<endl;
					if(!seen[A[cit][j]]){
						seen[A[cit][j]] = true;
						bfs[tot++] = A[cit][j];
					}
				}
			}
			//cout<<"I: "<<i<<" TOT: " <<tot<<endl;
			if(tot < N){ok=false; break;}
			for (int j=0; j<=N ; j++) {
				seen[j] = false;
			}
		}
		if(ok)cout<<1<<endl;
		else cout<<0<<endl;
	}
}