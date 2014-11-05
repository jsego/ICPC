#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define PB push_back
#define INF 1000000000

vector<int> A[505];
int B[1100];
int N,M;

int BFS(int r){
	vector<int> v(N, 0);
	vector<int> p(N,-1);
	v[r] = 1; p[r] = r;
	int cp = 0, tp = 0, cr, cv;
	B[tp++] = r; B[tp++] = 1;
	int res = INF;
	while(cp < tp){
		cr = B[cp++]; cv = B[cp++];
		for(int i=0;i<int(A[cr].size());i++){
			if(v[A[cr][i]] == 0){
				v[A[cr][i]] = cv+1;
				p[A[cr][i]] = cr;
				B[tp++] = A[cr][i];
				B[tp++] = cv+1;
			}
			else if(A[cr][i] != p[cr] && v[A[cr][i]]+cv > 3){ 
				res = min(res, v[A[cr][i]]+cv-1);
			}
		}
	}
	return res;
}

int main(){
	int T; cin>>T;
	for(int t=1;t<=T;t++){
		cin>>N>>M;
		for(int i=0;i<N;i++) A[i].clear();
		int a,b; 
		for(int i=0;i<M;i++){
			cin>>a>>b;
			A[a].PB(b);
			A[b].PB(a);
		}
		int girth = INF;
		int current_girth;
		for(int i=0;i<N;i++){//root
			current_girth = BFS(i);
			girth = min(girth, current_girth);
			if(girth == 3) break; //to output faster
		}
		if(girth == INF) cout<<"Case "<<t<<": impossible"<<endl;
		else cout<<"Case "<<t<<": "<<girth<<endl;
	}
}
