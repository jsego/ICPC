#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

int main(){
	string s;
	bool last = false;
	while (getline(cin,s)) {
		if ((int)s.LE == 0) {
			cout<<endl; last = false; continue;
		}
		for (size_t i = 0; i<s.LE; i++) {
			if (s[i] == '(' || s[i] == ')' || s[i] == ' ') {
				continue;
			}
			if (s[i]>='A' && s[i]<='Z') {
				if (!last){
					s[i] = (s[i]-'A')+'a';
				}
			}
			else if(s[i]>='a' && s[i]<='z'){
				if (last) {
					s[i] = (s[i]-'a')+'A';
				}
			}
			last = (s[i]=='.' || s[i]=='?' || s[i]=='!');
		}
		cout << s<<endl;
	}
}