/*
* Javier Segovia
* Accepted in 0.036
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair

char REV[300];

bool isPal(string &s){
	for (size_t i=0; i<s.LE/2; i++) {
		if (s[i]!=s[s.LE-1-i]) {
			return false;
		}
	}
	return true;
}

bool isMir(string &s){
	size_t lim=s.LE>>1;
	for (size_t i=0; i<=s.LE/2; i++) {
		if (s[i]!=REV[(int)s[(int)s.LE-1-i]]) {
			return false;
		}
	}
	return true;
}

int main(){
	for(int i=0;i<300;i++) REV[i]=0;
	REV[(int)'A']='A';
	REV[(int)'E']='3';
	REV[(int)'H']='H';
	REV[(int)'I']='I';
	REV[(int)'J']='L';
	REV[(int)'L']='J';
	REV[(int)'M']='M';
	REV[(int)'O']='O';
	REV[(int)'S']='2';
	REV[(int)'T']='T';
	REV[(int)'U']='U';
	REV[(int)'V']='V';
	REV[(int)'W']='W';
	REV[(int)'X']='X';
	REV[(int)'Y']='Y';
	REV[(int)'Z']='5';
	REV[(int)'1']='1';
	REV[(int)'2']='S';
	REV[(int)'3']='E';
	REV[(int)'5']='Z';
	REV[(int)'8']='8';
	string s;
	while (cin>>s) {
		bool pal = isPal(s);
		bool mir = isMir(s);
		if(!pal && !mir) cout<<s<<" -- is not a palindrome."<<endl;
		else if(pal && !mir) cout<<s<<" -- is a regular palindrome."<<endl;
		else if(!pal && mir) cout<<s<<" -- is a mirrored string."<<endl;
		else cout<<s<<" -- is a mirrored palindrome."<<endl;
		cout << endl;
	}
}