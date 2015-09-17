/*
*  Javier Segovia
*  Accepted in 0.008
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
char A[300];
int main(){
	string mad="ertyuiop[]dfghjkl;'cvbnm,. ", ok="qwertyuiopasdfghjklzxcvbnm ";
	for (int i=0; i<(int)mad.LE; i++) {
		A[(int)mad[i]] = ok[i];
	}
	string s;
	while (getline(cin,s)) {
		for (int i=0; i<(int)s.LE; i++) {
			if(s[i]>='A' && s[i]<='Z') s[i]=(s[i]-'A')+'a';
			cout<<A[(int)s[i]];
		}cout<<endl;
	}
}