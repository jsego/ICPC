#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	while(cin >> N){
		map<string, int> M;
		string s;
		for(int i=0; i<N; ++i){
			cin >> s;
			auto it = M.find(s);
			if(it == M.end()) M[s] = 1;
			else ++(it->second);
		}
		int votes = 0;
		for(auto it = M.begin(); it != M.end(); ++it){
			if((it->second) > votes){
				s = (it->first);
				votes = it->second;
			}
		}
		cout << s << '\n';
	}
}
