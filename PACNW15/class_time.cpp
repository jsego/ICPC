#include<bits/stdc++.h>

using namespace std;


int main(){
	int N;
	while(cin >> N){
		vector<pair<string,string>> v(N);
		for(int i=0; i < N; i++) cin >> v[i].second >> v[i].first;
		sort(v.begin(), v.end());
		
		for(int i=0; i < N; i++)
			cout << v[i].second << " " << v[i].first << "\n";
	}
}

