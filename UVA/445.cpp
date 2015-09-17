/*
* Javier Segovia
* Accepted in 0.008
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
int main(){
	string s,sol="";
	while (getline(cin,s)) {
		int val=0;
		sol="";
		for (int i=0; i<(int)s.LE; i++) {
			if(s[i]>='0' && s[i]<='9') val += s[i]-'0';
			else {
				if (s[i]=='!') {
					sol.PB('\n');
				}
				else {
					if (s[i]=='b') {
						sol += string(val,' ');
					}
					else {
						sol += string(val,s[i]);
					}
					val = 0;
				}
			}
		}
		cout<<sol<<endl;
	}
}