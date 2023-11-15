#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	while(cin >> s){
		map<char,int> m;
		
		for(const auto& c : s){
			auto it = m.find(c);
			if(it == m.end()) m[c] = 1;
			else (it->second)++;
		}
		
		vector<int> vec;
		for(map<char,int>::iterator it = m.begin(); it != m.end(); ++it){
			vec.push_back(it->second);
		}
		sort(vec.begin(), vec.end());
		
		int edits = 0;
		for(size_t i = 0; i+2 < vec.size(); i++){
			edits += vec[i];
		}
		cout << edits << "\n";
	}
}

