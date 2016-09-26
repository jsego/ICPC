/*
*  Javier Segovia
*  Accepted in 0.180
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

int tam,cont=1;
map<string,int> M;
//vector<string> V;
bool isValid(string &s){
	if((int)s.LE > 5) return false;
	for (int i=1; i<(int)s.LE; i++) {
		if (s[i]<=s[i-1]) {
			return false;
		}
	}
	return true;
}

void recur(int p,char c,string &s){
	if (p==tam) {//if(tam==1) cout<<s<<endl;
		M[s] = cont++;
	}
	for (char a=c+1; a+p<'z'+tam; a++) {
		s[p] = a;
		recur(p+1,a,s);
	}
}

int main(){
	string s;
	for (tam=1; tam<6; tam++) {
		string s(tam,' '); char c='a'; c--; //cout<<"C: "<<c<<endl;
		recur(0,c,s);
	}
	while (cin>>s) {
		if(s=="a"){printf("1\n"); continue;}
		map<string,int>::iterator it = M.find(s);
		if (it==M.end()) {
			printf("0\n");
		}
		else {
			printf("%d\n",it->second);
		}/*

		bool valid = isValid(s);
		if (!valid) {
			printf("0\n"); continue;
		}
		int b=1,c=1,res=0;
		for (int i=(int)s.LE-1; i>=0; i--,c--) {
			res+=(s[i]-'a'+c)*b; b*=(26-c-1);
		}
		printf("%d\n",res);*/
	}
}