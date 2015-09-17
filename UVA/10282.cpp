/*
*  Javier Segovia
*  Accepted in 0.784
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	string a,b,s;
	map<string,string> M;
	map<string,string>::iterator it;
	while (getline(cin,s) && (int)s.LE>0) {
		size_t pos = s.find(' ');
		a = s.substr(0,pos);
		b = s.substr(pos+1);
		M[b] = a;
	}
	while (getline(cin,s)) {
		it = M.find(s);
		if (it!=M.end()) {
			cout<<it->second<<endl;
		}
		else {
			cout<<"eh"<<endl;
		}

	}
}