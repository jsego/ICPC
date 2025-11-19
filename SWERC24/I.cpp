#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A[100002];
int IN[100002];
int depth[100002];

int DFS(int n){
	if(depth[n] != -1) return depth[n];
	if(A[n].size() == 0) return 1;
	int maxi = 0;
	for(size_t i=0; i<A[n].size(); ++i){
		maxi = max(maxi, 1 + DFS(A[n][i]));
	}
	depth[n] = maxi;
	return maxi;
}

int main(){
	while(cin >> N){
		memset(IN, 0, N);
		memset(depth, -1, N);
		int refs, num_leaves = 0;
		for(int i=1; i<=N; ++i){
			cin >> refs;
			if(refs == 0) ++num_leaves;
			A[i].resize(refs, 0);
			for(int j=0; j<refs; ++j){
				cin >> A[i][j];
			}
			
		}
		// if leaves != 1 => 0
		if(num_leaves != 1){
			cout << "0\n"; continue;
		}
		
		// compute roots, if |roots| != 1 => 0
		int root = -1, num_roots = 0;
		for(int i=1; i<=N; ++i){
			if( IN[i] == 0 ){
				root = i; ++num_roots;
			}
		}
		if(num_roots != 1){
			cout << "0\n"; continue;
		}
		
		// Otherwise, topsort, then path check
		if(DFS(root) == N) cout << "1\n";
		else cout << "0\n"; 
		
	}
}
