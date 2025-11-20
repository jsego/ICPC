#include <bits/stdc++.h>

#define SQ(a) ((a)*(a))

using namespace std;

int N, K;
pair<long long, int> A[5001]; // sorted by d_i
long long res[5001];
long long current_res[5001];
long long best_penalty;
int optimal[5001][21]; // use memoization for optimal next step

void solve(int pos, int last_pos, int k, long long accum_penalty){
	if(accum_penalty > best_penalty) return;
	if(pos < 0){
		if(accum_penalty < best_penalty){
			for(int i=0; i<N; ++i){
				res[i] = current_res[i];
			}
			best_penalty = accum_penalty;
		}
		return;
	}
	
	// if optimal next step is know, do not apply recursivity
	if(...){
		...
		return;
	}
	
	// Otherwise, do recursion
	// A. do not deliver this day
	current_res[A[pos].second] = A[last_pos].first;
	solve(pos-1, last_pos, k, accum_penalty+SQ(A[pos].first-A[last_pos].first));
	
	// B. deliver this day
	if(k > 0){
		current_res[A[pos].second] = A[pos].first;
		solve(pos-1, pos, k-1, accum_penalty);
	}
} 

int main(){
	while(cin >> N >> K){
		for(int i=0; i<N; ++i){
			cin >> A[i].first; 
			A[i].second = i;
		}
		sort(A, A+N);
		// set trivial gifting day 
		for(int i=0; i<N; ++i) res[i] = current_res[i] = A[N-1].first;
		// compute trivial penalty
		best_penalty = 0;
		for(int i=0; i<N; ++i){
			best_penalty += SQ(A[N-1].first - A[i].first);
		}
		
		// compute solution	
		solve(N-2, N-1, K-1, 0);
		
		for(int i=0; i<N; ++i){
			cout << (i?" ":"") << res[i];
		}
		cout << '\n';
	}
}
