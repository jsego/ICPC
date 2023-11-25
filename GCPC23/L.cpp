#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	while(cin >> s){
		vector<int> id_seq;
		vector<string> pieces;
		int current_id = 0;
		map<string, int> M;
		int level = 0;
		string current = "";
		for(size_t i=0; i<s.size(); ++i){
			if(s[i]=='('){
				current += "(";
				++level;
			}
			else{ // s[i] == ')'
				current += ")";
				--level;
			}
			// Cuts can only exist in level==0
			if(level==0){
				auto it = M.find(current);
				if(it == M.end()){
					M[current] = current_id;
					id_seq.push_back(current_id);
					++current_id;
				}
				else{
					id_seq.push_back(it->second);
				}
				pieces.push_back(current);
				current = "";
			}
		}
		if(current_id < 2){cout << "no\n"; continue;}
		int offset = 0;
		for(size_t i=1; i<id_seq.size(); ++i){
			if(id_seq[i] != id_seq[0]){offset=i; break;}
		}
		for(size_t i=0; i<pieces.size(); ++i){
			cout << pieces[(i+offset)%pieces.size()];
		}
		cout << "\n";
	}
}
