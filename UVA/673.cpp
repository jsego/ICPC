/*
*  Javier Segovia
*  Accepted in 0.256
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<list>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	int kases; cin>>kases;
	string s; getline(cin,s);
	while (kases--) {
		getline(cin,s);
		list<char> l;
		bool ok=true;
		for (int i=0; i<(int)s.LE; i++) { //cout<<"I: "<<i<<endl;
			if(s[i]=='('){l.PB(')');}
			else if(s[i]=='['){l.PB(']');}
			else{
				if( ((int)l.SL==0) || (l.back() != s[i])) {
					ok=false; break;
				}
				l.pop_back();
			}
		}//cout<<"SL: "<<l.SL<<endl;
		ok=(ok&&((int)l.SL==0));
		if(ok)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}