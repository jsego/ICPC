/*
*  Javier Segovia
*  Accepted in 0.172
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
bool T[10002];
bool IM[10002];
vector<int> V[10002];
int B[1000002];
int N,S,kases; 

int bfs(int p){
	for (int i=1; i<=N; i++) {
		T[i] = false;
	}
	int ac=0,tot=0,step,pos;
	B[tot++] = p;
	B[tot++] = 0;
	T[p] = true;
	int total=0;
	while (ac<tot) {
		pos = B[ac++];
		step = B[ac++];
		if(IM[pos]) total += step;
		for (int i=0; i<int(V[pos].SL); i++) {
			if (!T[V[pos][i]]) {
				T[V[pos][i]] = true;
				B[tot++] = V[pos][i];
				B[tot++] = step+1;
			}
		}
	}
	return total;
}

int main(){
	cin>>kases; 
	for (int k=0; k<kases; k++) {
		cin>>N>>S;
		for (int i=0; i<=N ; i++) {
			T[i] = IM[i] = false;
			V[i].clear();
		}
		for (int i=0; i<S; i++) {
			int st,last=0; int cont=0;
			while (cin>>st && st) {
				if(T[st]) IM[st] = true;
				T[st] = true;
				if(last){
					V[st].PB(last);
					V[last].PB(st);
				}
				last = st; cont++;
			}
		}
		int min=INT_MAX,res=0,ac;
		for (int i=1;i<=N ; i++) {
			if (IM[i]) {
				ac = bfs(i);// cout<<"I: "<<i<<" AC: "<<ac<<endl;
				if(ac<min){
					min = ac; res = i;
				}
			}
		}
		cout<<"Krochanska is in: "<<res<<endl;
	}
}