#include<bits/stdc++.h>

using namespace std;

#define SQ(a) ((a)*(a))

int X[1001], Y[1001], R[1001];

int Q[1001];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	int N;
	while(cin >> N){
		for(int i=0; i<N; ++i) cin >> X[i] >> Y[i] >> R[i];
		
		// Build adjacency list
		vector<vector<int>> adjacency(N);
		int diff;
		for(int i=0;i<N;++i){
			for(int j=i+1; j<N; ++j){
				diff = SQ(abs(X[i]-X[j])) + SQ(abs(Y[i]-Y[j]));
				if(diff <= SQ(R[i]+R[j])){ // gears are connected
					adjacency[i].push_back(j);
					adjacency[j].push_back(i);
				}
			}
		}
		
		// Propagate direction
		vector<int> dir(N,0);
		dir[0] = 1;
		int pos = 0, total = 0, current_gear, next_gear, next_dir;
		bool blocked = false;
		Q[total++]=0;
		while((not blocked) and (pos < total)){
			current_gear = Q[pos++];
			
			for(size_t i=0; i<adjacency[current_gear].size(); ++i){
				next_gear = adjacency[current_gear][i];
				next_dir = dir[next_gear]; 
				if(next_dir == 0){dir[next_gear] = -dir[current_gear]; Q[total++]=next_gear;}
				else if(next_dir == dir[current_gear]){blocked=true; break;}
			}
		}
		
		
		if(blocked) cout << "The input gear cannot move.\n";
		else if(dir[N-1]==0) cout << "The input gear is not connected to the output gear.\n";
		else{
			int d = gcd(R[N-1], R[0]);
			cout << dir[N-1]*R[0]/d << ":" << R[N-1]/d << "\n";
		}
	}
}
