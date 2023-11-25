#include <bits/stdc++.h>

using namespace std;

void recur(const string& s, size_t pos, string current){
	if(pos == s.size()){
		cout << current << "\n";
		return;
	}
	if(s[pos] != 's'){
		recur(s, pos+1, current+string(1, s[pos]));
		return;
	}
	// s[pos] == 's'
	if(((pos+1) < s.size()) && s[pos+1]=='s'){ // two adjacent 's'
		recur(s, pos+2, current+"B");
	}
	recur(s, pos+1, current+"s");
}

int main(){
	string s;
	while(cin >> s){
		std::transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c){ return std::tolower(c); });
		recur(s, 0, "");
	}
}
