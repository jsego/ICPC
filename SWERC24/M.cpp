#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	while(cin >> s){
		for(size_t i=0; i<s.size(); ++i){
			cout << ".-";
			if(s[i] == 'O') cout << ".-";
		}
		cout << '\n';
	}
}
