/*
*  Javier Segovia
*  Accepted in 0.120
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

bool isCon(char c){
	return !(c=='a' || c=='A' || c=='e' || c=='E' || c=='I' || c=='i'
			 || c=='o' || c=='O' || c=='u' || c=='U');
}

bool isAlpha(char r){
	return (r>='a' && r<='z') || (r>='A' && r<='Z');
}

int main(){
	string s;
	while (getline(cin,s)) {
		bool alpha=false,con=false; char c='.';
		for (int i=0; i<(int)s.LE; i++) {
			alpha = isAlpha(s[i]);
			if (alpha) {
				con = isCon(s[i]);
				if (con) {
					c = s[i++];
					for (;i<(int)s.LE; i++) {
						alpha = isAlpha(s[i]);
						if (alpha) {
							cout<<s[i];
						}
						else break;
					}
					cout<<c<<"ay";
				}
				else {
					for (; i<(int)s.LE; i++) {
						alpha = isAlpha(s[i]);
						if (alpha) {
							cout<<s[i];
						}
						else break;
					}
					cout<<"ay";
				}
			}
			cout<<s[i];

		}cout<<endl;
	}
}