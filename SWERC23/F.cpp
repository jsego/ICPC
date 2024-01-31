#include <bits/stdc++.h>

using namespace std;

string NAMES[100001];
pair<int,int> RES[100001];

int main(){
	int N, P, E, total;
	while(cin >> N){
		int totalE, mini, maxi;
		for(int i=0; i<N; ++i){
			totalE = 0;
			maxi = -1;
			mini = 200;
			cin >> NAMES[i] >> P;
			for(int j=0; j<6; ++j){
				cin >> E; totalE += E;
				mini = min(mini, E);
				maxi = max(maxi, E);
			}
			totalE -= (maxi+mini);
			total = P*10 + totalE;
			RES[i] = make_pair(total, -i);
		}
		sort(RES, RES+N);
		int firstval = RES[N-1].first, secondval = -1;
		for(int i = N-1, j=0; j<1000 && i>=0; --i, ++j){
			if(RES[i].first < secondval) break;
			else if(secondval==-1 && RES[i].first < firstval && i<N-3) break;
			else if(RES[i].first < firstval) 
				secondval = RES[i].first;
			//cout << firstval << " " << secondval << endl;
			cout << NAMES[-RES[i].second] << " " << RES[i].first << '\n';
		} //cout << endl;
		
	}
}
