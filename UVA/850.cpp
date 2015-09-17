/*
*  Javier Segovia
*  Accepted in 0.016
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
string lines[102];
char T[300];

bool check(string &s){
	string ac="the quick brown fox jumps over the lazy dog";
	if(s.LE != ac.LE) return false;
	for(int i=(int)'a';i<=(int)'z';i++) T[i] = '.';
	//cout<<"S: "<<s<<endl;
	for (int i=0; i<(int)ac.LE; i++) { //cout<<"I: "<<i<<endl;
		if(s[i]==' '){ if(ac[i]!=' ') return false;}
		else if (T[(int)s[i]]=='.') {
			T[(int)s[i]]=ac[i];
		}
		else {
			if(T[(int)s[i]] != ac[i]) return false;
		}
	}
	return true;
}

int main(){
	int kases; cin>>kases; bool first=true;
	string s;
	getline(cin,s); 
	getline(cin,s); 
	
	while (kases--) { 
		if(first) first = false; 
		else cout<<endl;
		bool finish=false; 
		int total=0;
		while (getline(cin,lines[total++]) && lines[total-1].LE>0) { 
			if (!finish) {
				finish = check(lines[total-1]);
			}
		}
		if (finish) {
			for(int i=0;i+1<total;i++){
				for (int j=0; j<(int)lines[i].LE; j++) {
					if(lines[i][j]!=' ')cout<<T[(int)lines[i][j]];
					else cout<<" ";
				}cout<<endl;
			}
		}
		else {
			cout<<"No solution."<<endl;
		}
	}
}