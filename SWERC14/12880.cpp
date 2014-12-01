// This code performs maximum bipartite matching.
//
// Running time: O(|E| |V|) -- often much faster in practice
//
//   INPUT: w[i][j] = edge between row node i and column node j
//   OUTPUT: mr[i] = assignment for row node i, -1 if unassigned
//           mc[j] = assignment for column node j, -1 if unassigned
//           function returns number of matches made

#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < (int)w[i].size(); j++) {
    if (!seen[w[i][j]]) {
      seen[w[i][j]] = true;
      if (mc[w[i][j]] < 0 || FindMatch(mc[w[i][j]], w, mr, mc, seen)) {
        mr[i] = w[i][j];
        mc[w[i][j]] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w.size(), -1);
  
  int ct = 0;
  for (int i = 0; i < (int)w.size(); i++) {
    VI seen(w.size());
    if (FindMatch(i, w, mr, mc, seen)) 
		ct++;
	//cout<<i<<" "<<ct<<endl;
  }
  return ct;
}

int main(){
	int N, M;
	while(cin>>N>>M){
		VVI w(N);
		int f, t;
		for(int i=0;i<M;i++){
			cin>>f>>t;
			w[f].push_back(t);
		}
		VI mr, mc;
		cout<<(BipartiteMatching(w, mr, mc) == N ? "YES":"NO")<<endl;
	}
}
