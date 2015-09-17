/*
*  Accepted in 0.012
*
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
struct Elem {
	char c; int rep;
	Elem(){c='-'; rep=0;}
	Elem(char a){c=a; rep=0;}
	void plus(){ ++rep;}
	bool operator<(const Elem &e) const{
		return (rep<e.rep || (rep==e.rep && c>e.c));
	}
	bool operator>(const Elem &e) const{
		return (rep>e.rep || (rep==e.rep && c<e.c));
	}
};

Elem A[300];

void process(string &s){
	for (int i=0; i<(int)s.LE; i++) {
		if(s[i]>='A' && s[i]<='Z') A[(int)s[i]].plus();
		else if(s[i]>='a' && s[i]<='z') A[(int)(s[i]-'a'+'A') ].plus();
	}
}

int main(){
	int kases; cin>>kases;
	string s; getline(cin,s);
	for (int i=(int)'A'; i<=(int)'Z'; i++) {
		A[i].c = (char)i;
	}
	while (kases--) {
		getline(cin,s);
		process(s);
	}
	sort(A+65,A+90);
	for (int i=90; i>=65; i--) {
		if (A[i].rep) {
			cout<<A[i].c<<" "<<A[i].rep<<endl;
		}
	}
	
}