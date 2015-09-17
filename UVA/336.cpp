/*
*  Javier Segovia
*  Accepted in 0.092
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

vector<int> VM[150];
bool seen[300];
int V[300];

int bfs(int a,int TTL,int N){
	int ac=0,tot=0,pos,next,vttl;//,count=0;
	V[tot++] = a;
	V[tot++] = 0;
	seen[a] = true;
	while (ac<tot) {
		pos = V[ac++];
		vttl = V[ac++];
		//cout<<pos<<" "<<vttl<<" "<<tot/2<<endl;
		
		if(vttl == TTL){ continue;}
		
		//count++;
		for (int i=0; i<int(VM[pos].SL); i++) {
			next = VM[pos][i];
			if (!seen[next]) {
				seen[next] = true;
				V[tot++] = next;
				V[tot++] = vttl+1;
			}
		}
	}
	//cout<<"N: "<<N <<" COUNT: "<<tot/2<<endl;
	return N - (tot/2);
	
}

int main(){
	int links,kases=1;
	while (cin>>links,links) {
		
		for (int i=0; i<150; i++) {
			VM[i].clear();
		}
		
		int a,b,cont=0,ac,bc;
		map<int,int> M;
		map<int,int>::iterator it1,it2;
		
		for (int i=0; i<links; i++) {
			cin>>a>>b;
			it1 = M.find(a); 			
			if (it1 == M.end()) {
				M[a] = cont;
				ac = cont++;
			}
			else {
				ac = (it1->second);
			}
			it2 = M.find(b);
			if (it2 == M.end()) {
				M[b] = cont;
				bc  = cont++;
			}
			else {
				bc = (it2->second);
			}
			
			VM[ac].PB(bc);
			VM[bc].PB(ac);
			
		}
		while (cin>>a>>b, a||b) {
			for (int i=0; i<cont; i++) {
				seen[i] = false;
			}
			it1 = M.find(a);
			int res;
			if(it1 == M.end()) res=cont;
			else{
				ac = it1->second;
				res = bfs(ac,b,cont);
			}
			cout<<"Case "<<kases++<<": "<<res<<" nodes not reachable from node "<<a<<" with TTL = "<<b<<"."<<endl;
		}
	}
}