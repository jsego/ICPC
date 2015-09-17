/*
*  Javier Segovia
*  Accepted in 0.012
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

int bfs(int r,vector<vector<int> > &m){
	vector<int> bf((int)m.SL+10);
	bf[0]=r;
	vector<bool> seen((int)m.SL,false);
	seen[r] = true;
	int tot=1,ac=0;
	while (ac<tot) {
		r = bf[ac]; 
		for (int i=0;i<(int)m[r].SL;i++){
			if(!seen[m[r][i]]){
				seen[m[r][i]] = true;
				bf[tot++]=m[r][i];
			}
			else return -1;
		}
		ac++;
	}
	return tot;
}

int main(){
	int kases=1;
	int a,b;
	while (cin>>a>>b && (a>=0 && b>=0) ) {
		map<int,int> ent,li;
		map<int,int >::iterator itl1,itl2;
		int total=0,ac1,ac2,last=-1;
		vector<vector<int> > links;
		while (a || b ) {
			ent[b]++;
			ent[a];
			itl1 = li.find(b); itl2=li.find(a);
			if (itl1==li.end()) {
				li[b] = total++;
				ac1 = total-1;
			}
			else {
				ac1 = itl1->second;
			}
			if (itl2==li.end()) {
				li[a] = total++;
				ac2 = total-1;
			}
			else {
				ac2 = itl2->second;
			}
			while (last!=total) {
				links.PB(vector<int> ());
				last++;
			}
			links[ac2].PB(ac1);
			cin>>a>>b;
		}		
		bool ok=true;
		int zeros=0,root=-1;
		map<int,int>::iterator it;
		for (it=ent.begin(); it!=ent.end();it++) {
			if(it->second==0){zeros++; root=it->first;}
			else if(it->second!=1){ok=false; break;}
		}
		if (zeros == 1) {
			int num = bfs(li[root],links);
			ok = (ok&&num==(int)ent.SL);
		}
		ok = (ok&&(zeros==1)) || ((int)ent.SL == 0);
		
		cout<<"Case "<<kases++<<" is"<<(ok?"":" not")<<" a tree."<<endl;
	}
}